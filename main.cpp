#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{
	double r;
	cin >> r;
	Circle c(r);//����һ���뾶Ϊr��Բ
	cout << c.Area() << endl;
	system<"pause">;
	return 1;

}