#include<iostream>
#include<forward_list>
using namespace std;
int main ()
{
forward_list<int > list;
list.push_front(10);
list.push_front(20);
list.push_front(30);
list.push_front(40);
list.push_front(50);
list.push_front(60);
list.pop_front();
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}
