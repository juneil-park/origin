#pragma once
#include <iostream>

class Flybehavior
{
public:

    virtual void fly() = 0 ; 
    
};

class FlyWithWings : public Flybehavior
{
    void fly()
    {
        std::cout << "날고있어요!" << std::endl;
    }
};

class FlyNoWay : public Flybehavior
{
    void fly()
    {
        std::cout << "저는 못날아요." << std::endl;
    }
};


class FlyWithRocket : public Flybehavior
{
    void fly()
    {
        std::cout << "로켓추진으로 날아갑니다" << std::endl;

    }

};