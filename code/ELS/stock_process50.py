# stock_process50.py
import numpy as np
import matplotlib.pyplot as plt

N = 365
S = np.zeros([N, 1])
S[0] = 100
vol = 0.079
r = 0.021
T = 1
dt = T / N
t = np.linspace(0, T, N)
plt.xlabel('Time')
plt.ylabel('Stock Process')

for k in range(0, 50):
    z = np.random.normal(0, 1, N)
    for i in range(N - 1):
        S[i + 1, 0] = S[i, 0] * np.exp((r - 0.5 * vol ** 2) * dt + vol * z[i] * np.sqrt(dt))
    plt.plot(t[:], S[:], 'k-', linewidth=0.3)
plt.show()
