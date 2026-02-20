program ciaawcli
    use iso_fortran_env, only: output_unit
    use M_CLI2, only: set_args, iget, lget, specified
    use M_CLI2, only: args=>unnamed, get_subcommand, set_mode
    use stdlib_optval
    use stdlib_codata, only: MOLAR_MASS_CONSTANT
    use ciaaw
    use ciaaw__pte, only: pt
    use ciaaw__common

    character(len=*), parameter :: name="ciaaw"
    character(len=:),allocatable, target  :: help_text(:)
    character(len=:),allocatable, target  :: version_text(:)

    integer :: i
    character(len=3) :: s

    version_text=[character(len=80) :: &
        'PROGRAM:      '//name//'                                              ', &
        'DESCRIPTION:  Command line interface for ciaaw.                       ', &
        'VERSION:      '//get_version()//'                                     ', &
        'AUTHOR:       M. Skocic                                               ', &
        'LICENSE:      MIT                                                     ', &
        '' ]

    help_text=[character(len=80) :: &
        'NAME                                                                  ', &
        '  '//name//' - Command line for ciaaw                                 ', &
        '                                                                      ', &
        'SYNOPSIS                                                              ', &
        '  '//name//' [OPTION...] [ELEMENT...]                                 ', &
        '                                                                      ', &
        'DESCRIPTION                                                           ', &
        '  '//name//' is a command line interface which provides the atomic    ', &
        '  weights, the isotopic compositions and the nuclides atomic weights. ', &
        '  If no element is provided the full periodic table is displayed.    ', &
        '                                                                      ', &
        'OPTIONS                                                               ', &
        '  --saw, -s        Get the standard atomic weight.                  ', &
        '  --ice, -i        Get the isotopic composition.                    ', &
        '  --naw, -n        Get the nuclide atomic weight.                   ', &
        '  --mu, -m         Get the molar masses in g/mol by multiplying the ', &
        '                   atomic weights by the molar mass contant Mu.', &
        '  --colnames, -c   Show the headers in the outputs.                 ', &
        '  --usage, -u      Show usage text and exit.                        ', &
        '  --help, -h       Show help text and exit.                         ', &
        '  --verbose, -V    Display additional information when available.   ', &
        '  --version, -v    Show version information and exit.               ', &
        '                                                                      ', &
        'NOTES                                                                 ', &
        '                                                                      ', &
        '  You may replace the default options from a file if your first       ', &
        '  options begin with @file.                                           ', &
        '  Initial options will then be read from the "response file"          ', &
        '  "file.rsp" in the current directory.                                ', &
        '                                                                      ', &
        '  If "file" does not exist or cannot be read, then an error occurs and', &
        '  the program stops. Each line of the file is prefixed with "options"', &
        '  and interpreted as a separate argument. The file itself may not'  , &
        '  contain @file arguments. That is, it is not processed recursively.', &
        '                                                                      ', &
        '  For more information on response files see                          '  , &
        '                                                                      ', &
        '    https://urbanjost.github.io/M_CLI2/set_args.3m_cli2.html'  , &
        '                                                                      ', &
        'EXAMPLE                                                               ', &
        '  Minimal example                                                     ', &
        '                                                                      ', &
        '      ciaaw                                                           ', &
        '      ciaaw H C B O Zr Nb --saw --ice --naw --colnames                ', &
        '      ciaaw H C B O Zr Nb -sinc                                       ', &
        '                                                                      ', &
        'SEE ALSO                                                              ', &
        '  ciaaw(3), codata(3)                                                 ', &
        '' ]
    
    call set_mode('strict')
    call set_mode('response_file')
    call set_args('--abridged:a --saw:s --ice:i --naw:n --mu:m --colnames:c', help_text, version_text) 
    if(size(args)<=0)then
        call print_periodic_table()
    else
        if(.not.any(specified(['s','i','n'])))then
            write(output_unit, '(A)') 'Specify at least one option -s or -i or -n. See --help.'
            stop
        end if
        do i=1, size(args)
            s = trim(args(i))
            call print(s, lget('s'), lget('i'), lget('n'), lget('c'), lget('m'))
        end do
    end if

contains

