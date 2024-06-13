#include <iostream>
#include <ostream>
#include <utility>
#include "vector.hpp"
#include "array.hpp"

using namespace std;

class point {
    private:
        int x,y;
    public:
        point(int a, int b) : x(a), y(b) {}
        point() : x(0), y(0) {}

        friend ostream& operator<<(ostream& os, point val);
};

ostream& operator<<(ostream& os, point val) {
    os<<'(' << val.x << ',' << val.y << ')' << ' ';
    return os;
}

int main() {
    vect<point> a(5,point(1,1));
    a.print();

    vect<point> b(3, point(2,2));
    b.print();

    a = std::move(b);
    a.print();
    b.print();

    vect<point> c(std::move(b));
    c.print();

    b.push_back(point(4,4));
    b.print();
    c.print();
}
