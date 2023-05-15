#include <gtest/gtest.h>
#include "myfunctions.h"
#include "problem1_matrix.h"
#include <vector>
#include <random>
#include <iostream>

//EXPECT_ macros generate nonfatal failures and allow the current function to continue running, while ASSERT_ macros generate fatal failures and abort the current function.

TEST(GetNumberOfRowTest, Matrix)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,5); //1~10에서 난수 생성
    std::uniform_int_distribution<int> dis2(0,5);

    for(int i=1; i<20; i++)
    {
        int rownum = dis(gen);
        int colnum = dis2(gen);
        Matrix Mat = Matrix(rownum,colnum);
        EXPECT_EQ(Mat.GetNumberOfRow(), rownum);
    }
}


TEST(AddMatricesTest, Matrix)
{
    Matrix Mat1 = Matrix(3,3,std::vector<std::vector<int>>{{1,2,3},{2,4,6},{3,6,9}});
    Matrix Mat2 = Matrix(3,3,std::vector<std::vector<int>>{{3,6,9},{2,4,6},{1,2,3}});
    Matrix Mat_test = Mat1.AddMatrices(Mat2);
    Matrix Mat_control = Matrix(3,3,std::vector<std::vector<int>>{{4,8,12},{4,8,12},{4,8,12}});
    EXPECT_EQ(Mat_test.GetMatrix(), Mat_control.GetMatrix());
    EXPECT_EQ(Mat_test.GetMatrix(), (std::vector<std::vector<int>>{{4,8,12},{4,8,12},{4,8,12}}));
    EXPECT_NE(Mat_test.GetMatrix(), (std::vector<std::vector<int>>{{0,0,0},{0,0,0},{0,0,0}}));
}



TEST(MultiplyMatricesTest, Matrix)
{
    Matrix Mat1 = Matrix(3,3,std::vector<std::vector<int>>{{1,2,3},{2,4,6},{3,6,9}});
    Matrix Mat2 = Matrix(3,3,std::vector<std::vector<int>>{{3,6,9},{2,4,6},{1,2,3}});
    Matrix Mat_test = Mat1.MultiplyMatrices(Mat2);
    Matrix Mat_control = Matrix(3,3,std::vector<std::vector<int>>{{10,20,30},{20,40,60},{30,60,90}});
    EXPECT_EQ(Mat_test.GetMatrix(), Mat_control.GetMatrix());
    EXPECT_EQ(Mat_test.GetMatrix(), (std::vector<std::vector<int>>{{10,20,30},{20,40,60},{30,60,90}}));
    EXPECT_NE(Mat_test.GetMatrix(), (std::vector<std::vector<int>>{{0,0,0},{0,0,0},{0,0,0}}));
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}