subroutine print_text(char_fp)
    ! Print text pointed by char_fp.
    character(len=:), pointer, intent(in) :: char_fp(:)
    integer :: i
    do i=1, size(char_fp), 1
        write (OUTPUT_UNIT, '(A)') char_fp(i)
    end do
end subroutine

subroutine print(s, saw, ice, naw, headers, mu)
    ! Print saw, ice and naw.
    character(len=*), intent(in) :: s
    logical, intent(in), optional :: saw
    logical, intent(in), optional :: ice
    logical, intent(in), optional :: naw
    logical, intent(in), optional :: headers
    logical, intent(in), optional :: mu

    real(dp) :: r, dr, cmu
    integer :: i,j,z
    character(len=15) :: s1, s2, s3, s4, s5
    logical :: h, saw2, ice2, naw2, mu2
   
    character(len=15) :: header(5)
    character(len=15) :: ice_headers(5)
    character(len=15) :: naw_headers(5)
    character(len=32) :: fmt

    h = optval(headers, .false.)
    saw2 = optval(saw, .true.)
    ice2 = optval(ice, .false.)
    naw2 = optval(naw, .false.)
    mu2 = optval(mu, .false.)
    
    header = [character(len=15) ::      'S', 'Z', 'A', 'M', 'dM']
    ice_headers = [character(len=15) :: 'S', 'Z', 'A', 'C', 'dC']
    naw_headers = [character(len=15) :: 'S', 'Z', 'A', 'M', 'dM']
    fmt = '(A5, A5, A5, A15, A15)'
    
    cmu = 1.0_dp
    if(mu2)then
        cmu = MOLAR_MASS_CONSTANT%value * 1000.0
    end if

    z = -1
    do i=1, size(pt)
        if(s == pt(i)%symbol)then
            z = i
            exit
        endif
    end do
    if(z>0)then 
        if(saw2) then
            if(h) write(output_unit, fmt) header
            write(s1, '(A)') pt(i)%symbol
            write(s2, '(I3)') pt(i)%z
            write(s3, '(A)') ''
            write(s4, '(F14.6)') pt(i)%saw%asaw * cmu
            write(s5, '(F14.6)') pt(i)%saw%asaw_u * cmu
            write(output_unit, fmt) &
                adjustl(s1), &
                adjustl(s2), &
                adjustl(s3), &
                adjustl(s4), &
                adjustl(s5)
        end if

        if(ice2)then
            if(h) write(output_unit, '(A5, A5, A5, A15, A15)') ice_headers
            do j=1, pt(i)%ice%n
                write(s1, '(A)') pt(i)%symbol
                write(s2, '(I3)') pt(i)%z
                write(s3, '(I3)') nint(pt(i)%ice%values(j,1))
                write(s4, '(F12.6)') pt(i)%ice%values(j,2)
                write(s5, '(ES12.5)') pt(i)%ice%values(j,3)
                write(output_unit, '(A5, A5, A5, A15, A15)') adjustl(s1), adjustl(s2), adjustl(s3), adjustl(s4), adjustl(s5)
            enddo
        end if
        
        if(naw2)then
            if(h) write(output_unit, '(A5, A5, A5, A15, A15)') naw_headers
            do j=1, pt(i)%naw%n
                write(s1, '(A)') pt(i)%symbol
                write(s2, '(I3)') pt(i)%z
                write(s3, '(I3)') nint(pt(i)%naw%values(j,1))
                write(s4, '(F12.6)') pt(i)%naw%values(j,2) * cmu
                write(s5, '(ES12.5)') pt(i)%naw%values(j,3) * cmu
                write(output_unit, '(A5, A5, A5, A15, A15)') adjustl(s1), adjustl(s2), adjustl(s3), adjustl(s4), adjustl(s5)
            enddo
        end if
    end if
end subroutine

subroutine print_all()
    integer :: i 
    do i=1, size(pt)
    write(output_unit, '(A5, 4X, I3, 4X, G14.6, ES14.2)') &
            pt(i)%symbol, &
            pt(i)%z, &
            pt(i)%saw%asaw, &
            pt(i)%saw%asaw_u
   end do
end subroutine



end program
