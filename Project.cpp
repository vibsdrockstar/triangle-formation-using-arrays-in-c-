#include<iostream>


using namespace std;

int main()
{
int edge[1000][2];
int noofedges=0;
int x[100],y[100];
int triangle[1000][3];
int nooftriangles=0;

bool intersecting =false;
int n;
cin>>n;
int temp;
float flag;
for(int i=0;i<n;i++)
{
cin>>x[i];
cin>>y[i];
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1;j++)
{
//sorting for x coordinates
if(x[j+1]<x[j])
{
temp=x[j];
x[j]=x[j+1];
x[j+1]=temp;

temp=y[j];
y[j]=y[j+1];
y[j+1]=temp;
}
}
}
//after sorting
/*for(int i=0;i<n;i++)
{
cout<<x[i]<<y[i]<<endl;
}*/
for(int i=0;i<n;i++)
{
//cout<<"Entered value of i="<<i<<endl;
for(int j=0;j<i;j++)
{
//cout<<"Entered value of j="<<j<<endl;
intersecting=false;
for(int k=0;k<noofedges;k++)
{
//cout<<"Entered value of k="<<k<<endl;
int m=edge[k][0];
int n=edge[k][1];

float x1 = x[i];
float y1=y[i];
float x2 = x[j];
float y2=y[j];
float x3=x[m];
float y3=y[m];
float x4=x[n];
float y4= y[n];
float deltax=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
float deltay=(x1-x2)*(y4-y2)-(y1-y2)*(x4-x2);
float delta=(x1-x2)*(y4-y3)-(x4-x3)*(y1-y2);

if(delta==0)
{
if(deltax==0&&deltay==0)
{
intersecting =true;
}
}
else
{
float flag1=deltax/delta;
float flag2=deltay/delta;
//cout<<flag1<<flag2<<endl;


if(m!=i&&m!=j&&n!=i&&n!=j&& flag1>=0&&flag1<=1&&flag2>=0&&flag2<=1)
{
intersecting=true;
//if(i==2&&j==1&&intersecting==true)
//cout<<"The value of k"<<"="<<k<<endl;

}
}
}
if(intersecting==false)

 {
edge[noofedges][0]=i;
edge[noofedges][1]=j;
noofedges++;
cout<<noofedges<<endl;

//cout<<flag1<<flag2<<endl;

}
}
}

for(int i=0;i<noofedges;i++)
{
cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
}
for(int i=0;i<n;i++)
{
for(int j=0;j<i;j++)
{
for(int k=0;k<j;k++)
{
bool e1=false;
bool e2=false;
bool e3=false;
for(int l=0;l<noofedges;l++)
{
if(edge[l][0]==i && edge[l][1]==j)
{
e1=true;
}
else if(edge[l][0]==i && edge[l][1]==k)
{
e2=true;
}
else if(edge[l][0]==j&&edge[l][1]==k)
{
e3=true;
}
}
if(e1&&e2&&e3)
{
cout<<i<<" "<<j<<" "<<k<<endl;
triangle[nooftriangles][0]=k;
triangle[nooftriangles][1]=j;
triangle[nooftriangles][2]=k;
}
}
}
} 


return 0;

}

