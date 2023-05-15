#include <iostream>
#include <vector>
#include <random>
#include "problem1_matrix.h"


int main()
{
    int m1_r, m1_c, m2_r, m2_c;

    std::cout<< "press row count for martix 1" << std::endl;
    std::cin >> m1_r; 
    std::cout<< "press columb count for martix 1" << std::endl;
    std::cin >> m1_c;   
    std::cout<< "press row count for martix 2" << std::endl;
    std::cin >> m2_r; 
    std::cout<< "press columb count for martix 2" << std::endl;
    std::cin >> m2_c;  
    Matrix matrix1(m1_r,m1_c);
    Matrix matrix2(m2_r,m2_c);
    // std::vector<std::vector<int>> m1{{1, 1, 1},{2,2,2},{3,3,3}};
    // std::vector<std::vector<int>> m2{{4, 4, 4},{5,5,5},{6,6,6}};
    // Matrix matrix1(3,3,m1);
    // Matrix matrix2(3,3,m2);
    matrix1.Display();
    matrix2.Display();
    try
    {
    Matrix a = matrix1.AddMatrices(matrix2);
    a.Display();
    } catch (std::string& s){
        std::cout << "Error : " << s << std:: endl; ////예외처리
    }
    try{
    Matrix b = matrix1.MultiplyMatrices(matrix2);
    b.Display();
    } catch (std::string& s){
        std::cout << "Error : " << s << std::endl; ////예외처리
    }
    
    return 0;
}  
