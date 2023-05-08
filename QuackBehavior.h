#pragma once
#include <iostream>

class QuackBehavior
{
public:
    virtual void quack() = 0;   
};


class Quack : public QuackBehavior
{
    void quack()
    {
        std::cout << "꽥" << std::endl;
    }

};

class MuteQuack : public QuackBehavior
{
    void quack()
    {
        std::cout << "<<  조용  >>" << std::endl;
    }

};

class Squack : public QuackBehavior
{
    void quack()
    {
        std::cout << "삑" << std::endl;
    }

};