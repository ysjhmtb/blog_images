import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mat

Fs = 8000
f = 5
sample = 2000
x = np.arange(sample)
y = np.sin(2 * np.pi * f * x / Fs)
plt.style.use('dark_background')
plt.plot(x, y,linestyle="--", color="white", linewidth=4)
# plt.grid()

plt.xlabel('sample(n)')
plt.ylabel('voltage(V)')

fig = plt.gcf()
plt.show()
fig.savefig('sin_graph.PNG')

