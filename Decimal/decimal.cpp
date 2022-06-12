#include<iostream>
#include<stack>
using namespace std;
char tochar(int d)
{
return d+48;
}
int todigit(char d)
{
return d-48;
}
int main ()
{
char a[21];
char b[21];
char c[24];
cout<<"enter  a first element : ";
cin>>a;
cout<<"enter a second element  :";
cin>>b;
int fi,si;
for(fi=0;a[fi]!='\0';fi++);
fi--;
for(si=0;b[si]!='\0';si++);
si--;
int carry=0;
stack<int>stk;
int sum,m;
int left,right;
while(fi>=0 &&si>=0)
{
left=todigit(a[fi]);
right=todigit(b[si]);
sum=carry+left+right;
m=sum%10;
carry=sum/10;
stk.push(m);
fi--;
si--;
}
while(fi>=0)
{
left=todigit(a[fi]);
sum=carry+left;
m=sum%10;
carry=sum/10;
stk.push(m);
fi--;
}
while(si>=0)
{
right=todigit(b[si]);
sum=carry+right;
m=sum%10;
carry=sum/10;
stk.push(m);
si--;
}
if(carry>0) stk.push(carry);
int ti;
ti=0;
while(!stk.empty())
{
c[ti]=tochar(stk.top());
stk.pop();
ti--;
}
c[ti]='\0';
cout<<a<<"   is  "<<b<<"   and   "<<c<<endl;
return 0;
}