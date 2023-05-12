#pragma once
#include <iostream>
#include "Behavior.h"

class Charactor
{
    public:
    Charactor(int p, int i, double h, int pi) :power_(p), intel_(i), hp_(h), damage_(0), playerinfo_(pi) {};;
    ~Charactor() {};
    Behavior *behavior;
    
    void setBehavior(Behavior *bh)
    {
        behavior = bh;
    }

    void performBehavior()
    {
        behavior -> behav();
    }

    double performBehavior(Behavior *opponent, double opponent_damage)
    {
        return behavior -> behav(opponent,damage_,opponent_damage,hp_,intel_);
    }

    double GetHp()
    {
        return hp_;
    }

    void SetHp(double hp)
    {
        if (hp>0)
        {        
            hp_ = hp;
        }
        else
        {
            hp_ = 0;
        }
    }

    double GetDamage()
    {
        return damage_;
    }

    void SetDamage(double damage)
    {
        damage_ = damage;
    }

    int GetPower()
    {
        return power_;
    }

    int GetIntel()
    {
        return intel_;
    }

    int GetPlayerInfo()
    {
        return playerinfo_;
    }

    private:

    int power_;
    int intel_;
    double hp_;
    double damage_;
    int playerinfo_;
};