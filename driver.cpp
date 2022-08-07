#include<iostream>
using namespace std;
#include"Array.h"
int main()
{
	
	
	Array<Array<Array<int>>> c;
	c.reSize(2);
	int val = 1;
	for (int i = 0; i < 2; i++)
	{
		c[i].reSize(4);
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j].reSize(4);
		}
	}
	for (int i = 0; i < c.getCapacity(); i++)
		for (int j = 0; j < c[i].getCapacity(); j++)
			for (int k = 0; k < c[i][j].getCapacity(); k++)
				c[i][j][k] = val++;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
				cout << c[i][j][k] << " ";
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}