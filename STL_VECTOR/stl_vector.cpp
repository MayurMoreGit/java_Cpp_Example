#include<iostream>
#include<vector>
using namespace std;
int main ()
{
vector<int>g;
g.push_back(10);
g.push_back(20);
g.push_back(30);
g.push_back(40);
g.push_back(50);
cout<<g.front()<<endl;
cout<<g.size()<<endl;
cout<<g.empty()<<endl;
cout<<"***************"<<endl;
for(vector<int>::iterator i=g.begin();i!=g.end();++i) cout<<*i<<endl;
cout<<"***********"<<endl;
for(vector<int>::reverse_iterator i=g.rbegin();i!=g.rend();++i) cout<<*i<<endl;

return 0;
}
