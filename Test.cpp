#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization - Point")
{
    Point p1(1, 2), p2(2,2), p3(3,2);
    CHECK(p1.getX() == 1);
    CHECK(p1.getY() == 2);
    CHECK(p1.distance(p2) == 1);
    CHECK(p2.distance(p1) == 1);
    Point res = p1.moveTowards(p3,1);
    CHECK(res == p2);
    res = p2.moveTowards(p3,0);
    CHECK(res == p2); 
}
TEST_CASE("Test 2 - Initialization - Characters")
{
    Point p1(1, 2), p2(2,2), p3(15,20);
    Cowboy c("c", p1);
    c.setScore(0); // make him dead
    CHECK_THROWS(c.hasboolets());
    Cowboy c1("martin", p1);
    OldNinja n1("sushi", p2);
    YountNinja n2("sushika", p3);
    CHECK(n1.getScore() == 150);
    CHECK(c1.getLocation() == p1);
    CHECK(c1.getScore() == 11);
    CHECK(c1.getNumOfBullets() == 6);
    c1.hit(3);
    CHECK(c1.getScore() == 8);
    c1.shoot(&n1);
    CHECK(c1.getNumOfBullets() == 5);
    c1.reload();
    CHECK(n1.getScore() == 149);
    n1.slash(&c1); // killed c1
    CHECK_FALSE(c1.isAlive());
    CHECK_THROWS(c1.getNumOfBullets());
    CHECK_THROWS(c1.shoot(&n2));
    n1.slash(&n2);
    CHECK(n2.getScore() == 100); // the ninja is too far
}
