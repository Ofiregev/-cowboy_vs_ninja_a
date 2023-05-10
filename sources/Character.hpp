#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;
     
namespace ariel {
    class Character {
        private:
            Point location;
            int score;
            string name;
        public:
            Character();
            Character(Point loc, int score, string name);
            bool isAlive();
            double distance ( Character* player);
            void hit(int points);
            string getName();
            Point getLocation();
            virtual void print(); 
            int getScore();
            void setScore(int score);
            void setLocation(Point loc);
            virtual const std::type_info& getType() const;
            //virtual void destructor();



    };
}

    


#endif