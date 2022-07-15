#include<list>
#include<iostream>
using namespace std;
int main ()
{
list<int>l1;
l1.push_back(10);
l1.push_back(20);
l1.push_back(30);
l1.push_back(40);
l1.push_back(50);
cout<<l1.front()<<endl;
cout<<l1.back()<<endl;
cout<<l1.size()<<endl;
cout<<"now iterating top to bottom : "<<endl;
list<int>::iterator tb=l1.begin();
while(tb!=l1.end())
{
cout<<*tb<<endl;
++tb;
}
cout<<"now iterating bottom to top : "<<endl;
list<int>::reverse_iterator bt=l1.rbegin();
while(bt!=l1.rend())
{
cout<<*bt<<endl;
++bt;
}
return 0;
}
