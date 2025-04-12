#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Shape {
   private:
    std::string name_;

   public:
    explicit Shape() = default;

    Shape(const std::string &name) : name_(name) {
    }

    virtual double area() const {
        return 0;
    }

    std::string getName() const {
        return name_;
    }
};

class Circle : public Shape {
   private:
    double rad_;

   public:
    Circle(const double &radius) : rad_(radius), Shape("Circle") {
    }

    double area() const {
        return M_PI * rad_ * rad_;
    }
};

class Rectangle : public Shape {
   private:
    double x_;
    double y_;

   public:
    Rectangle(const double &x, const double &y) : x_(x), y_(y), Shape("Rectangle") {
    }

    double area() const {
        return x_ * y_;
    }
};

std::ostream &operator<<(std::ostream &os, const Shape &sh) {
    os << sh.getName();
    return os;
}

void processInput() {
    std::string line;
    std::vector<Shape *> shapes;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "circle") {
            double radius;
            iss >> radius;
            shapes.push_back(new Circle(radius));
            std::cout << "Created " << shapes.back()->getName() << " with radius " << radius << std::endl;
        } else if (command == "rectangle") {
            double width, height;
            iss >> width >> height;
            shapes.push_back(new Rectangle(width, height));
            std::cout << "Created " << shapes.back()->getName() << " with width " << width << " and height " << height
                      << std::endl;
        } else if (command == "area") {
            for (const auto &shape : shapes) {
                std::cout << (*shape).getName() << " Area: " << (*shape).area() << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    for (auto shape : shapes) {
        delete shape;
    }
}
int main() {
    processInput();
    return 0;
}