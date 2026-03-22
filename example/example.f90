! EXAMPLE IN FORTRAN
program example_in_f
use ciaaw, only: saw, ice, naw, nice, nnaw, version
implicit none(type,external)
print *, "version ", version()

print '(A)', '########### CIAAW SAW ##########'
print '(A10, F10.5)', 'ASAW H   = ', saw("H", ab=.true.)
print '(A10, F10.5)', 'U ASAW H = ', saw("H", u=.true.)
print '(A10, F10.5)', 'SAW H    = ', saw("H", ab=.false.)
print '(A10, F10.5)', 'U SAW H  =  ', saw("H", ab=.false., u=.true.)
print '(A10, F10.5)', 'ASAW T   = ', saw("Tc", ab=.true.)

print '(A)', '########### CIAAW ICE ##########'
print '(A, I3)',      'N ICE H    = ', nice("H")
print '(A, F12.6)',   'ICE H 1    = ', ice("H", A=1)
print '(A, ES23.16)', 'U ICE H 1  = ', ice("H", A=1, u=.true.)
print '(A, F12.6)',   'ICE H 2    = ', ice("H", A=2)
print '(A, ES23.16)', 'U ICE H 2  = ', ice("H", A=2, u=.true.)
print '(A, I3)',      'N ICE Tc   = ', nice("Tc")
print '(A, I3)',      'N ICE C    = ', nice("C")

print '(A)', '########### CIAAW NAW ##########'
print '(A, ES23.16)', 'NAW H 2     = ', naw("H", A=2)
print '(A, ES23.16)', 'U NAW H 2   = ', naw("H", A=2, u=.true.)
print '(A, I3)',      'N NAW Tc    = ', nnaw("Tc")

end program example_in_f
