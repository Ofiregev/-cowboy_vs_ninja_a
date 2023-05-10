#include "Character.hpp"

namespace ariel
{

    Character::Character(Point loc, int score, string name) : location(loc), score(score), name(name) {}

    bool Character::isAlive()
    {
        return score > 0;
    }

    double Character::distance(Character *player)
    {
        return location.distance(player->location);
    }

    void Character::hit(int points)
    {
        score = score - points;
    }

    string Character::getName()
    {
        return name;
    }

    Point Character::getLocation()
    {
        return location;
    }
    void Character::setLocation(Point loc)
    {
        location = loc;
    }

    void Character::print()
    {
        if(!isAlive())
        {
            cout << "Name: (" << name << ")";
        }
        cout << "Name: " << name << ", Score: " << score << ", Location: (" << location.getX() << "," << location.getY() << ")" << endl;
    }

    int Character::getScore()
    {
        return score;
    }
    void Character::setScore(int s)
    {
        this->score = s;   
     }
    const std::type_info& Character::getType() const {
        return typeid(Character);
    }

} // namespace ariel
