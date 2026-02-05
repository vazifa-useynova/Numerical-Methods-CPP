# Numerical Methods & Scientific Computing (C++)

This repository serves as a transition from my research-based Python implementations to high-performance C++. It focuses on solving linear systems and optimization problems commonly found in **Industrial Inverse Problems** and **Computer Graphics**.

## 🚀 Objectives
* **Computational Efficiency:** Leveraging C++ memory management (passing by reference, minimizing heap allocations) to optimize execution speed.
* **Numerical Stability:** Implementing algorithms like Gaussian Elimination with **Partial Pivoting** to handle potentially ill-conditioned matrices.
* **Graphics Lab Readiness:** Building a foundation in the core language used by the *Graphics & Geometric Computing Laboratory (GCL)*.

## 🛠 Currently Implemented
### 1. Linear System Solvers
* **Gaussian Elimination:** A robust solver for $Ax = b$ systems. 
    * *Key Feature:* Includes row swapping (pivoting) to maintain precision even with small divisors.
    * *Complexity:* $O(n^3)$.

## 📈 Future Roadmap
- [ ] Implement Sparse Matrix storage for large-scale geometric data.
- [ ] Add Gradient Descent and Newton's Method for non-linear optimization.
- [ ] Integrate **Eigen** or **Armadillo** libraries to compare custom performance vs. industry-standard libraries.

## 📄 Research Context
The logic in these implementations is based on my previous work with **Tikhonov Regularization** and **MSE minimization** in industrial sensor data processing.
