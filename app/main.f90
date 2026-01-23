program ciaawcli
    use iso_fortran_env, only: output_unit
    use M_CLI2, only: set_args, iget, lget
    use M_CLI2, only: args=>unnamed
    use regex_module, only: REGEX, parse_pattern, regex_pattern
    use stdlib_optval
    use ciaaw
    
    character(len=*), parameter :: name="ciaaw"
    character(len=:),allocatable, target  :: help_text(:) 
    character(len=:),allocatable, target  :: version_text(:)
    character(len=:), pointer :: char_fp(:)
    
    integer :: i
    
    nullify(char_fp)
    
    version_text=[character(len=80) :: &
        'PROGRAM:      '//name//'                         ', &
        'DESCRIPTION:  Command line interface for ciaaw  ', &
        'VERSION:      '//get_version()//'                ', &
        'AUTHOR:       M. Skocic                          ', &
        'LICENSE:      MIT                                ', &
        '' ]
    
    help_text=[character(len=80) :: &
        'NAME                                                            ', &
        '  '//name//' - Command line for ciaaw                          ', &
        '                                                                ', &
        'SYNOPSIS                                                        ', &
        '  '//name//' [OPTIONS] [REGEX_PATTERN ... ]                           ', &
        '                                                                ', &
        'DESCRIPTION                                                     ', &
        '  '//name//' is a command line interface ...', &
        '  constants.                                                    ', &
        '                                                                ', &
        'OPTIONS                                                         ', &
        '  o --usage          Show usage text and exit.                          ', & 
        '  o --help           Show help text and exit.                          ', & 
        '  o --verbose        Display additional information when available.   ', &
        '  o --version        Show version information and exit.               ', &
        '                                                                ', &
        'EXAMPLE                                                         ', &
        '  Minimal example                                               ', &
        '                                                                ', &
        '     ciaaw                                                     ', &
        '                                                                ', &
        'SEE ALSO                                                         ', &
        '  ciaaw(3), codata(3)                                                     ', &
        '' ]
        
    char_fp => help_text
    call print_text(char_fp)

contains


subroutine print_text(char_fp)
    character(len=:), pointer, intent(in) :: char_fp(:)
    integer :: i
    do i=1, size(char_fp), 1
        write (OUTPUT_UNIT, '(A)') char_fp(i)
    end do
end subroutine



end program
