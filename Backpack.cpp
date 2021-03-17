
// ReSharper disable All
#include <iostream>
#include <ctime>
struct thinks
{
	int weight;
	int price;
	double coefficient;
};
void init_struct(thinks st[],const int count)
{
	for (int i=0;i<count;i++)
	{
		st[i].price=1+rand()% 100;
		st[i].weight=1+rand()%9;
		st[i].coefficient=st[i].weight/st[i].price;
	}
}
int main()
{
    srand((unsigned)time(NULL));
    std::cout << "Input max weight ";
	std::cout << "Input count of items";
	int i;
    std::cin >> i;
   
    thinks *st=new thinks[i];
	init_struct(st,i);
	
}


