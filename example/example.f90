program example_in_f
    use ciaaw
    implicit none

    character(len=8) :: s
    
    ! ASAW = Abridged Standard Atomic Weight
    ! SAW  = Standard Atomic Weight
    ! ICE  = Isotopic Composition of the Element
    ! NAW  = Nuclide Atomic Weight
    ! U    = Uncertainty

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW ##########'
    print '(A10, F10.5)', 'ASAW H   = ', get_saw("H", abridged=.true.)
    print '(A10, F10.5)', 'U ASAW H = ', get_saw("H", uncertainty=.true.)
    print '(A10, F10.5)', 'SAW H    = ', get_saw("H", abridged = .false.)
    print '(A10, F10.5)', 'U SAW H  =  ', get_saw("H", abridged = .false., uncertainty = .true.)
    print '(A10, F10.5)', 'ASAW T   = ', get_saw("Tc", abridged=.true.)
    
    print '(A)', '########### CIAAW ICE ##########'
    print '(A, I3)',        'N ICE H    = ', get_nice("H")
    print '(A, F12.6)',   'ICE H 1    = ', get_ice("H", A=1)
    print '(A, ES23.16)', 'U ICE H 1  = ', get_ice("H", A=1, uncertainty=.true.)
    print '(A, F12.6)',   'ICE H 2    = ', get_ice("H", A=2)
    print '(A, ES23.16)', 'U ICE H 2  = ', get_ice("H", A=2, uncertainty=.true.)
    print '(A, I3)',        'N ICE Tc   = ', get_nice("Tc")
    print '(A, I3)',        'N ICE C    = ', get_nice("C")
    
    print '(A)', '########### CIAAW NAW ##########'
    print '(A, ES23.16)',   'NAW H 2     = ', get_naw("H", A=2)
    print '(A, ES23.16)',   'U NAW H 2   = ', get_naw("H", A=2, uncertainty=.true.)
    print '(A, I3)',          'N NAW Tc    = ', get_nnaw("Tc")

end program
