# compute_pi.py
import numpy as np
import matplotlib.pyplot as plt

N = 1000
count = 0
x = np.zeros([N, 1])
y = np.zeros([N, 1])
z = np.zeros([N, 1])
r = np.zeros([N, 1])

x = 2 * np.random.random((N, 1)) - 1
y = 2 * np.random.random((N, 1)) - 1
z = np.power(x, 2) + np.power(y, 2)
r = np.sqrt(z)

for i in range(N):
    if r[i] < 1:
        count = count + 1
        plt.plot(x[i], y[i], 'k*', markersize=5)
    else:
        plt.plot(x[i], y[i], 'ko', markersize=5)

t = np.linspace(0, 2 * np.pi, 100)
plt.plot(np.cos(t), np.sin(t), 'k', linewidth=2)
plt.axis('image')
plt.show()
Pi = 4 * count / N
print('Pi = %f' % Pi)
