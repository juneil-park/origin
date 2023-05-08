#pragma once
#include <iostream>
#include "Flybehavior.h"
#include "QuackBehavior.h"
class Duck
{
public:
    Flybehavior *flybehavior;
    QuackBehavior *quackBehavior;
    Duck() {};
    virtual ~Duck() {};
    virtual void display() = 0;
    void swim()
    {
        std::cout << "모든 오리는 물에 뜹니다." << std::endl;
    }
    
    void performFly()
    {
        flybehavior -> fly();
    }


    void setFlyBehavior(Flybehavior *fb)
    {
        flybehavior = fb;
    }

    void performQuack()
    {
        quackBehavior -> quack();
    }

    void setQuackBehavior(QuackBehavior *qu)
    {
        quackBehavior = qu;
    }


};

class MallardDuck : public Duck
{
public:
    MallardDuck() {};
    ~MallardDuck() {};
    void display()
    {
        std::cout << "저는 물오리 입니다." << std::endl;
    }

};


class RubberDuck : public Duck
{
public:
    RubberDuck() {};
    ~RubberDuck() {};
    void display()
    {
        std::cout << "저는 러버덕 입니다." << std::endl;
    }

};


class ModelDuck : public Duck
{
public:
    ModelDuck() {};
    ~ModelDuck() {};
    void display()
    {
        std::cout<< "저는 모형오리 with 로켓입니다." << std::endl;
    }

};