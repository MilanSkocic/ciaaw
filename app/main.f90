program ciaawcli
    use iso_fortran_env, only: output_unit
    use M_CLI2, only: set_args, iget, lget
    use M_CLI2, only: args=>unnamed, get_subcommand, set_mode
    use regex_module, only: REGEX, parse_pattern, regex_pattern
    use stdlib_optval
    use ciaaw
    use ciaaw__pte, only: pt
    use ciaaw__common

    character(len=*), parameter :: name="ciaaw"
    character(len=:),allocatable, target  :: help_text(:)
    character(len=:),allocatable, target  :: version_text(:)

    integer :: i
    character(len=3) :: s

    version_text=[character(len=80) :: &
        'PROGRAM:      '//name//'                         ', &
        'DESCRIPTION:  Command line interface for ciaaw  ', &
        'VERSION:      '//get_version()//'                ', &
        'AUTHOR:       M. Skocic                          ', &
        'LICENSE:      MIT                                ', &
        '' ]

    help_text=[character(len=80) :: &
        'NAME                                                            ', &
        '  '//name//' - Command line for ciaaw                           ', &
        '                                                                ', &
        'SYNOPSIS                                                        ', &
        '  '//name//' [OPTIONS] [ELEMENTS ...]                ', &
        '                                                                ', &
        'DESCRIPTION                                                     ', &
        '  '//name//' is a command line interface for printing the atomic ', &
        '  weights, the isotopic compositions and the nuclides atomic weights.', &
        '                                                                ', &
        '  If no elements is provided the full periodic table is displayed.', &
        '                                                                ', &
        'OPTIONS                                                         ', &
        '  o --saw, -s        Get the standard atomic weight.            ', &
        '  o --ice, -i        Get the isotopic composition. ', &
        '  o --naw, -n        Get the nuclide atomic weight.             ', &
        '  o --colnames, -c   Show the headers in the outputs.           ', &
        '  o --usage, -u      Show usage text and exit.                  ', &
        '  o --help, -h       Show help text and exit.                   ', &
        '  o --verbose, -V    Display additional information when available.   ', &
        '  o --version, -v    Show version information and exit.               ', &
        '                                                                ', &
        'EXAMPLE                                                         ', &
        '  Minimal example                                               ', &
        '                                                                ', &
        '      ciaaw                                                     ', &
        '      ciaaw H C B O Zr Nb --saw --ice --naw --colnames           ', &
        '      ciaaw H C B O Zr Nb -sinc                                  ', &
        '                                                                ', &
        'SEE ALSO                                                         ', &
        '  ciaaw(3), codata(3)                                                     ', &
        '' ]
    
    call set_mode('strict')
    call set_args('--abridged:a --saw:s --ice:i --naw:n --colnames:c', help_text, version_text) 
    if(size(args)<=0)then
        call print_periodic_table()
    else
        do i=1, size(args)
            s = trim(args(i))
            call print(s, lget('s'), lget('i'), lget('n'), lget('c'))
        end do
    end if

contains

subroutine print_text(char_fp)
    character(len=:), pointer, intent(in) :: char_fp(:)
    integer :: i
    do i=1, size(char_fp), 1
        write (OUTPUT_UNIT, '(A)') char_fp(i)
    end do
end subroutine

subroutine print(s, saw, ice, naw, headers)
    character(len=*), intent(in) :: s
    logical, intent(in), optional :: saw
    logical, intent(in), optional :: ice
    logical, intent(in), optional :: naw
    logical, intent(in), optional :: headers

    real(dp) :: r, dr
    integer :: i,j,z
    character(len=15) :: s1, s2, s3, s4, s5
    logical :: h, saw2, ice2, naw2
   
    character(len=15) :: header(4)
    character(len=15) :: ice_headers(5)
    character(len=15) :: naw_headers(5)

    h = optval(headers, .false.)
    saw2 = optval(saw, .true.)
    ice2 = optval(ice, .false.)
    naw2 = optval(naw, .false.)
    
    header = [character(len=15) :: "S", "Z", "M", "dM"]
    ice_headers = [character(len=15) :: "S", "Z", "A", "C", "dC"]
    naw_headers = [character(len=15) :: "S", "Z", "A", "M", "dM"]

    z = -1
    do i=1, size(pt)
        if(s == pt(i)%symbol)then
            z = i
            exit
        endif
    end do
    if(z>0)then 
        if(saw2) then
            if(h) write(output_unit, '(4A15)') header
            write(s1, '(A)') pt(i)%symbol
            write(s2, '(I3)') pt(i)%z
            write(s3, '(F14.6)') pt(i)%saw%asaw
            write(s4, '(F14.6)') pt(i)%saw%asaw_u
            write(output_unit, '(4A15)') &
                adjustl(s1), &
                adjustl(s2), &
                adjustl(s3), &
                adjustl(s4)
        end if

        if(ice2)then
            if(h) write(output_unit, "(5A15)") ice_headers
            do j=1, pt(i)%ice%n
                write(s1, '(A)') pt(i)%symbol
                write(s2, '(I3)') pt(i)%z
                write(s3, "(I3)") nint(pt(i)%ice%values(j,1))
                write(s4, "(F12.6)") pt(i)%ice%values(j,2)
                write(s5, "(ES12.5)") pt(i)%ice%values(j,3)
                write(output_unit, "(5A15)") adjustl(s1), adjustl(s2), adjustl(s3), adjustl(s4), adjustl(s5)
            enddo
        end if
        
        if(naw2)then
            if(h) write(output_unit, "(5A15)") naw_headers
            do j=1, pt(i)%naw%n
                write(s1, '(A)') pt(i)%symbol
                write(s2, '(I3)') pt(i)%z
                write(s3, "(I3)") nint(pt(i)%naw%values(j,1))
                write(s4, "(F12.6)") pt(i)%naw%values(j,2)
                write(s5, "(ES12.5)") pt(i)%naw%values(j,3)
                write(output_unit, "(5A15)") adjustl(s1), adjustl(s2), adjustl(s3), adjustl(s4), adjustl(s5)
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
