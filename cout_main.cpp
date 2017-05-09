#include "Cout.h";
int main(){
	int i = 0;
	srand(time(0));
	calculate c;
	c.readFile();
	c.scan();
	while (i<c.questionnum)
	{
		c.randomNumber();
		c.randomOperation();
		while (!c.generateExpression()) {
			c.randomNumber();
			c.randomOperation();
		}
		cin >> c.answer;
		c.judgeanswer();
		i++;
	}
	c.print();
	c.writeFile();
	return 0;
	system("pause");
}