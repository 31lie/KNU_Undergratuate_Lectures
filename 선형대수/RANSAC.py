import numpy as np
import matplotlib.pyplot as plt
import random
import math


def cal_inlier(datas, d1, d2, threshold) :
    
    # estimate the line
    m = (d1[1] - d2[1]) / (d1[0] - d2[0])
    # y = mx + b , b = y - mx
    b = d1[1] - m * d1[0]
    
    inlier = list()
    
    # define whether data is inlier or outlier
    for data in datas :
        # calculate d
        d = abs(m*data[0] + b - data[1]) / math.sqrt(1+m**2)
        if d <= threshold:
            inlier.append(data)

    return len(inlier), m, b

def RANSAC(data, threshold) :
    
    best_m = 0
    best_b = 0
    max_inlier = 0

    for i in range(500):
        # Select two points Randomly
        first_data = data[random.randrange(0, 99)]
        second_data = data[random.randrange(0, 99)]

        if (first_data != second_data) :
            num_inlier, m, b = cal_inlier(data, first_data, second_data, threshold)

            if num_inlier > max_inlier:
                max_inlier = num_inlier
                best_b = b
                best_m = m
            
    return best_m, best_b


def total_least_square(x, y):
    
    m = np.sum(x*y) / np.sum(x*x)
    b = np.mean(y) - m * np.mean(x)
    return m, b
    


# read data and save
dataFile = open("./data.txt", "r")
data = dataFile.readlines()
x_list = list()
y_list = list()
for i in range(len(data)):
    data[i] = data[i].strip()
    data[i] = data[i].split()
    data[i][0] = float(data[i][0])
    data[i][1] = float(data[i][1])
    x_list.append(data[i][0])
    y_list.append(data[i][1])
    
# set threshold 0.5
threshold = 0.5
est_m, est_b = RANSAC(data, threshold)
est_y = [est_m * x + est_b for x in x_list]

plt.plot(x_list, est_y, 'b-', label=f'y={est_m}x+{est_b}')
plt.title(f'threshold {threshold}')
plt.scatter(x_list, y_list)

lss_m, lss_b = total_least_square(np.array(x_list), np.array(y_list))
plt.plot(x_list, [lss_m * x + lss_b for x in x_list], label = 'by lss', color='red')
plt.legend(bbox_to_anchor=(0.6, 0.7), prop={'size': 6})
plt.show()


