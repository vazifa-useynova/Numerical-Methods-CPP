#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

/**
 * LinearSolver Class
 * * Purpose: Implements fundamental numerical algorithms for scientific computing.
 * This implementation focuses on the transition from Python's high-level abstractions
 * to C++ manual optimization and efficient memory handling.
 */
class LinearSolver {
public:
    /**
     * Solves a system of linear equations (Ax = b) using Gaussian Elimination 
     * with partial pivoting to ensure numerical stability.
     * * @param matrix The coefficient matrix A (passed by reference to avoid expensive copying).
     * @param b The result vector (passed by reference, will be modified during calculation).
     * @return A vector containing the values of the unknowns.
     */
    static std::vector<double> solveGauss(std::vector<std::vector<double>>& matrix, std::vector<double>& b) {
        int n = matrix.size();

        // --- Forward Elimination Phase ---
        for (int i = 0; i < n; i++) {
            
            // Partial Pivoting: Find the row with the largest absolute value in the current column.
            // This minimizes rounding errors, which is critical for industrial inverse problems.
            int maxRow = i;
            for (int k = i + 1; k < n; k++) {
                if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
                    maxRow = k;
                }
            }
            
            // Swap current row with the pivot row
            std::swap(matrix[i], matrix[maxRow]);
            std::swap(b[i], b[maxRow]);

            // Eliminate entries below the pivot
            for (int k = i + 1; k < n; k++) {
                // Calculate factor for row reduction
                double factor = -matrix[k][i] / matrix[i][i];
                
                for (int j = i; j < n; j++) {
                    if (i == j) {
                        matrix[k][j] = 0; // Explicitly set to zero to avoid precision residue
                    } else {
                        matrix[k][j] += factor * matrix[i][j];
                    }
                }
                b[k] += factor * b[i];
            }
        }

        // --- Backward Substitution Phase ---
        std::vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) {
            x[i] = b[i] / matrix[i][i];
            // Update the remaining result vector based on the found value
            for (int k = i - 1; k >= 0; k--) {
                b[k] -= matrix[k][i] * x[i];
            }
        }
        return x;
    }
};

int main() {
    // Demonstration with a sample system representing a typical numerical problem
    std::vector<std::vector<double>> A = {{3, 2, -4}, {2, 3, 3}, {5, -3, 1}};
    std::vector<double> b = {3, 15, 14};

    std::cout << "Starting Gaussian Elimination Solver..." << std::endl;

    try {
        std::vector<double> result = LinearSolver::solveGauss(A, b);

        std::cout << "Computed Solution Vector:" << std::endl;
        for (int i = 0; i < result.size(); i++) {
            std::cout << "x[" << i << "] = " << std::fixed << std::setprecision(6) << result[i] << std::endl;
        }
    } catch (...) {
        std::cerr << "An error occurred during numerical computation." << std::endl;
    }

    return 0;
}
