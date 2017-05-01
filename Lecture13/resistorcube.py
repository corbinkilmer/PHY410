from cpt import *
import numpy as np
import matplotlib.pyplot as plt

print "Resistor Cube with arbitrary resistors"
print " --------------------------------------"

v0 = 1.
r1 = 1.
r2 = r1
r3 = r1
r4 = r1
r5 = r1
r6 = r1
r7 = r1
r8 = r1
r9 = r1
r10 = r1
r11 = r1
r12 = r1

rx = np.linspace(0,20,100)

ry = []
#print rx
v = Matrix(6, 1)       # column vector with 3 rows
v[0][0] = v0
v[1][0] = v0
v[2][0] = v0
v[3][0] = v0
v[4][0] = v0
v[5][0] = v0
#print 'v = '
#print v 

R = Matrix(6, 6)       # 3x3 resistance matrix
R[0][0] = r1
R[0][1] = r1+r5+r11
R[0][2] = 0
R[0][3] = r11
R[0][4] = 0
R[0][5] = 0

R[1][0] = r1+r4+r10
R[1][1] = r1
R[1][2] = 0
R[1][3] = 0
R[1][4] = r10
R[1][5] = 0

R[2][0] = 0
R[2][1] = 0
R[2][2] = r2+r6+r12
R[2][3] = r2
R[2][4] = 0
R[2][5] = r12

R[3][0] = 0
R[3][1] = r11
R[3][2] = r2
R[3][3] = r2+r7+r11
R[3][4] = 0
R[3][5] = 0

R[4][0] = r10
R[4][1] = 0
R[4][2] = 0
R[4][3] = 0
R[4][4] = r3+r8+r10
R[4][5] = r3

R[5][0] = 0
R[5][1] = 0
R[5][2] = r12
R[5][3] = 0
R[5][4] = r3
R[5][5] = r3+r9+r12

for r in rx:
    R[0][0] = r
    R[0][1] = r+r5+r11
    R[1][0] = r+r4+r10
    R[1][1] = r
# the solve_Gauss_Jordan replaces R by R^-1 and v by i
# so save the original R and copy v into a vector i
    R_save = Matrix_copy(R)
    i = Matrix_copy(v)

    solve_Gauss_Jordan(R_save, i)
#print " Solution using Gauss-Jordan elimination"
#print " i = "
#print i

# find the other currents
#rint " i_a = i_1 - i_2 = " + str(i[0][0] - i[1][0])
#rint " i_v = i_1 + i_3 = " + str(i[0][0] + i[2][0])
#rint " i_x = i_1 - i_2 + i_3 = " + str(i[0][0] - i[1][0] + i[2][0])

    itot = float(i[0][0]+i[1][0]+i[2][0]+i[3][0]+i[4][0]+i[5][0])
    reff = v0/itot
    ry.append(reff)

y = array(ry)
plt.plot(rx, y)
plt.show()
#print y
# see whether LU decomposition gives the same answer
#i = Vector(v)
#solve_LU_decompose(R_save, i)
#print " Solution using LU Decompositon"
#print " i = "
#print i

