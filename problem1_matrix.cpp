#include <iostream>
#include <vector>
#include <random>
class Matrix
{
private:
    int mColumb;
    int mRow;
    std::vector<std::vector<int>> mMat;

public:
    int GetNumberOfRow();
    int GetNumberOfColumn();
    void SetElement(int i, int j, int value);
    void Display();
    Matrix AddMatrices(Matrix B);
    Matrix MultiplyMatrices(Matrix B);
    Matrix(int i, int j); // vector를 주지 않으면 0~10사이에서 랜덤생성
    Matrix(int i, int j, std::vector<std::vector<int>>);

};


Matrix::Matrix(int i, int j) //vector를 주지 않으면 0~10사이에서 랜덤생성
: mRow(i), mColumb(j) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,10); //0~10에서 난수 생성
    std::vector<std::vector<int>> vec_2d(mRow, std::vector<int>(mColumb,0));

    for (int i =0; i< mRow; i++)
    {
        for (int j=0; j<mColumb; j++)
        {
            vec_2d[i][j] = dis(gen);
        }
    }
    mMat = vec_2d;
}

Matrix::Matrix(int i, int j, std::vector<std::vector<int>> mat) //생성자
: mRow(i), mColumb(j), mMat(mat){}

int Matrix::GetNumberOfColumn()
{
    return mColumb;
}

int Matrix::GetNumberOfRow()
{
    return mRow;
}

void Matrix::SetElement(int i, int j, int value)
{
    mMat[i][j] = value;
}

void Matrix::Display()
{
    for (int i=0; i< mRow; i++)
        {for (int j=0; j< mColumb; j++)
            {
                std::cout <<  mMat[i][j] << " ";
            }
            std::cout << "\n";
        }
}

Matrix Matrix::AddMatrices(Matrix B)
{
    if ((mRow == B.mRow) && (mColumb == B.mColumb))
    {
        std::vector<std::vector<int>> temp(mRow, std::vector<int>(mColumb,0));
        
        for (int i =0; i< mRow; i++)
        {
            for (int j=0; j<mColumb; j++)
            {
                temp[i][j] = mMat[i][j] + B.mMat[i][j];
            }
        }

        return Matrix(mRow,mColumb,temp);
        
    }
    std::cout << "Add error" << std::endl;
        
    return Matrix(mRow,mColumb,mMat); // 더 좋은 방법이 있을듯? 에러 났을때 리턴을 안주는 방법??
    
    
}


Matrix Matrix::MultiplyMatrices(Matrix B)
{
    if (mColumb == B.mRow)
    {
        std::vector<std::vector<int>> temp(mRow, std::vector<int>(mColumb,0));

        for (int i =0; i< mRow; i++)
        {
            for (int j=0; j<mColumb; j++)
            {
                // temp[i][j] = 0;
                for (int k=0 ; k<mColumb; k++)
                {
                    temp[i][j] += (mMat[i][k] *B.mMat[k][j]);
                } 
            }
        }

        return Matrix(mColumb,mRow,temp);
    }

    std::cout << "Multiply error" << std::endl;
        
    return Matrix(mRow,mColumb,mMat); // 더 좋은 방법이 있을듯?
}




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
    Matrix a = matrix1.AddMatrices(matrix2);
    a.Display();
    Matrix b = matrix1.MultiplyMatrices(matrix2);
    b.Display();
    return 0;
}  