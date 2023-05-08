#include "Duck.h"
#include <iostream>
int main()

{
    MallardDuck duck1;
    duck1.display();
    duck1.setFlyBehavior(new FlyWithWings());
    duck1.performFly();
    duck1.setQuackBehavior(new Quack());
    duck1.performQuack();

    std::cout << std::endl;

    RubberDuck rubberduck;
    rubberduck.display();
    rubberduck.setFlyBehavior(new FlyNoWay());
    rubberduck.performFly();
    rubberduck.setQuackBehavior(new Squack());
    rubberduck.performQuack();
    
    std::cout << std::endl;
    
    ModelDuck modelduck;
    modelduck.display();
    modelduck.setFlyBehavior(new FlyWithRocket());
    modelduck.performFly();
    modelduck.setQuackBehavior(new MuteQuack());
    modelduck.performQuack();

    return 0;
}