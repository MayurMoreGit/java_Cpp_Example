#include<iostream>
#include<forward_list>
using namespace std;
int main ()
{
forward_list<int > list;
forward_list<int>::iterator i=list.begin();
i=list.insert_after(i,10);
i=list.insert_after(i,20);
i=list.insert_after(i,30);
i=list.insert_after(i,40);
i=list.insert_after(i,50);
i=list.insert_after(i,60);
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}
