#include<iostream>
#include<utility>
#include<map>
using namespace std;
int main ()
{
map<int,int>m;
m.insert(pair<int,int>(101,26337));
m.insert(pair<int,int>(102,267));
m.insert(pair<int,int>(103,337));
m.insert(pair<int,int>(104,27));
m.insert(pair<int,int>(105,37));
map<int,int>::iterator i;
for(i=m.begin();i!=m.end();++i)
{
cout<<(*i).first<<","<<i->second<<endl;
}
return 0;
}
