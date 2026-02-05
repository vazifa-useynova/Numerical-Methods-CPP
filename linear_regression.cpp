#include <iostream>
#include <vector>
#include <numeric>

/**
 * A simple implementation of Linear Regression using the Least Squares Method.
 * This is a fundamental building block for data fitting and optimization.
 */
class LinearRegression {
public:
    double slope = 0;
    double intercept = 0;

    void fit(const std::vector<double>& x, const std::vector<double>& y) {
        int n = x.size();
        double x_sum = std::accumulate(x.begin(), x.end(), 0.0);
        double y_sum = std::accumulate(y.begin(), y.end(), 0.0);
        
        double x_mean = x_sum / n;
        double y_mean = y_sum / n;

        double numerator = 0;
        double denominator = 0;

        for (int i = 0; i < n; i++) {
            numerator += (x[i] - x_mean) * (y[i] - y_mean);
            denominator += (x[i] - x_mean) * (x[i] - x_mean);
        }

        slope = numerator / denominator;
        intercept = y_mean - (slope * x_mean);
    }
};

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    LinearRegression model;
    model.fit(x, y);

    std::cout << "Model fitted: y = " << model.slope << "x + " << model.intercept << std::endl;
    return 0;
}
