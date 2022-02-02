# 컴퓨터학부 심화컴퓨터전공
# 2020114658 이윤서

# 공학수학 Midterm Project 3 - Tank2 When step size is 0.1

import numpy as np
from matplotlib import pyplot as plt
import math

# 초기 조건
x0_t1, y0_t1 = 0, 150
x0_t2, y0_t2 = 0, 50

# step size
h = 0.1
x_end = 2


def f_sol_t1(x):
    return 120 * math.exp(-1/10 * x) + 30 * math.exp(-3/5 * x)


def f_sol_t2(x):
    return 80 * math.exp(-1/10 * x) - 30 * math.exp(-3/5 * x)


def f_t1(x, y):
    return -3/10 * y + 3/10 * f_sol_t2(x)


def f_t2(x, y):
    return 1/5 * f_sol_t1(x) - 2/5 * y


# for tank2

x_arr_t2 = np.arange(x0_t2, x_end+h, h)
y_arr_t2 = np.zeros(x_arr_t2.shape)
y_value_t2 = np.zeros(x_arr_t2.shape)
error_t2 = np.zeros(x_arr_t2.shape)

y_arr_t2[0] = y0_t2
for i, x in enumerate(x_arr_t2[:-1]):
    y_arr_t2[i+1] = y_arr_t2[i] + h * f_t2(x, y_arr_t2[i])
    y_value_t2[i] = f_sol_t2(x)
y_value_t2[-1] = f_sol_t2(x_arr_t2[-1])


for i, x in enumerate(x_arr_t2[:-1]):
    error_t2[i] = abs((y_value_t2[i] - y_arr_t2[i]) / y_value_t2[i]) * 100
error_t2[-1] = abs((y_value_t2[-1] - y_arr_t2[-1]) / y_value_t2[-1]) * 100

print(" Tank 2 for step size = 0.1\n")
print("    x \t\t    y(x) \t Euler approximation of y(x) \t True relative percentage error")
for i in range(0, len(x_arr_t2)):
    print("%f \t %f \t\t %f \t \t\t%f" % (x_arr_t2[i], y_value_t2[i], y_arr_t2[i], error_t2[i]))

# 근사치 그래프 그리기
plt.plot(x_arr_t2, y_arr_t2, 'r', label='Euler approximation')
plt.plot(x_arr_t2, y_value_t2, 'b', label='Real value')
plt.xlabel('t axis')
plt.ylabel('y axis')
plt.title('3 Graph for tank 2, step size = 0.1')
plt.legend(loc='lower right')
plt.show()
