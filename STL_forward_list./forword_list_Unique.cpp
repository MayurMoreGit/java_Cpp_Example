#include<iostream>
#include<forward_list>
using namespace std;
int main ()
{
forward_list<int > list={10,13,13,13,14,152,12,34,55,43,67,6,13,15};
  list.unique();
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}
