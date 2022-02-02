# 컴퓨터학부 심화컴퓨터전공
# 2020114658 이윤서

# 공학수학 Midterm Project 3 - Tank1 When step size is 0.2

import numpy as np
from matplotlib import pyplot as plt
import math

# 초기 조건
x0_t1, y0_t1 = 0, 150
x0_t2, y0_t2 = 0, 50

# step size
h = 0.2
x_end = 2


def f_sol_t1(x):
    return 120 * math.exp(-1/10 * x) + 30 * math.exp(-3/5 * x)


def f_sol_t2(x):
    return 80 * math.exp(-1/10 * x) - 30 * math.exp(-3/5 * x)


def f_t1(x, y):
    return -3/10 * y + 3/10 * f_sol_t2(x)


def f_t2(x, y):
    return 1/5 * f_sol_t1(x) - 2/5 * y


# for tank1

x_arr_t1 = np.arange(x0_t1, x_end+h, h)
y_arr_t1 = np.zeros(x_arr_t1.shape)
y_value_t1 = np.zeros(x_arr_t1.shape)
error_t1 = np.zeros(x_arr_t1.shape)

y_arr_t1[0] = y0_t1
for i, x in enumerate(x_arr_t1[:-1]):
    y_arr_t1[i+1] = y_arr_t1[i] + h * f_t1(x, y_arr_t1[i])
    y_value_t1[i] = f_sol_t1(x)
y_value_t1[-1] = f_sol_t1(x_arr_t1[-1])


for i, x in enumerate(x_arr_t1[:-1]):
    error_t1[i] = abs((y_value_t1[i] - y_arr_t1[i]) / y_value_t1[i]) * 100
error_t1[-1] = abs((y_value_t1[-1] - y_arr_t1[-1]) / y_value_t1[-1]) * 100

print(" Tank 1 for step size = 0.2\n")
print("    x \t\t    y(x) \t Euler approximation of y(x) \t True relative percentage error")
for i in range(0, len(x_arr_t1)):
    print("%f \t %f \t\t %f \t \t\t%f" % (x_arr_t1[i], y_value_t1[i], y_arr_t1[i], error_t1[i]))

# 근사치 그래프 그리기
plt.plot(x_arr_t1, y_arr_t1, 'r', label='Euler approximation')
plt.plot(x_arr_t1, y_value_t1, 'b', label='Real value')
plt.xlabel('t axis')
plt.ylabel('y axis')
plt.title('3 Graph for tank 1, step size = 0.2')
plt.legend(loc='upper right')
plt.show()
