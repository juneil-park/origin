#include <iostream>
#include <random>
#include <string>
#include "Charactor.h"
#include <deque>
#include <random>
#include <vector>
#include <algorithm>

template <typename T>
void PrintDeque(std::deque<T>& dq)
{
    enum AvailableMovement
    {ATTACK=1, DEFEND, COUNTERATTACK, SPECIALMOVE, DONOTHING = 9};

    std::cout << "[ ";
    for  (const auto& elem: dq)
    {
        switch (elem)
        {
            case ATTACK:
                std::cout<< "Attack" <<" ";
                break;

            case DEFEND:
                std::cout<< "Defend" <<" ";
                break;

            case COUNTERATTACK:
                std::cout<< "CounterAttack" <<" ";
                break;

            case SPECIALMOVE:
                std::cout<< "SpecialMove" <<" ";
                break;

            case DONOTHING:
                std::cout<< "DoNothing" <<" ";
                break;

        }   
    // std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}


template <typename T>
void PrintDequeUsingIntel(std::deque<T>& dq, int my_intel, int xi_intel)
{
    enum AvailableMovement
    {ATTACK=1, DEFEND, COUNTERATTACK, SPECIALMOVE, DONOTHING = 9};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_open_num(0,4); 
    std::vector<int> open_num_vector(5,0);
    int open_num = round((my_intel - xi_intel)/10) ;
    for (int i=0; i<open_num; i++);
        open_num_vector.push_back(dis_open_num(gen));
    
    std::sort(open_num_vector.begin(),open_num_vector.end());

    int open_count = 0;
    std::cout << "Xiangyu's Move Pridiction : [ ";
    
    for  (const auto& elem: dq)
    {   
        if (std::count(open_num_vector.begin(), open_num_vector.end(), open_count))
        {
            switch (elem)
            {
                case ATTACK:
                    std::cout<< "Attack" <<" ";
                    break;

                case DEFEND:
                    std::cout<< "Defend" <<" ";
                    break;

                case COUNTERATTACK:
                    std::cout<< "CounterAttack" <<" ";
                    break;

                case SPECIALMOVE:
                    std::cout<< "SpecialMove" <<" ";
                    break;

                case DONOTHING:
                    std::cout<< "DoNothing" <<" ";
                    break;

            }   
        }
        else
        {
            std::cout << "?" << " ";
        }
        open_count++;
    }
    std::cout << "]" << std::endl;

}

std::deque<int> SetMyMove()  // enum으로 구현?
{
    // std::vector<std::string> available_movement = {"Attack", "Defend","CounterAttack","SpecialMove"};
    enum AvailableMovement
    {ATTACK=1, DEFEND, COUNTERATTACK, SPECIALMOVE, DONOTHING = 9};
    std::deque<int> my_move;
    int movement;
    int special_token = 1;
    int i=0;
    std::cout <<"당신의 행동을 아래에서 골라주세요" << std::endl;
    std::cout << "1. Attack / 2.Defend / 3.CounterAttack / 4. SpecialMove" << std::endl;
    
    while (i<5)
    {
        std::cin >> movement;
        // std::cout << "Input num : " << movement << std::endl;
        if (movement >=ATTACK && movement<=SPECIALMOVE) 
        {
            if (movement == SPECIALMOVE)
                {    
                if(special_token == 1)
                {
                    my_move.push_back(movement);
                    // my_move.push_back(availablemovement.movement);
                    i++;
                    special_token--;
                }
                else
                {
                    std::cout<<"더 이상의 스킬은 사용할수없습니다 휴먼."<<std::endl;
                }
            }
            else
            {
                my_move.push_back(movement);
                i++;
            }
            }
        else
        {
            std::cout<<"표시된 번호 중에서 선택해주세요 (제발)"<<std::endl;
        }
        // std::cout << i <<std::endl;
    }
        return my_move;

}

std::deque<int> SetXiangyuMove()  // enum으로 구현?
{
    enum AvailableMovement
    {ATTACK=1, DEFEND, COUNTERATTACK, SPECIALMOVE, DONOTHING = 9};
    std::deque<int> xiangyu_move;
    int movement;
    int special_token = 1;
    int i=0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_num(1,4); 


    while (i<5)
    {
        movement = dis_num(gen);
    
        if (movement == SPECIALMOVE)
            {    
            if(special_token == 1)
            {
                xiangyu_move.push_back(movement);
                // my_move.push_back(availablemovement.movement);
                i++;
                special_token--;
            }
    
        }
        else
        {
            xiangyu_move.push_back(movement);
            i++;
        }
    }
   
    return xiangyu_move;

}

Behavior* MoveConvert(int movement, int player)
{
    enum testEnum
    {
        ATTACK=1,
        DEFEND,
        COUNTERATTACK,
        SPECIALMOVE,
        DONOTHING = 9
    };
    
    switch (movement)
    {
        case ATTACK:
            return new Attack();
    
        case DEFEND:
            return new Defend();
        case COUNTERATTACK:
            return new CounterAttack();

        case SPECIALMOVE:
            if (player == 0)
            {
                return new HealthShild();
            }
            else if (player == 1)
            {
                return new YukBalSanGiGaeSay();
            }
        case DONOTHING:
            return new DoNothing();
    }
}

int main()
{   

    std::deque<int> xiangyu_move = SetXiangyuMove(); // 랜덤생성으로 개발 해보실?


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_power(60,80); // 플레이어의 power 랜덤 생성 (60-80)
    std::uniform_int_distribution<int> dis_intel(70,100); // 플레이어의 intelligent 랜덤 생성 (70-100)
    
    Charactor me(dis_power(gen),dis_intel(gen),100);
    Charactor xiangyu(100,50,100);
    
    PrintDequeUsingIntel(xiangyu_move,me.GetIntel(), xiangyu.GetIntel());

    std::deque<int> my_move = SetMyMove();
    std::cout << "My move :";
    PrintDeque(my_move);

    std::cout << "Xiang-yu move :";
    PrintDeque(xiangyu_move);


    me.SetDamage((50-(xiangyu.GetPower()-me.GetPower()))/2);
    xiangyu.SetDamage((50-(me.GetPower()-xiangyu.GetPower()))/2);


    std::cout << "My damage : " << me.GetDamage() << std::endl;
    std::cout << "Xiangyu's damage : " << xiangyu.GetDamage() << std::endl;

    int me_movement;
    int xi_movement;
    int hasty_result = 1;

    for (int round_num = 0; round_num<5; round_num++)
    {
        me_movement = my_move[round_num];
        xi_movement = xiangyu_move[round_num];

        Behavior* meBehavior = MoveConvert(me_movement,0);
        Behavior* xiBehavior = MoveConvert(xi_movement,0);
        
        // Behavior* meBehavior  = new Defend();
        // Behavior* xiBehavior   = new Attack();    

        me.setBehavior(meBehavior);
        // me.performBehavior();
        double me_deal = me.performBehavior(xiBehavior,xiangyu.GetDamage());
        xiangyu.SetHp(xiangyu.GetHp() - me_deal);
        


        xiangyu.setBehavior(xiBehavior);
        double xiangyu_deal = xiangyu.performBehavior(meBehavior,me.GetDamage());
        me.SetHp(me.GetHp() - xiangyu_deal);

        // me.performBehavior();
        // std::cout << "내 HP : " << me.GetHp() << std::endl;
        // xiangyu.performBehavior() ;
        // std::cout  << "항우 HP : " << xiangyu.GetHp() << std::endl;
        
        //결과 보고
        std::cout << "Round " << round_num+1 << ")" << "You : " << me.GetHp() << " " << "Xiang-yu : " << xiangyu.GetHp() << std::endl;
        
        //종료조건
        if (me.GetHp() == 0 || xiangyu.GetHp() == 0)
        {
            if (me.GetHp() == 0 && xiangyu.GetHp() == 0)
            {
                std::cout << "Draw" << std::endl;
            }
            else if (me.GetHp() == 0)
            {
                std::cout << "Defeat" << std::endl;
            }
            else if (xiangyu.GetHp() == 0)
            {
                std::cout << "Victory" << std::endl;
            }
            hasty_result--;
            break;
        }
        //카운터 디펜드 조건
        if (round_num <4)    
            if (me_movement == 2 && xi_movement == 3)
            {
                xiangyu_move.erase(xiangyu_move.begin()+round_num+1);
                xiangyu_move.insert(xiangyu_move.begin()+round_num+1,9); 
            }

            if (me_movement == 3 && xi_movement == 2)
            {
                my_move.erase(my_move.begin()+round_num+1);
                my_move.insert(my_move.begin()+round_num+1,9);
            }
    
    }

    if (hasty_result == 1)
        if (me.GetHp() > xiangyu.GetHp())
            std::cout << "Victory : Player!" << std::endl;
        
        else if (me.GetHp() < xiangyu.GetHp())
            std::cout << "Victory : Xiang-Yu!" << std::endl;
    
        else if (me.GetHp() > xiangyu.GetHp())
            std::cout << "Victory : Draw!" << std::endl;


    return 0;
}