program example_in_f
    use ciaaw
    implicit none

    character(len=8) :: s

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW ##########'
    print '(A, F10.5)', 'Abridged Standard Atomic Weight: ', get_saw("H", abridged=.true.)
    print '(A, F10.5)', 'Uncertainty for Abridged Standard Atomic Weight: ', get_saw("H", uncertainty=.true.)
    print '(A, F10.5)', 'Standard Atomic Weight: ', get_saw("H", abridged = .false.)
    print '(A, F10.5)', 'Uncertainty for Standard Atomic Weight: ', get_saw("H", abridged = .false., uncertainty = .true.)

end program
