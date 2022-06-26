#include<iostream>
#include<forward_list>
using namespace std;
int main ()
{
forward_list<int > list={10,20,30,40,54,77,23,22,89,97,43,99,50};
list.sort();
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}
