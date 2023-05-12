#include <iostream>
#include <random>
#include <string>
#include "Charactor.h"
#include <deque>
#include <random>
#include <vector>
#include <algorithm>

enum class AvailableMovement : int
{
    ATTACK = 1, 
    DEFEND, 
    COUNTERATTACK, 
    SPECIALMOVE, 
    DONOTHING = 9
};

enum class CharactorInfo : int
{
    PLAYER,
    XIANGYU
};

template <typename T>
void PrintMove(std::deque<T>& dq, enum AvailableMovement)
{
    std::cout << "[ ";
    for  (const auto& elem: dq)
    {
        switch (static_cast<AvailableMovement>(elem))
        {
            case AvailableMovement::ATTACK:
                std::cout<< "Attack" <<" ";
                break;

            case AvailableMovement::DEFEND:
                std::cout<< "Defend" <<" ";
                break;

            case AvailableMovement::COUNTERATTACK:
                std::cout<< "CounterAttack" <<" ";
                break;

            case AvailableMovement::SPECIALMOVE:
                std::cout<< "SpecialMove" <<" ";
                break;

            case AvailableMovement::DONOTHING:
                std::cout<< "DoNothing" <<" ";
                break;

        }   
    // std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}


template <typename T>
void PrintMoveUsingIntel(std::deque<T>& dq, int my_intel, int xi_intel, enum AvailableMovement)
{
    
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
            switch (static_cast<AvailableMovement>(elem))
            {
                case AvailableMovement::ATTACK:
                    std::cout<< "Attack" <<" ";
                    break;

                case AvailableMovement::DEFEND:
                    std::cout<< "Defend" <<" ";
                    break;

                case AvailableMovement::COUNTERATTACK:
                    std::cout<< "CounterAttack" <<" ";
                    break;

                case AvailableMovement::SPECIALMOVE:
                    std::cout<< "SpecialMove" <<" ";
                    break;

                case AvailableMovement::DONOTHING:
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

std::deque<int> SetPlayerMove(enum AvailableMovement)  
{
    
    std::deque<int> my_move;
    int movement;
    bool special_token = true;
    int i=0;
    std::cout <<"당신의 행동을 아래에서 골라주세요" << std::endl;
    std::cout << "1. Attack / 2.Defend / 3.CounterAttack / 4. SpecialMove" << std::endl;
    
    while (i<5)
    {
        std::cin >> movement;
        
        if (movement >= static_cast<int>(AvailableMovement::ATTACK) && movement<=static_cast<int>(AvailableMovement::SPECIALMOVE)) // 허용되는 입력 범위.
        {
           
            if (static_cast<AvailableMovement>(movement) == AvailableMovement::SPECIALMOVE)
                {    
                if (special_token == true)
                {
                    my_move.push_back(movement);
                    i++;
                    special_token = false;
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
    }
        return my_move;

}

std::deque<int> SetXiangyuMove(enum AvailableMovement)
{
    std::deque<int> xiangyu_move;
    int movement;
    bool special_token = true;
    int i=0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_num(1,4); 

    while (i<5)
    {
        movement = dis_num(gen);
    
        if (static_cast<AvailableMovement>(movement) == AvailableMovement::SPECIALMOVE)
            {    
            if (special_token == true)
            {
                xiangyu_move.push_back(movement);
                i++;
                special_token = false;
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

Behavior* MoveConvert(int movement, int player_info, enum CharactorInfo,enum AvailableMovement)
{ 
    switch (static_cast<AvailableMovement>(movement))
    {
        case AvailableMovement::ATTACK:
            return new Attack();
    
        case AvailableMovement::DEFEND:
            return new Defend();
            
        case AvailableMovement::COUNTERATTACK:
            return new CounterAttack();

        case AvailableMovement::SPECIALMOVE:
            if ((static_cast<CharactorInfo>(player_info) == CharactorInfo::PLAYER))
            {
                return new HealthShild();
            }
            else if ((static_cast<CharactorInfo>(player_info) == CharactorInfo::XIANGYU))
            {
                return new YukBalSanGiGaeSay();
            }
        case AvailableMovement::DONOTHING:
            return new DoNothing();
    }
}

int main()
{   

    AvailableMovement availablemovement;
    CharactorInfo charactorinfo;

    std::deque<int> xiangyu_move = SetXiangyuMove(availablemovement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_power(60,80); // 플레이어의 power 랜덤 생성 (60-80)
    std::uniform_int_distribution<int> dis_intel(70,100); // 플레이어의 intelligent 랜덤 생성 (70-100)
    

    Charactor player(dis_power(gen),dis_intel(gen),100,0); // (power, intelligent, hp, playerinfo[player : 0 , xiangyu : 1])
    Charactor xiangyu(100,50,100,1);
    
    //플레이어의 지능을 이용해서 항우의 행동을 예측, 콘솔에 표시
    PrintMoveUsingIntel(xiangyu_move,player.GetIntel(), xiangyu.GetIntel(), availablemovement); 
    
    std::deque<int> player_move = SetPlayerMove(availablemovement);
    std::cout << "Player's move :";
    PrintMove(player_move,availablemovement);

    std::cout << "Xiang-yu's move :";
    PrintMove(xiangyu_move,availablemovement);


    player.SetDamage((50-(xiangyu.GetPower()-player.GetPower()))/2);
    xiangyu.SetDamage((50-(player.GetPower()-xiangyu.GetPower()))/2);


    std::cout << "Player's damage : " << player.GetDamage() << std::endl;
    std::cout << "Xiangyu's damage : " << xiangyu.GetDamage() << std::endl;

    int player_current_movement;
    int xiangyu_current_movement;
    bool hasty_result = false; //모든 라운드가 종료하기 전에 결과가 나왔는지 체크

    for (int round_num = 0; round_num<5; round_num++)
    {
        player_current_movement = player_move[round_num];
        xiangyu_current_movement = xiangyu_move[round_num];

        Behavior* playerBehavior = MoveConvert(player_current_movement, player.GetPlayerInfo(),charactorinfo,availablemovement);
        Behavior* xiangyuBehavior = MoveConvert(xiangyu_current_movement,player.GetPlayerInfo(),charactorinfo,availablemovement);
        
        player.setBehavior(playerBehavior);
        double player_deal = player.performBehavior(xiangyuBehavior,xiangyu.GetDamage());
        xiangyu.SetHp(xiangyu.GetHp() - player_deal);

        xiangyu.setBehavior(xiangyuBehavior);
        double xiangyu_deal = xiangyu.performBehavior(playerBehavior,player.GetDamage());
        player.SetHp(player.GetHp() - xiangyu_deal);

        //결과 보고
        std::cout << "Round " << round_num+1 << ") " << "Player : " << player.GetHp() << " " << "Xiang-yu : " << xiangyu.GetHp() << std::endl;
        
        //종료조건
        if (player.GetHp() == 0 || xiangyu.GetHp() == 0)
        {
            if (player.GetHp() == 0 && xiangyu.GetHp() == 0)
            {
                std::cout << "Draw" << std::endl;
            }
            else if (player.GetHp() == 0)
            {
                std::cout << "Defeat" << std::endl;
            }
            else if (xiangyu.GetHp() == 0)
            {
                std::cout << "Victory" << std::endl;
            }
            hasty_result = true;
            break;
        }
        // Defend vs CounterAttack 시 다음 라운드의 행동 변경
        if (round_num <4)    
            if (static_cast<AvailableMovement>(player_current_movement) == AvailableMovement::DEFEND && 
            static_cast<AvailableMovement>(player_current_movement) == AvailableMovement::COUNTERATTACK)
            {
                xiangyu_move.erase(xiangyu_move.begin()+round_num+1);
                xiangyu_move.insert(xiangyu_move.begin()+round_num+1,(int)AvailableMovement::DONOTHING); 
            }

            if (static_cast<AvailableMovement>(player_current_movement) == AvailableMovement::COUNTERATTACK &&
            static_cast<AvailableMovement>(player_current_movement) == AvailableMovement::DEFEND)
            {
                player_move.erase(player_move.begin()+round_num+1);
                player_move.insert(player_move.begin()+round_num+1,(int)AvailableMovement::DONOTHING);
            }
    
    }
    // 승패가 결정되지 않았다면, 체력이 많은쪽이 승리
    if (hasty_result == false)
        if (player.GetHp() > xiangyu.GetHp())
            std::cout << "Victory : Player!" << std::endl;
        
        else if (player.GetHp() < xiangyu.GetHp())
            std::cout << "Victory : Xiang-Yu!" << std::endl;
    
        else if (player.GetHp() == xiangyu.GetHp())
            std::cout << "Victory : Draw!" << std::endl;


    return 0;
}