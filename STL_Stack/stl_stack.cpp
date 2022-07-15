#include<stack>
#include<iostream>
using namespace std;
int main ()
{
stack<int>s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
cout<<s.top()<<endl;
s.pop();
cout<<s.size()<<endl;
cout<<"********"<<endl;
while(!s.empty())
{
cout<<s.top()<<endl;
s.pop();
}
return 0;
}
