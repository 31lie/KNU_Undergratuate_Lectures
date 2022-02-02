import numpy as np
from numpy.linalg import eig

def inverse_power_method(A, x, a, dis) :
    eigenV = 0
    k = 1
    I = np.identity(n=3, dtype=np.int8)
    
    while True:
        y = np.linalg.solve(A - a*I, x)
        mu = abs(y).max()
        last_eigenV = eigenV
        eigenV = a + (1/mu)
        x = (1/mu) * y
        #print(f"{k}번째 Iteration:\n x_k = {x}, y_k = {y}, mu_k = {mu}, v_k = {eigenV}\n")
        k += 1
        if abs(eigenV - last_eigenV) < dis :
            return eigenV


A = np.matrix([[10, -8, -4], [-8, 13, 4], [-4, 5, 4]])
x = np.matrix([[1], [1], [1]])
        
print("the smallest eigenvalues (1.9)\n")
eigenValue = inverse_power_method(A, x, 1.9, 0.001)
print(f"dis = 0.001 일때, eigenValue = {eigenValue}")
eigenValue = inverse_power_method(A, x, 1.9, 0.00001)
print(f"dis = 0.00001 일때, eigenValue = {eigenValue}")
eigenValue = inverse_power_method(A, x, 1.9, 0.0000001)
print(f"dis = 0.0000001 일때, eigenValue = {eigenValue}")

print("\n\nSecond smallest eigenvalues (3.3)")
eigenValue = inverse_power_method(A, x, 3.3, 0.001)
print(f"dis = 0.001 일때, eigenValue = {eigenValue}")
eigenValue = inverse_power_method(A, x, 3.3, 0.00001)
print(f"dis = 0.00001 일때, eigenValue = {eigenValue}")
eigenValue = inverse_power_method(A, x, 3.3, 0.0000001)
print(f"dis = 0.0000001 일때, eigenValue = {eigenValue}")
