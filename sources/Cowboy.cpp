#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point location) : Character(location, 11, name), num_of_bullets(6) {}

    void Cowboy::setBullets(int bul) {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        num_of_bullets = bul;
    }
    int Cowboy::getNumOfBullets() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        return num_of_bullets;
    }

    void Cowboy::shoot(Character * enemy) {
        if (hasboolets() && isAlive()) {
            double dist = distance(enemy);
            enemy->hit(1);
            //cout << getName() << " shoots " << enemy->getName() << "!" << endl;
            num_of_bullets--;
        }
        else {
            throw("cannot shoot!");
            //cout << getName() << " has no bullets left!" << endl;
        }
    }

    bool Cowboy::hasboolets() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        return num_of_bullets > 0;
    }

    void Cowboy::reload() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        num_of_bullets = 6;
    }

    void Cowboy::print() {
        cout << "C: " << getName() << ", Location: ";
        getLocation().print();
        cout << ", Score: " << getScore() << ", Bullets: " << num_of_bullets << endl;
    }
    const std::type_info& Cowboy::getType() const {
        return typeid(Cowboy);
    }

} // namespace ariel
