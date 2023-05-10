#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <string>
using namespace std;
     
namespace ariel {
    class Point {
        private:
            double point_x;
            double point_y;
        public:
            Point(double x, double y);
            double distance(Point p);
            double getX();
            double getY();
            Point moveTowards(Point dest, double distance);
            void print();
            string get_string_for_print();
            friend bool operator==(const Point& point1, const Point& point2);



    };
}

    


#endif