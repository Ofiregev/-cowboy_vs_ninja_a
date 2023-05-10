#ifndef NINJA_HPP
#define NINJA_HPP
#include <iostream>
#include <string>
#include "Character.hpp"
using namespace std;
     
namespace ariel {
    class Ninja : public Character {
        private:
            int speed;
            
        public:
            Ninja(Point loc,int score,string name);
            void setSpeed(int speed);
            void move(Character* enemy);
            void slash(Character* enemy);
            void print() override;
            const std::type_info& getType() const override;
            //void destructor() override;


    };
}

    


#endif