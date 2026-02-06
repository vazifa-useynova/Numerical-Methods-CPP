#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

/**
 * LinearRegression Class
 * Implementation of the Least Squares Method.
 * Demonstrates OOP principles and basic numerical optimization.
 */
class LinearRegression {
public:
    double slope = 0;
    double intercept = 0;

    /**
     * Fits the model to the provided data points (x, y).
     * Uses the formula: slope = covariance(x, y) / variance(x)
     */
    void fit(const std::vector<double>& x, const std::vector<double>& y) {
        if (x.empty() || x.size() != y.size()) return;

        size_t n = x.size();
        double x_sum = std::accumulate(x.begin(), x.end(), 0.0);
        double y_sum = std::accumulate(y.begin(), y.end(), 0.0);
        
        double x_mean = x_sum / n;
        double y_mean = y_sum / n;

        double numerator = 0;
        double denominator = 0;

        for (size_t i = 0; i < n; i++) {
            numerator += (x[i] - x_mean) * (y[i] - y_mean);
            denominator += (x[i] - x_mean) * (x[i] - x_mean);
        }

        // Avoiding division by zero
        if (denominator != 0) {
            slope = numerator / denominator;
            intercept = y_mean - (slope * x_mean);
        }
    }

    /**
     * Predicts the output for a given input based on the fitted model.
     */
    double predict(double x_val) const {
        return slope * x_val + intercept;
    }
};

int main() {
    // Sample data: y = 1x + 1 (with some noise)
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2.1, 2.9, 4.2, 5.1, 5.8};

    LinearRegression model;
    model.fit(x, y);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "========================================" << std::endl;
    std::cout << "Linear Regression Model Fitted" << std::endl;
    std::cout << "Formula: y = " << model.slope << "x + " << model.intercept << std::endl;
    std::cout << "========================================" << std::endl;

    // Test prediction
    double test_x = 6.0;
    std::cout << "Prediction for x = " << test_x << ": y = " << model.predict(test_x) << std::endl;

    return 0;
}
