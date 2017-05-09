#pragma once
#ifndef COUNT_H
#define COUNT_H
using namespace std;
#include<iostream>
#include<ctime>
#include <sstream>
#include<fstream>
#include<string>
class calculate {
public:
	calculate();
	ofstream out;
	double random1, random2, random3, random4, answer;
	double rightresult;
	int sign1, sign2, sign3, temp, rightnum, si;
	string url, in_url, outfile, s[300];
	int language;
	void readFile();//读取用户要求的题目数量(请注意参数设置)
	void scan();//该函数用于与用户交互，获取输入数据
	void randomNumber();//用于随机生成数字
	void randomOperation();//用于随机生成运算符
	bool generateExpression();//用于生成运算式
	double calculateResult();//用于计算生成的运算式的结果
	void judgeanswer();//用于判断用户答题是否正确
	void writeFile();//将最终结果写入文件，写入内容包括：用户输入的题目数，每个生成的表达式、正确答案、用户输入的答案，保存到命令行中第二个参数指定的路径。(请注意参数设置)
	void print();//将统计结果输出给用户
	char sign(int a);
	int questionnum;
};
#endif