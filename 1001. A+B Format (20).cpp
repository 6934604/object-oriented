#include<iostream>
using namespace std;
int main()
{
  int sum,i,t=1,x,y,a[10],ifpositive=1;
  cin>>x;cin>>y;
  sum=x+y;
  if(sum<0){ifpositive=0;sum=sum*(-1);}
  for(i=0;sum/t>0;i++)
    t=t*10;
  for(t=0;t<i;t++)
  {
    a[t]=sum%10;
    sum=sum/10;
  }
  if(ifpositive==0) cout<<"-";
  if(i==0) cout<<"0";
  else
    for(i=i-1;i>=0;i--){
      cout<<a[i];
      if(i!=0&&i%3==0) cout<<",";
    }
  printf("\n");
  return 0;
}

