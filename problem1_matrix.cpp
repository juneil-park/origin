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
    ~Matrix();  //소멸자

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
