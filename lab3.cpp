#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Масив коефіцієнтів
    int degree; // Ступінь многочлена

public:
    // Конструктор класу
    Polynomial(int deg, const vector<double>& coeffs) {
        degree = deg;
        coefficients = coeffs;
    }

    // Метод для обчислення значення многочлена для заданого аргументу x
    double evaluate(double x) {
        double result = 0.0;
        double x_pow = 1.0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * x_pow;
            x_pow *= x;
        }
        return result;
    }

    // Метод для додавання многочленів
    Polynomial add(const Polynomial& other) {
        int max_degree = max(degree, other.degree);
        vector<double> result_coeffs(max_degree + 1, 0.0);
        for (int i = 0; i <= max_degree; i++) {
            if (i <= degree) result_coeffs[i] += coefficients[i];
            if (i <= other.degree) result_coeffs[i] += other.coefficients[i];
        }
        return Polynomial(max_degree, result_coeffs);
    }

    // Метод для віднімання многочленів
    Polynomial subtract(const Polynomial& other) {
        int max_degree = max(degree, other.degree);
        vector<double> result_coeffs(max_degree + 1, 0.0);
        for (int i = 0; i <= max_degree; i++) {
            if (i <= degree) result_coeffs[i] += coefficients[i];
            if (i <= other.degree) result_coeffs[i] -= other.coefficients[i];
        }
        return Polynomial(max_degree, result_coeffs);
    }

    // Метод для множення многочленів
    Polynomial multiply(const Polynomial& other) {
        int result_degree = degree + other.degree;
        vector<double> result_coeffs(result_degree + 1, 0.0);
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result_degree, result_coeffs);
    }

    // Метод для виводу многочлена на екран
    void print() {
        for (int i = degree; i >= 0; i--) {
            cout << coefficients[i];
            if (i > 0) cout << "x^" << i << " + ";
        }
        cout << endl;
    }
};

int main() {
    // Приклад використання класу Polynomial
    vector<double> coeffs1 = {2, -3, 1}; // 2x^2 - 3x + 1
    vector<double> coeffs2 = {1, 4};     // x + 4

    Polynomial poly1(2, coeffs1);
    Polynomial poly2(1, coeffs2);

    cout << "Polynomial 1: ";
    poly1.print();

    cout << "Polynomial 2: ";
    poly2.print();

    Polynomial sum = poly1.add(poly2);
    cout << "Sum: ";
    sum.print();

    Polynomial difference = poly1.subtract(poly2);
    cout << "Difference: ";
    difference.print();

    Polynomial product = poly1.multiply(poly2);
    cout << "Product: ";
    product.print();

    cout << "Value of Polynomial 1 at x=3: " << poly1.evaluate(3) << endl;

    return 0;
}
