#ifndef TEAM_HPP
#define TEAM_HPP
#include <iostream>
#include <string>
#include <array>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YountNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;
     
namespace ariel {
    class Team {
        
        private:
            std::array<Character*, 10> members{};
            Character& team_leader;
        public:
            Team(Character *leader);
            virtual void add(Character* warrier);
            void attack(Team * enemies);
            Character& getTeamLeader();
            void findClosestTeamLeader();
            Character* findClosestVictim(Team* enemies);
            void killVictim(Team* enemies);
            bool isCowboy(Character* warrier);
            int stillAlive();
            virtual void print();
            void destructor();



    };
}

    


#endif