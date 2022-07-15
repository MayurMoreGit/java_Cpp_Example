#include<stdio.h>
#include<map>
#include<utility>
#include<iostream>
using namespace std;
class student
{
int rollnumber;
string name;
public:
student ()
{
this->rollnumber=0;
this->name="";
}
student(int rollnumber,string name)
{
this->rollnumber=rollnumber;
this->name=name;
}
void setrollnumber(int rollnumber)
{
this->rollnumber=rollnumber;
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
class course
{
int rollnumber;
string title;
public:
course ()
{
this->rollnumber=0;
this->title=" ";
}
course(int rollnumber,string title)
{
this->rollnumber=rollnumber;
this->title=title;
}
void setrollnumber(int rollnumber)
{
this->rollnumber=rollnumber;
}
int getrollnumber()
{
return this->rollnumber;
}
void settitle(string title)
{
this->title=title;
}
string gettitle()
{
return this->title;
}
};
int main ()
{
student s1(101,"sameer");
student s2(102,"mayur");
student s3(103,"suresh");
student s4(104,"mohan");
student s5(105,"ritik");
student s6(106,"danish");
course c1(1,"c++");
course c2(2,"java");
course c3(3,"phyton");
course c4(4,"java scrpit");
map<int,student*>studentIndex;
studentIndex.insert(pair<int,student*>(101,&s1));
studentIndex.insert(pair<int,student*>(102,&s2));
studentIndex.insert(pair<int,student*>(103,&s3));
studentIndex.insert(pair<int,student*>(104,&s4));
studentIndex.insert(pair<int,student*>(105,&s5));
studentIndex.insert(pair<int,student*>(106,&s6));
map<student *,course *>studentcourse;
studentcourse.insert(pair<student *,course *>(&s1,&c1));
studentcourse.insert(pair<student *,course *>(&s2,&c1));
studentcourse.insert(pair<student *,course *>(&s3,&c2));
studentcourse.insert(pair<student *,course *>(&s4,&c3));
studentcourse.insert(pair<student *,course *>(&s5,&c4));
map<int,student *>::iterator si;
int rollnumber;
cout<<"enter  a rollnumber : ";
cin>>rollnumber;
student *s;
si=studentIndex.find(rollnumber);
if(si==studentIndex.end())
{
cout<<"name is not found : "<<endl;
return 0;
}
map<student *,course *>::iterator sci;
s=si->second;
sci=studentcourse.find(s);
if(sci==studentcourse.end())
{
cout<<"name"<<"("<<s->getname()<<")"<<endl<<"student not registerd for any course : "<<endl;
return 0;
}
course *c;
c=sci->second;
cout<<"name "<<"("<<s->getname()<<")"<<endl<<"student registerd for course"  <<"("<<c->gettitle()<<")"<<endl;
return 0;
}
