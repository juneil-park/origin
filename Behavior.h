#pragma once
#include <iostream>
#include <cmath>

class Behavior
{
public:
    virtual void behav() = 0;
    virtual double behav(Behavior *opponent,double my_damage,double opponent_damage,double my_hp,int my_intel) = 0;
    virtual double CallFromAttack(double my_damage,double opponent_damage) = 0;
    virtual double CallFromDefend(double my_damage,double opponent_damage) = 0;
    virtual double CallFromCounterAttack(double my_damage,double opponent_damage) = 0;
    virtual double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel) = 0;
    virtual double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp) = 0;

}; 

class Attack : public Behavior
{
    void behav()
    {
        std::cout <<"공격!" << std::endl;
    }
    double behav(Behavior *opponent,double my_damage,double opponent_damage,double my_hp,int my_intel)
    {
        double deal;
        deal = opponent->CallFromAttack(my_damage,opponent_damage);
        return deal;
        
    }

    double CallFromAttack(double my_damage,double opponent_damage)
    {
        return my_damage;
    }

    double CallFromDefend(double my_damage,double opponent_damage)
    {
        return 0;
    }

    double CallFromCounterAttack(double my_damage,double opponent_damage)
    {
        return opponent_damage;
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.1;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return my_hp;
    }

};

class Defend : public Behavior
{
    void behav()
    {
        std::cout <<"방어!" << std::endl;
    }

    double behav(Behavior *opponent,double my_damage,double opponent_damage,double my_hp,int my_intel)
    {
        // std::cout << "상호작용 - 방어" << std::endl;
        
        double deal;
        deal = opponent -> CallFromDefend(my_damage,opponent_damage);
        return deal;
    }

    double CallFromAttack(double my_damage,double opponent_damage)
    {
        return 0;
    }

    double CallFromDefend(double my_damage,double opponent_damage)
    {
        return 0;
    }

    double CallFromCounterAttack(double my_damage,double opponent_damage)
    {
        return 20; // 상대방의 다음 합은 무효가 됩니다.
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.2;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return my_hp;
    }

};

class CounterAttack : public Behavior
{
    void behav()
    {
        std::cout <<"카운터!" << std::endl;
    }

    double behav(Behavior *opponent,double my_damage,double oppnent_damage,double my_hp,int my_intel)
    {
        double deal;
        deal = opponent->CallFromCounterAttack(my_damage,oppnent_damage);
        return deal;
    }

    double CallFromAttack(double my_damage,double oppnent_damage)
    {
        return 10;
    }

    double CallFromDefend(double my_damage,double oppnent_damage)
    {
        return 0; // 내 다음 합은 무효가 됩니다.
    }

    double CallFromCounterAttack(double my_damage,double oppnent_damage)
    {
        return my_damage;
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.1;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return my_hp/2;
    }
};

class HealthShild : public Behavior
{
    void behav()
    {
        std::cout <<"스킬!" << std::endl;
    }

    double behav(Behavior *opponent,double my_damage,double oppnent_damage,double my_hp,int my_intel)
    {
        // std::cout << "상호작용 - 스킬" << std::endl;
        double deal;
        deal = opponent -> CallFromHealthShield(my_damage,oppnent_damage,my_intel);
        return deal;
    }

    double CallFromAttack(double my_damage,double oppnent_damage)
    {
        return 0; 
    }

    double CallFromDefend(double my_damage,double oppnent_damage)
    {
        return 0;
    }

    double CallFromCounterAttack(double my_damage,double oppnent_damage)
    {
        return 0;
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.1;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return 0;
    }
};

class YukBalSanGiGaeSay : public Behavior
{
    void behav()
    {
        std::cout <<"스킬!" << std::endl;
    }

    double behav(Behavior *opponent,double my_damage,double oppnent_damage,double my_hp,int my_intel)
    {
        // std::cout << "상호작용 - 스킬" << std::endl;
        double deal;
        deal = opponent -> CallFromYukBalSanGiGaeSay(my_damage,oppnent_damage,my_hp);
        return deal;
    }

    double CallFromAttack(double my_damage,double oppnent_damage)
    {
        return my_damage;
    }

    double CallFromDefend(double my_damage,double oppnent_damage)
    {
        return 0;
    }

    double CallFromCounterAttack(double my_damage,double oppnent_damage)
    {
        return 0;
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.1;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return 0;
    }
};

class DoNothing : public Behavior
{
    void behav()
    {
        std::cout <<"아무것도 못합니다!" << std::endl;
    }
    double behav(Behavior *opponent,double my_damage,double opponent_damage,double my_hp,int my_intel)
    {
        double deal;
        return 0;
        
    }

    double CallFromAttack(double my_damage,double opponent_damage)
    {
        return my_damage;
    }

    double CallFromDefend(double my_damage,double opponent_damage)
    {
        return 0;
    }

    double CallFromCounterAttack(double my_damage,double opponent_damage)
    {
        return my_damage;
    }

    double CallFromHealthShield(double my_damage,double opponent_damage, int my_intel)
    {
        return my_damage +(my_intel + std::abs(my_damage-opponent_damage))*0.1;
    }

    double CallFromYukBalSanGiGaeSay(double my_damage,double opponent_damage, double my_hp)
    {
        return my_hp;
    }

};