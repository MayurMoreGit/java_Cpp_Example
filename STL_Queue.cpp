#include<queue>
#include<iostream>
using namespace std;
int main ()
{
priority_queue<int>g;
g.push(10);
g.push(20);
g.push(30);
g.push(410);
g.push(50);
cout<<g.top()<<endl;
cout<<g.size()<<endl;
cout<<"***********"<<endl;
while(!g.empty())
{
cout<<g.top()<<endl;
g.pop();
}
return 0;
}
