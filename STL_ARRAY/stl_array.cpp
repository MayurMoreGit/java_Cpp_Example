#include<array>
#include<iostream>
using namespace std;
int main ()
{
array<int,10>g;
g[0]=10;
g[1]=20;
g[2]=30;
for(int e=0;e<g.size();e++) cout<<g[e]<<endl;
for(array<int,10>::iterator i=g.begin();i!=g.end();++i) cout<<*i<<endl;
g.fill(0);
for(array<int,10>::iterator i=g.begin();i!=g.end();++i) cout<<*i<<endl;
for(array<int,10>::reverse_iterator i=g.rbegin();i!=g.rend();++i) cout<<*i<<endl;
g[0]=10;
g[1]=100;
g[2]=10000;
for(array<int,10>::iterator i=g.begin();i!=g.end();++i) cout<<*i<<endl;
return 0;
}
