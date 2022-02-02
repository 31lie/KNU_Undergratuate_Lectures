
import numpy as np

def power_method(A, x, dis) :
    eigenV = 0;
    k = 1;
    while True:
        Ax = A @ x
        last_eigenV = eigenV;
        eigenV = abs(Ax).max();
        x = (1/eigenV) * Ax;
        #print(f"{k}번째 Iteration:\n x_k = {x}, Ax_k = {Ax}, Mu_k = {eigenV}\n")
        k += 1
        if abs(eigenV - last_eigenV) < dis:
            return eigenV

A = np.matrix([[6, 5], [1, 2]])
x = np.matrix([[0], [1]])

eigenV = power_method(A, x, 0.001)
print(f"dis = 0.001 일때, eigenValue = {eigenV}")
eigenV = power_method(A, x, 0.00001)
print(f"dis = 0.00001 일때, eigenValue = {eigenV}")
eigenV = power_method(A, x, 0.0000001)
print(f"dis = 0.0000001 일때, eigenValue = {eigenV}")
eigenV = power_method(A, x, 0.000000001)
print(f"dis = 0.0000001 일때, eigenValue = {eigenV}")
