#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
    private:
        int area;
        int perimeter;
    public:
        virtual int getArea() = 0;
        virtual int getPerimeter() = 0;

        virtual ~Shape() {};
};

#endif