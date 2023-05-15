#pragma once
#include <iostream>
#include <vector>
#include <random>

class Matrix
{
public:
    Matrix(int i, int j); // vector를 주지 않으면 0~10사이에서 랜덤생성
    Matrix(int i, int j, std::vector<std::vector<int>>); // contructor 는 가장 위에 사용

    int GetNumberOfRow();
    int GetNumberOfColumn();
    void SetElement(int i, int j, int value);
    void Display();
    Matrix AddMatrices(Matrix B);
    Matrix MultiplyMatrices(Matrix B);
    ~Matrix() {};  //소멸자

    std::vector<std::vector<int>> GetMatrix()
    {
        return Mat_;
    }


private: // private 변수는 뒤에 언더바 _ 
    int Columb_;
    int Row_;
    std::vector<std::vector<int>> Mat_;


};


Matrix::Matrix(int i, int j) //vector를 주지 않으면 0~10사이에서 랜덤생성
: Row_(i), Columb_(j) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,10); //0~10에서 난수 생성
    std::vector<std::vector<int>> vec_2d(Row_, std::vector<int>(Columb_,0));

    for (int i =0; i< Row_; i++)
    {
        for (int j=0; j<Columb_; j++)
        {
            vec_2d[i][j] = dis(gen);
        }
    }
    Mat_ = vec_2d;
}

Matrix::Matrix(int i, int j, std::vector<std::vector<int>> mat) //생성자
: Row_(i), Columb_(j), Mat_(mat){} // initialization

int Matrix::GetNumberOfColumn()
{
    return Columb_;
}

int Matrix::GetNumberOfRow()
{
    return Row_;
}

void Matrix::SetElement(int i, int j, int value)
{
    Mat_[i][j] = value;
}

void Matrix::Display()
{
    for (int i=0; i< Row_; i++)
        {for (int j=0; j< Columb_; j++)
            {
                std::cout <<  Mat_[i][j] << " ";
            }
            std::cout << "\n";
        }
}

Matrix Matrix::AddMatrices(Matrix B)
{
    if ((Row_ == B.Row_) && (Columb_ == B.Columb_))
    {
        std::vector<std::vector<int>> temp(Row_, std::vector<int>(Columb_,0));
        
        for (int i =0; i< Row_; i++)
        {
            for (int j=0; j<Columb_; j++)
            {
                temp[i][j] = Mat_[i][j] + B.Mat_[i][j];
            }
        }

        return Matrix(Row_,Columb_,temp);
        
    }

    throw std::string("Add error. 두 행렬의 차원이 덧셈연산에 적합하지 않습니다."); //예외처리
    
}


Matrix Matrix::MultiplyMatrices(Matrix B)
{
    if (Columb_ == B.Row_)
    {
        std::vector<std::vector<int>> temp(Row_, std::vector<int>(B.Columb_,0));

        for (int i =0; i< Row_; i++)
        {
            for (int j=0; j<B.Columb_; j++)
            {
                // temp[i][j] = 0;
                for (int k=0 ; k<Columb_; k++)
                {
                    temp[i][j] += (Mat_[i][k] *B.Mat_[k][j]);
                } 
            }
        }

        return Matrix(Row_,B.Columb_,temp);
    }

    throw std::string("Multiply Error. 두 행렬의 차원이 곱셈연산에 적합하지 않습니다."); ////예외처리
}