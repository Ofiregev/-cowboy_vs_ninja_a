#include "Team.hpp"
#include "typeinfo"
namespace ariel
{

    Team::Team(Character *leader) : team_leader(*leader) {}

    bool Team::isCowboy(Character *warrier)
    {
        return typeid(warrier) == typeid(Cowboy);
    }

    void Team::add(Character* warrior) {
    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(warrior)) {
        cout << "cowboy added" << endl;
        cout << "Member is of type " << warrior->getType().name() << endl;
        for (int i = 0; i < 10; i++) {
            if (!members[i]) {
                members[i] = cowboy;
                break;
            }
        }
    }
    else if (Ninja* ninja = dynamic_cast<Ninja*>(warrior)) {
        cout << "ninja added" << endl;
        cout << "Member is of type " << warrior->getType().name() << endl;
        for (int i = 0; i < 10; i++) {
            if (!members[i]) {
                members[i] = ninja;
                break;
            }
        }
    }
}


    // Find the closest team leader
    void Team::findClosestTeamLeader()
    {
        double minimal_dist = 100000;
        for (int i = 0; i < 10; i++)
        {
            if (members[i]->isAlive() && members[i]->distance(&team_leader) < minimal_dist)
            {
                minimal_dist = members[i]->distance(&team_leader);
            }
            team_leader = *members[i];
        }
    }

    // Find the closest victim
    // Character Team::findClosestVictim(Team *enemies)
    // {
    //     Character victim;
    //     double minimal_dist = 100000;
    //     for (int i = 0; i < 10; i++)
    //     {
    //         if (enemies->members[i].isAlive())
    //         { // check if enemy is alive
    //             double dist = enemies->members[i].distance(&team_leader);
    //             if (dist < minimal_dist)
    //             {
    //                 minimal_dist = dist;
    //                 victim = enemies->members[i];
    //             }
    //         }
    //     }
    //     return victim;
    // }
     Character *Team::findClosestVictim(Team *enemies)
    {
        //cout << "closet victim"<< endl;

        Character *victim = nullptr;
        double minimal_dist = 100000;
        for (int i = 0; i < 10; i++)
        {
            if (enemies->members[i] && enemies->members[i]->isAlive())
            {
                double dist = enemies->members[i]->distance(&team_leader);
                if (dist < minimal_dist)
                {
                    minimal_dist = dist;
                    victim = enemies->members[i]; // assign pointer to existing object
                }
            }
        }
        if(!victim)
        {
            cout << "null"<< endl;

        }
        //victim->print();

        return victim;
    }

    // Conduct the attack
    void Team::killVictim(Team *enemies)
    {
        //enemies->print();
        Character *victim = findClosestVictim(enemies);
        //this->print();

        for (int i = 0; i < 10; i++)
        {
            if (members[i] && members[i]->isAlive())
            {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(members[i]))
                {
                    if (cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else
                    {
                        cowboy->reload();
                    }
                }
                else if (Ninja *ninja = dynamic_cast<Ninja *>(members[i]))
                {
                    if (ninja->distance(victim) <= 1)
                    {
                        ninja->slash(victim);
                    }
                    else
                    {
                        ninja->move(victim);
                    }
                }
                else
                {
                    cout << typeid(*members[i]).name() << endl;
                    cout << "Member is neither Cowboy nor Ninja!" << endl;
                }
            }
        }
    }

    // Main attack function
    void Team::attack(Team *enemies)
    {
         if (enemies == nullptr)
    {
        cout << "Error: no enemies specified." << endl;
        return;
    }
        //cout << "attack"<< endl;

        if (!team_leader.isAlive())
        {
            findClosestTeamLeader();
        }
        //cout << enemies->stillAlive() << endl;
        while (stillAlive() > 0 && enemies->stillAlive() > 0)
        {
            killVictim(enemies);
        }
    }

 
    int Team::stillAlive()
    {
        //cout << "still alive" << endl;
        int count = 0;
        for (int i = 0; i < 10; i++)
        {
            if (members[i] && members[i]->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team::print()
    {
        cout << "The team leader is " << team_leader.getName() << "." << endl;
        cout << "The members of the team are:" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (members[i])
            {
                members[i]->print();
                //cout << members[i]->getType().name() << endl;
            }
        }
    }

    void Team::distructor()
    {
        for (int i = 0; i < 10; i++)
        {
            if (!members[i]->getName().empty())
            {
                delete &members[i];
            }
        }
    }
} // namespace ariel
