#include <cmath>
#include <iostream>
class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {
    }

    double Re() const {
        return real;
    }

    double Im() const {
        return imag;
    }
    friend std::istream& operator>>(std::istream& cinn, Complex& n) {
        cinn >> n.real >> n.imag;
        return cinn;
    }
    friend Complex operator+(const Complex& x1, const Complex x2) {
        return Complex(x1.Re() + x2.Re(), x1.Im() + x2.Im());
    }
    friend Complex operator+(const Complex& x, double y) {
        return Complex(x.Re() + y, x.Im());
    }
    friend Complex operator+(double y, const Complex& x) {
        return Complex(x.Re() + y, x.Im());
    }
    friend Complex operator-(const Complex& x1, const Complex& x2) {
        return Complex(x1.Re() - x2.Re(), x1.Im() - x2.Im());
    }
    friend Complex operator-(const Complex& x, double y) {
        return Complex(x.Re() - y, x.Im());
    }
    friend Complex operator-(double y, const Complex& x) {
        return Complex(y - x.Re(), x.Im());
    }
    friend Complex operator*(const Complex& x1, const Complex& x2) {
        return Complex(x1.Re() * x2.Re() - x1.Im() * x2.Im(), x1.Im() * x2.Re() + x1.Re() * x2.Im());
    }
    friend Complex operator*(const Complex& x, double y) {
        return Complex(y * x.Re(), y * x.Im());
    }
    friend Complex operator*(double y, const Complex& x) {
        return Complex(y * x.Re(), y * x.Im());
    }
    friend Complex operator/(const Complex& x1, const Complex& x2) {
        return Complex((x1.Re() * x2.Re() + x1.Im() * x2.Im()) / (x2.Re() * x2.Re() + x2.Im() * x2.Im()),
                       (x1.Im() * x2.Re() - x2.Im() * x1.Re()) / (x2.Re() * x2.Re() + x2.Im() * x2.Im()));
    }
    friend Complex operator/(const Complex& x, double y) {
        return Complex(x.Re() / y, x.Im() / y);
    }
    friend Complex operator/(double y, const Complex& x) {
        return Complex((x.Re() * y) / (x.Re() * x.Re() + x.Im() * x.Im()),
                       (-x.Im() * y) / (x.Re() * x.Re() + x.Im() * x.Im()));
    }
    friend Complex operator+(const Complex& x) {
        return x;
    }
    friend Complex operator-(const Complex& x) {
        return Complex(-x.real, -x.imag);
    }
    friend bool operator==(const Complex& x1, const Complex& x2) {
        return (x1.Re() == x2.Re() && x1.Im() == x2.Im());
    }

    friend bool operator!=(const Complex& x1, const Complex& x2) {
        return !(x1 == x2);
    }

    friend std::ostream& operator<<(std::ostream& coutt, const Complex& x) {
        coutt << x.Re() << ' ' << x.Im();
        return coutt;
    }
};
double Abs(const Complex& x) {
    return std::sqrt(x.Re() * x.Re() + x.Im() * x.Im());
}
