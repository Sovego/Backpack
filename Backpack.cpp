#include <iostream>


int max(int number1, int number2) {
    if (number1 > number2) {
        return number1;
    } else return number2;
}
int main()
{
    int count;
    int max_weight;
    std::cout << "Input max weight ";
    std::cin >> max_weight;
    std::cout << "Input max count ";
    std::cin >> count;
    int** list=new int*[count+1];
    int* cost_list= new int[count+1];
    for (int i = 0; i < count+1; i++) list[i] = new int[max_weight+2];
    for (int i=0;i<count+1;i++)
    {
        for (int j=0;j<max_weight+2;j++)
        {
            list[i][j]=0;
        }
    }
    for (int i=2;i<max_weight+2;i++)
    {
        list[0][i]=i-1;
    }
    for (int i=1;i<count+1;i++)
    {
        int x;
        std::cout << "Input " << i << " weight ";
        std::cin >> x;
        list[i][0]=x;
        std::cout << "Input " << i << " cost ";
        std::cin >> x;
        cost_list[i]=x;
    }
    for (int i=2;i<count+1;i++)
    {
        for (int j=2;j<max_weight+2;j++)
        {
            if (j<list[i][0])
            {
                list[i][j]=list[i-1][j];
            } else if(j>=list[i][0])
            {
                list[i][j]=max(list[i-1][j],list[i-1][j-i]+cost_list[j]);
            }
        }

    }
    for (int i=0;i<count+1;i++)
    {
        for (int j=0;j<max_weight+2;j++)
        {
            std::cout <<list[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}
