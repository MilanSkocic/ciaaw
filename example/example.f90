program example_in_f
    use ciaaw
    implicit none

    character(len=8) :: s

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW - get by atomic number z ##########'
    print '(A, F10.5)', 'Abridged Standard Atomic Weight: ', get_asaw(1)
    print '(A, F10.5)', 'Uncertainty for Abridged Standard Atomic Weight: ', get_asaw_u(1)
    
    print '(A)', '########### CIAAW SAW - get by symbol ##########'
    s = "He"
    print '(A, F10.5)', 'Abridged Standard Atomic Weight: ', get_asaw_by_symbol(s)

end program
