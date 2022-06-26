#include<iostream>
#include<forward_list>
using namespace std;
int main ()
{
forward_list<int > list={10,20,30,40,50};
list.remove(30);
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}
