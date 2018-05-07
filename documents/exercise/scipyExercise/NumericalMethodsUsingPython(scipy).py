# http://www.southampton.ac.uk/~fangohr/teaching/python/book/html/


# Numerical Methods using Python (scipy)
# http://www.southampton.ac.uk/~fangohr/teaching/python/book/html/16-scipy.html






# https://www.southampton.ac.uk/~fangohr/teaching/python/book/html/16-scipy.html#Exercise:-integrate-a-function

from math import cos, exp, pi
from scipy.integrate import quad


# function we want to integrate
def f(x):
    return cos(2 * pi * x)


# call quad to integrate f from 0 to 1
res, err = quad(f, 0, 1)

print("The numerical result is {:f} (+- {:g})".format(res, err))



# https://www.southampton.ac.uk/~fangohr/teaching/python/book/html/16-scipy.html#Exercise:-plot-before-you-integrate

