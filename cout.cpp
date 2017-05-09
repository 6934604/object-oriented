using namespace std;
#include "Cout.h";
double qcount(double x, double y, int sign);
calculate::calculate() {
	rightnum = 0;
	si = 0;
	url = "language.txt";
	in_url = "in.txt";
	outfile = "out.txt";
}
void calculate::readFile() {
	int i = 1;
	string temp, t;
	char te[10];
	ifstream p;
	p.open(in_url);
	getline(p, temp);
	stringstream ss;
	ss << temp;
	ss >> questionnum;

}
void calculate::scan() {
	int i = 0;
	string temp, t;
	char te[10];
	ifstream p;
	p.open(url);
	while (getline(p, temp))
	{
		if (i<6)
		{
			cout << temp << endl;
			s[si] = temp;si++;
		}
		i++;
	}
	cin >> language;
	sprintf_s(te, "%d", language);t = te;
	s[si] = t;si++;
}

void calculate::randomNumber() {
	random1 = rand() % 10;
	random2 = rand() % 10;
	random3 = rand() % 10;
	random4 = rand() % 10;
}
void calculate::randomOperation() {
	sign1 = rand() % 6;
	sign2 = rand() % 6;
	sign3 = rand() % 6;
}

bool calculate::generateExpression() {
	rightresult = calculateResult();
	while (rightresult>10000 || rightresult<0) {
		return false;
	}
	char rm1[10], rm2[10], rm3[10], rm4[10];
	string r1, r2, r3, r4, stemp;
	sprintf_s(rm1, "%.0lf", random1);sprintf_s(rm2, "%.0lf", random2);sprintf_s(rm3, "%.0lf", random3);sprintf_s(rm4, "%.0lf", random4);
	r1 = rm1;r2 = rm2;r3 = rm3;r4 = rm4;
	if (sign1>3 && sign2 <= 3 && sign3 <= 3) {
		cout << "(" << random1 << sign(sign1) << random2 << ")" << sign(sign2) << random3 << sign(sign3) << random4 << "=?" << endl;
		stemp = "(" + r1 + sign(sign1) + r2 + ")" + sign(sign2) + r3 + sign(sign3) + r4 + "=?";
		s[si] = stemp;si++;
	}
	else if (sign1>3 && sign2>3 && sign3 <= 3) {
		cout << "(" << random1 << sign(sign1) << random2 << sign(sign2) << random3 << ")" << sign(sign3) << random4 << "=?" << endl;
		stemp = "(" + r1 + sign(sign1) + r2 + sign(sign2) + r3 + ")" + sign(sign3) + r4 + "=?";
		s[si] = stemp;si++;
	}
	else if (sign1>3 && sign2 <= 3 && sign3>3) {
		cout << "(" << random1 << sign(sign1) << random2 << ")" << sign(sign2) << "(" << random3 << sign(sign3) << random4 << ")" << "=?" << endl;
		stemp = "(" + r1 + sign(sign1) + r2 + ")" + sign(sign2) + "(" + r3 + sign(sign3) + r4 + ")" + "=?";
		s[si] = stemp;si++;
	}
	else if (sign1 <= 3 && sign2>3 && sign3 <= 3) {
		cout << random1 << sign(sign1) << "(" << random2 << sign(sign2) << random3 << ")" << sign(sign3) << random4 << "=?" << endl;
		stemp = r1 + sign(sign1) + "(" + r2 + sign(sign2) + r3 + ")" + sign(sign3) + r4 + "=?";
		s[si] = stemp;si++;
	}
	else if (sign1 <= 3 && sign2>3 && sign3>3) {
		cout << random1 << sign(sign1) << "(" << random2 << sign(sign2) << random3 << sign(sign3) << random4 << ")" << "=?" << endl;
		stemp = r1 + sign(sign1) + "(" + r2 + sign(sign2) + r3 + sign(sign3) + r4 + ")" + "=?";
		s[si] = stemp;si++;
	}
	else if (sign1 <= 3 && sign2 <= 3 && sign3>3) {
		cout << random1 << sign(sign1) << random2 << sign(sign2) << "(" << random3 << sign(sign3) << random4 << ")" << "=?" << endl;
		stemp = r1 + sign(sign1) + r2 + sign(sign2) + "(" + r3 + sign(sign3) + r4 + ")" + "=?";
		s[si] = stemp;si++;
	}
	else {
		cout << random1 << sign(sign1) << random2 << sign(sign2) << random3 << sign(sign3) << random4 << "=?" << endl;
		stemp = r1 + sign(sign1) + r2 + sign(sign2) + r3 + sign(sign3) + r4 + "=?";
		s[si] = stemp;si++;
	}
	return true;
}
char calculate::sign(int a) {
	char sign;
	if (a == 0)
		return sign = '+';
	else if (a == 1)
		return sign = '-';
	else if (a == 2)
		return sign = '*';
	else if (a == 3)
		return sign = '/';
	else if (a == 4)
		return sign = '+';
	else if (a == 5)
		return sign = '-';
	return 0;
}
double calculate::calculateResult() {
	double count1, count2, count3, result;
	if (sign1>3) {
		count1 = qcount(random1, random2, sign1);
		if (sign2>3) { count2 = qcount(count1, random3, sign2);result = qcount(count2, random4, sign3); }
		else {
			if (sign3>3) { result = qcount(count1, qcount(random3, random4, sign3), sign2); }
			else {
				if (sign2>1) { result = qcount(qcount(count1, random3, sign2), random4, sign3); }
				else {
					if (sign3>1) { result = qcount(count1, qcount(random3, random4, sign3), sign2); }
					else { result = qcount(qcount(count1, random3, sign2), random4, sign3); }
				}
			}
		}
	}
	else {
		if (sign2>3) {
			count2 = qcount(random2, random3, sign2);
			if (sign3>3) { result = qcount(random1, qcount(count2, random4, sign3), sign1); }
			else {
				if (sign1>1) { result = qcount(qcount(random1, count2, sign1), random4, sign3); }
				else {
					if (sign3>1) { result = qcount(random1, qcount(count2, random4, sign3), sign1); }
					else { result = qcount(qcount(random1, count2, sign1), random4, sign3); }
				}
			}
		}
		else {
			if (sign3>3) {
				count3 = qcount(random3, random4, sign3);
				if (sign1>1) { result = qcount(qcount(random1, random2, sign1), count3, sign2); }
				else {
					if (sign2>1) { result = qcount(random1, qcount(random2, count3, sign2), sign1); }
					else { result = qcount(qcount(random1, random2, sign1), count3, sign2); }
				}
			}
			else {
				//无括号运算（大于三代表存在括号的运算）
				if (sign1>1) {
					count1 = qcount(random1, random2, sign1);
					if (sign2>1)result = qcount(qcount(count1, random3, sign2), random4, sign3);
					else {
						if (sign3>1) {
							count3 = qcount(random3, random4, sign3);
							result = qcount(count1, count3, sign2);
						}
						else {
							result = qcount(qcount(count1, random3, sign2), random4, sign3);
						}
					}
				}
				else {
					if (sign2>1) {
						count2 = qcount(random2, random3, sign2);
						if (sign3>1) {
							result = qcount(random1, qcount(count2, random4, sign3), sign1);
						}
						else { result = qcount(qcount(random1, count2, sign1), random4, sign3); }
					}
					else {
						if (sign3>1) {
							count3 = qcount(random3, random4, sign3);result = qcount(qcount(random1, random2, sign1), count3, sign2);
						}
						else { count1 = qcount(random1, random2, sign1);result = qcount(qcount(count1, random3, sign2), random4, sign3); }
					}
				}
			}
		}
	}
	return result;
}
double qcount(double x, double y, int sign) {
	switch (sign)
	{
	case 0:return x + y;
		break;
	case 1:return x - y;
		break;
	case 2:return x*y;
		break;
	case 3:return x / y;
		break;
	case 4:return x + y;//( + )
		break;
	case 5:return x - y;//( - )
		break;
	default:
		break;
	}
	return 0;
}
void calculate::judgeanswer() {
	int i = 1;
	string temp, t;
	char te[10];
	sprintf_s(te, "%.0lf", answer);
	t = te;
	s[si] = t;si++;
	sprintf_s(te, "%.3lf", rightresult);
	t = te;
	ifstream p;
	p.open(url);
	if (answer == rightresult) {
		rightnum++;
		while (getline(p, temp))
		{
			if (i == 9 + 5 * (language - 1))
			{
				cout << temp << endl;
				s[si] = temp;si++;
			}
			i++;
		}
	}
	else {
		while (getline(p, temp))
		{
			if (i == 10 + 5 * (language - 1))
			{
				temp += t;
				cout << temp << endl;
				s[si] = temp;si++;
			}
			i++;
		}
	}

}
void calculate::writeFile() {
	int i;
	ofstream out(outfile);
	for (i = 0;i<si;i++)
		out << s[i] << endl;
}
void calculate::print() {
	int i = 1;
	string temp, t;
	char te[10];
	sprintf_s(te, "%d", rightnum);t = te;
	ifstream p;
	p.open(url);

	while (getline(p, temp))
	{
		if (i == 11 + 5 * (language - 1))
		{
			temp += t;
			cout << temp << endl;
			s[si] = temp;si++;
		}
		i++;
	}

}