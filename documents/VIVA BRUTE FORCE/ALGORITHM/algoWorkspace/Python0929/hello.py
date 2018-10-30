# DSP 33 page
# x(t) = A cos(omega * t + phi) = A cos(2 * pi * f * t + phi)

import numpy as np
import matplotlib.pyplot as plt


def getCos(A, omega, phi):
    '''
    x(t) = A cos(omega * t + phi) = A cos(2 * pi * f * t + phi)
    :param A: 진폭 amplitude
    :param omega: 각 주파수 radian frequency
    :param f: 주파수 frequency
    :param phi: 위상 phase
    :return:
    '''

    x = np.arange(0, omega + phi, 0.1)
    y = np.cos(x)
    plt.plot(x, y)
    plt.xlabel('x values from 0 to omega + phi')
    plt.ylabel('cos(x)')
    plt.legend(['cos(x)'])
    plt.show()


getCos(1, 2 * np.pi, 0)
getCos(1, 4 * np.pi, -2 * np.pi)
getCos(1, 4 * np.pi, 0)

