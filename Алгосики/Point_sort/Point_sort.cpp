#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

struct Student {
    std::string name;
    std::string lname;
    int day = 0;
    int month = 0;
    int year = 0;
};
bool NameSort(const Student& x, const Student& y) {
    auto n1 = std::tie(x.lname, x.name, x.year, x.month, x.day);
    auto n2 = std::tie(y.lname, y.name, y.year, y.month, y.day);
    return n1 < n2;
};
bool DateSort(const Student& x, const Student& y) {
    auto d1 = std::tie(x.year, x.month, x.day, x.lname, x.name);
    auto d2 = std::tie(y.year, y.month, y.day, y.lname, y.name);
    return d1 < d2;
};
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Student> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i].name >> vec[i].lname >> vec[i].day >> vec[i].month >> vec[i].year;
    }
    std::string s;
    std::cin >> s;
    if (s == "name") {
        std::sort(vec.begin(), vec.end(), NameSort);
    } else {
        std::sort(vec.begin(), vec.end(), DateSort);
    }
    for (int j = 0; j < n; ++j) {
        std::cout << vec[j].name << " " << vec[j].lname << " " << vec[j].day << "." << vec[j].month << "."
                  << vec[j].year << "\n";
    }
    return 0;
}