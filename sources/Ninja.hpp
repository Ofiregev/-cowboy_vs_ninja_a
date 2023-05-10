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
            void setSpeed(int s);
            void move(Character* enemy);
            void slash(Character* enemy);
            virtual void print() override;
            const std::type_info& getType() const override;


    };
}

    


#endif