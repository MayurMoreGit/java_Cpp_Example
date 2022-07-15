#include<iostream>
#include<utility>
#include<map>
using namespace std;
int main ()
{
map<int,int>m;
m[101]=74648;
m[102]=748;
m[103]=74248;
m[104]=744648;
m[105]=648;
m[106]=48;
map<int,int>::iterator i;
m.erase(103);
m.erase(102);
m.erase(104);
m.erase(105);
for(i=m.begin();i!=m.end();++i)
{
cout<<i->first<<","<<i->second<<endl;
}
return 0;
}
