#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<forward_list>
using namespace std;
class student 
{
private:
int rollnumber;
string name;
public:
student ()
{
this->rollnumber=0;
this->name=" ";
}
student(int rollnumber,string name)
{
this->rollnumber=rollnumber;
this->name=name;
}
student(const student &other)
{
this->rollnumber=other.rollnumber;
this->name=other.name;
}
student & operator=(const student &other)
{
this->rollnumber=other.rollnumber;
this->name=other.name;
return *this;
}
void setrollnumber()
{
this->rollnumber;
}
int getrollnumber()
{
return this->rollnumber;
}
void setname(string name)
{
this->name=name;
}
string getname()
{
return this->name;
}
};


class studentrollnumbercomparator
{
public:
int operator()(student *rollnumberleft,student *rollnumberright)
{
return rollnumberleft<rollnumberright;
}
};



int main ()
{
forward_list<student *>list;
forward_list<student *>::iterator i=list.before_begin ();
i=list.insert_after(i,new student(101,"mayur"));
i=list.insert_after(i,new student(102,"mahesh"));
i=list.insert_after(i,new student(103,"parth"));
i=list.insert_after(i,new student(104,"neelsh"));
i=list.insert_after(i,new student(105,"densh"));
i=list.insert_after(i,new student(106,"harshit"));
student *s;

cout<<"now storing"<<endl;
studentrollnumbercomparator comparator;
list.sort(comparator);
for(i=list.begin();i!=list.end();++i)
{
s=*i;
cout<<s->getrollnumber()<<","<<s->getname()<<endl;
}


//release to m,emory
for(i=list.begin();i!=list.end();++i)
{
s=*i;
delete s;
}
return 0;
}
