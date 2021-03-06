#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;
void scan();
void randomNumber();
void randomOperation();
double count(double x,double y,int sign);
double calculateResult(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3);
double generateExpression(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3,bool *ifgo,int a,bool *rewrite);
void print(int ifneed,bool ifstart,bool *ifgo,int a);
char sign(int a);
bool Chinese;int k=0;
string url="language.txt",strlanguage[10];
double random1,random2,random3,random4,answer;
int sign1,sign2,sign3,temp;
int main(){
int bingo_number=0,i=1,j=1;
char ifstart,language;
bool start=false,ifgo=true,rewrite=false;
string temp;
ifstream p;
p.open(url);
while(getline(p,temp))
{
	if(i==2||i==12||i==22||i==32||i==42)
		cout<<temp<<endl;
	i++;
}
p.close();
cin>>language;
if(language=='C')
	j=1;
else if(language=='E')
	j=11;
else if(language=='J')
	j=21;
else if(language=='A')
	j=31;
else j=41;
p.open(url);
i=1;
while(getline(p,url))
{
	if(i>=j+2&&i<j+9){
		strlanguage[k]=url;
		k++;
	}
	i++;
}
p.close();
k=0;
cout<<strlanguage[k]<<endl;
k=1;
cout<<strlanguage[k]<<endl;
cin>>ifstart;
if(ifstart=='Y'){
start=true;
}else {k=2;cout<<strlanguage[k]<<endl; }

if(start){
while(ifgo){
srand(time(0)); 
randomNumber();
randomOperation();
ifgo=false;
generateExpression(random1,random2,random3,random4,sign1,sign2,sign3,&ifgo,bingo_number,&rewrite);
if(ifgo==true)bingo_number++;
if(rewrite==true) {ifgo=true;rewrite=false;}
}
}
return 0;
}
double generateExpression(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3,bool *ifgo,int a,bool *rewrite){
bool ifinteger;
char ifstart;
double ifneed=calculateResult(random1,random2,random3,random4,sign1,sign2,sign3);
if(ifneed>10000||ifneed<0){*rewrite=true;return 0;}
temp=ifneed*1000;
if(sign1>3&&sign2<=3&&sign3<=3)
cout<<"("<<random1 <<sign(sign1) <<random2<<")"<<sign(sign2) <<random3 <<sign(sign3)<<random4<<"=?"<<endl;
else if(sign1>3&&sign2>3&&sign3<=3)
cout<<"("<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<random3 <<")"<<sign(sign3)<<random4<<"=?"<<endl;
else if(sign1>3&&sign2<=3&&sign3>3)
cout<<"("<<random1 <<sign(sign1) <<random2<<")" <<sign(sign2) <<"("<<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
else if(sign1<=3&&sign2>3&&sign3<=3)
cout<<random1 <<sign(sign1) <<"("<<random2 <<sign(sign2) <<random3<<")" <<sign(sign3)<<random4<<"=?"<<endl;
else if(sign1<=3&&sign2>3&&sign3>3)
cout<<random1 <<sign(sign1) <<"("<<random2 <<sign(sign2) <<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
else if(sign1<=3&&sign2<=3&&sign3>3)
cout<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<"("<<random3 <<sign(sign3)<<random4<<")"<<"=?"<<endl;
else
cout<<random1 <<sign(sign1) <<random2 <<sign(sign2) <<random3 <<sign(sign3)<<random4<<"=?"<<endl;
scan();
return 0;
}
char sign(int a){
char sign;
if(a==0)
return sign='+';
else if(a==1)
return sign='-';
else if(a==2)
return sign='*';
else if(a==3)
return sign='/';
else if(a==4)
return sign='+';
else if(a==5)
return sign='-';
return 0;
}
//计算方法。
double calculateResult(double random1,double random2,double random3,double random4,int sign1,int sign2,int sign3){
double count1,count2,count3,result;
if(sign1>3){count1=::count(random1,random2,sign1);
if(sign2>3){count2=::count(count1,random3,sign2);result=::count(count2,random4,sign3);}
else{if(sign3>3){result=::count(count1,::count(random3,random4,sign3),sign2);}
else{if(sign2>1){result=::count(::count(count1,random3,sign2),random4,sign3);}
else{if(sign3>1){result=::count(count1,::count(random3,random4,sign3),sign2);}
else{result=::count(::count(count1,random3,sign2),random4,sign3);}}}}
}else{if(sign2>3){count2=::count(random2,random3,sign2);
if(sign3>3){result=::count(random1,::count(count2,random4,sign3),sign1);}
else{if(sign1>1){result=::count(::count(random1,count2,sign1),random4,sign3);}
else{if(sign3>1){result=::count(random1,::count(count2,random4,sign3),sign1);}
else{result=::count(::count(random1,count2,sign1),random4,sign3);}}}
}else{if(sign3>3){count3=::count(random3,random4,sign3);
if(sign1>1){result=::count(::count(random1,random2,sign1),count3,sign2);}
else{if(sign2>1){result=::count(random1,::count(random2,count3,sign2),sign1);}
else{result=::count(::count(random1,random2,sign1),count3,sign2);}}
}else{
//无括号运算（大于三代表存在括号的运算）
if(sign1>1){
count1=::count(random1,random2,sign1);
if(sign2>1)result=::count(::count(count1,random3,sign2),random4,sign3);
else{
if(sign3>1) {
count3=::count(random3,random4,sign3);
result=::count(count1,count3,sign2);
}else {
result=::count(::count(count1,random3,sign2),random4,sign3);
}}
}else{
if(sign2>1){count2=::count(random2,random3,sign2);
if(sign3>1){
result=::count(random1,::count(count2,random4,sign3),sign1);}
else{result=::count(::count(random1,count2,sign1),random4,sign3);}}
else{if(sign3>1){count3=::count(random3,random4,sign3);result=::count(::count(random1,random2,sign1),count3,sign2);
}
else{count1=::count(random1,random2,sign1);result=::count(::count(count1,random3,sign2),random4,sign3);}}
}
}
}
}
return result;
}
double count(double x,double y,int sign){
switch (sign)
{
case 0:return x+y;
break;
case 1:return x-y;
break;
case 2:return x*y;
break;
case 3:return x/y;
break;
case 4:return x+y;//( + )
break;
case 5:return x-y;//( - )
break;
default:
break;
}
return 0;
}
void randomNumber(){
    random1=rand()%10;
    random2=rand()%10;
    random3=rand()%10;
    random4=rand()%10;
}
void randomOperation(){
	sign1=rand()%6;
    sign2=rand()%6;
    sign3=rand()%6;
}
void scan(){
if(temp%1000==0)cin>>answer;
else {double a,b;char c;
cin>>a;cin>>c;cin>>b;
answer=a/b;}
}
void print(int ifneed,bool ifstart,bool *ifgo,int a){
if(answer==ifneed) {k=3;
cout<<strlanguage[k]<<endl;
cin>>ifstart;
if(ifstart=='Y') {*ifgo=true;}
else{k=4;cout<<strlanguage[k]; cout<<"   **"<<a+1<<"**"<<endl;}
}else {k=5;cout<<strlanguage[k];cout<<"   **"<<ifneed<<"**"<<endl;
k++;cout<<strlanguage[k] ;  cout<<"   **"<<a<<"**"<<endl;
}
}


