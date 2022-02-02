# 컴퓨터학부 심화컴퓨터전공
# 2020114658 이윤서

# 공학수학 Midterm Project 2-2

import numpy as np
from matplotlib import pyplot as plt
import math

x_arr = np.arange(0, 3, 0.02)
y_arr = np.zeros(x_arr.shape)

def f(x) :
    return 3/2 * ((x/3)**(1/4) - (x/3)**(7/4))


for i, x in enumerate(x_arr):
    y_arr[i] = f(x)

plt.plot(x_arr, y_arr, 'r')
plt.xlabel('x axis')
plt.ylabel('y axis')
plt.title('2-2 Graph')
plt.show()
