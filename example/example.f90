program example_in_f
    use ciaaw
    implicit none

    character(len=8) :: s
    
    ! ASAW = Abridged Standard Atomic Weight
    ! SAW  = Standard Atomic Weight
    ! ICE  = Isotopic Composition of the Element
    ! U    = Uncertainty

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW ##########'
    print '(A10, F10.5)', 'ASAW   = ', get_saw("H", abridged=.true.)
    print '(A10, F10.5)', 'U ASAW = ', get_saw("H", uncertainty=.true.)
    print '(A10, F10.5)', 'SAW    = ', get_saw("H", abridged = .false.)
    print '(A10, F10.5)', 'U SAW =  ', get_saw("H", abridged = .false., uncertainty = .true.)
    
    print '(A)', '########### CIAAW ICE ##########'
    print '(A, I3)',        'N ICE H   = ', get_nice("H")
    print '(A12, F12.6)',   'ICE H 1   = ', get_ice("H", A=1)
    print '(A12, ES23.16)', 'U ICE H 1 = ', get_ice("H", A=1, uncertainty=.true.)
    print '(A12, F12.6)',   'ICE H 2   = ', get_ice("H", A=2)
    print '(A12, ES23.16)', 'U ICE H 2 = ', get_ice("H", A=2, uncertainty=.true.)

end program
