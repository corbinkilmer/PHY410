from cpt import *
from math import *
import numpy as np


def f (p) :
    x = p[0]
    y = p[1]
    r = math.pow(x*x + y*y, 0.5)
    return -0.5*r*r + r*r*r*r/4

def df(p) :
    x = p[0]
    y = p[1]
    x = 4*x*y*y
    y = 4*x*x*y
    return np.array( [x,y] )


print " Minimization using Broyden-Fletcher-Goldfarb-Shanno Algorithm"
print " Find minimum of f(x,y) given an initial guess for x, y"
p = input(" Enter starting point coordinates x y: ")
gtol = input( " Enter desired accuracy: ")
f_min = 0.0
iterations = 0
res = scipy.optimize.fmin_bfgs(f=f, fprime=df,x0=p, gtol=gtol)
print res
