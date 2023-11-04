program example_in_f
    use ciaaw
    implicit none

    real(real64), parameter :: M_H = ciaaw_saw_H%saw

    print *, ciaaw_saw_H%z
    print *, ciaaw_saw_H%saw
    print *, ciaaw_saw_H%saw_u
    print *, ciaaw_saw_H%asaw
    print *, ciaaw_saw_H%asaw_u

end program