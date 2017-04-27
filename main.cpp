#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{
	double r;
	cin >> r;
	Circle c(r);//构造一个半径为r的圆
	cout << c.Area() << endl;
	system<"pause">;
	return 1;

}