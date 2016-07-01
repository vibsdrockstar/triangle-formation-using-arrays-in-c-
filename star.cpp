#include<iostream>
using namespace std;
int main()
{
int i,j,rows,first=0,second=1,next,c;
cin>>rows;
for(i=1;i<=rows;++i)
{
first=0;
second = 1;
for(c=0;c<i;c++)
{
if(c<=1)
next=c;
else
{
next=first+second;
first= second;
second=next;
}
}

for(j=0;j<next;++j)
{ 

cout<<"*";

}
cout<<endl;
}
return 0;
}

