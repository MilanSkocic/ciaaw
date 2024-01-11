program example_in_f
    use ciaaw
    implicit none

    type(element_t) :: elmt

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW ##########'
    elmt = H
    print '(A, A)', 'Element: ', elmt%element
    print '(A, A)', 'Symbol: ', elmt%symbol
    print '(A, I3)', 'Z: ', elmt%z
    print '(A, F23.16)', 'standard atomic weight max: ', elmt%standard atomic weight_max
    print '(A, F23.16)', 'standard atomic weight min: ', elmt%standard atomic weight_min
    print '(A, F23.16)', 'standard atomic weight: ', elmt%standard atomic weight_min
    print '(A, F23.16)', 'standard atomic weight uncertainty: ', elmt%standard atomic weight_u
    print '(A, F23.16)', 'abredged standard atomic weight: ', elmt%astandard atomic weight
    print '(A, F23.16)', 'abredged standard atomic weight uncertainty: ', elmt%astandard atomic weight_u
    print '(A)', '' 
    elmt = F
    print '(A, A)', 'Element: ', elmt%element
    print '(A, A)', 'Symbol: ', elmt%symbol
    print '(A, I3)', 'Z: ', elmt%z
    print '(A, F23.16)', 'standard atomic weight max: ', elmt%standard atomic weight_max
    print '(A, F23.16)', 'standard atomic weight min: ', elmt%standard atomic weight_min
    print '(A, F23.16)', 'standard atomic weight: ', elmt%saw_min
    print '(A, F23.16)', 'standard atomic weight uncertainty: ', elmt%saw_u
    print '(A, F23.16)', 'abredged standard atomic weight: ', elmt%asaw
    print '(A, F23.16)', 'abredged standard atomic weight uncertainty: ', elmt%asaw_u

end program
