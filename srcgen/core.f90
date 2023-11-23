module core
    ! Common parameters.
    use iso_fortran_env
    implicit none
    integer, parameter :: LENGTH_ELEMENT = 24
    integer, parameter :: LENGTH_SYMBOL = 8
    
    integer(int32), parameter :: LINE_LENGTH = 256 !! Length of line.

    ! Indexes for the table columns
    integer(int32), parameter :: cix_element(2) = [1, 20]
    integer(int32), parameter :: cix_symbol(2) = [21, 27]
    integer(int32), parameter :: cix_z(2) = [28, 32]
    integer(int32), parameter :: cix_saw_min(2) = [33, 52]
    integer(int32), parameter :: cix_saw_max(2) = [53, 72]
    integer(int32), parameter :: cix_saw(2) = [73, 92]
    integer(int32), parameter :: cix_saw_u(2) = [93, 112]
    integer(int32), parameter :: cix_footnote(2) = [113, 122]
    integer(int32), parameter :: cix_asaw(2) = [123, 132]
    integer(int32), parameter :: cix_asaw_u(2) = [133, 142]
    integer(int32), parameter :: cix_compute(2) = [143, 152]
    
    ! Properties of the file for the ciaaw saw data.
    type :: ciaaw_saw_file_props
        integer(int32) :: n !! Number of lines.
        integer(int32) :: index_header_end !! Number of lines for the header.
        character(len=18) :: fpath !! Filepath to the raw codata constants.
        character(len=4) :: year !! Year of release of the codata constants.
    end type

end module