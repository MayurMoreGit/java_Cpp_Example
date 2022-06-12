#include<stdio.h>
#include<string.h>
#include<ios>
#include<limits>
#include<fstream>
#include<iostream>
using namespace std;
class student
{
int rollnumber;
char name[21];
char gender;
public:
void setrollnumber(int rollnumber)
{
this->rollnumber=rollnumber;
}
int getrollnumber()
{
return this->rollnumber;
}
void setname(const char *name)
{
strcpy(this->name,name);
}
void getname(char  *name)
{
strcpy(name,this->name);
}
void setgender(char gender)
{
this->gender=gender;
}
char getgender()
{
return this->gender;
}
};
void addStudent()
{
cout<<"added module : "<<endl;
int rollnumber;
string name;
char gender;
cout<<"enter a rollnumber : ";
cin>>rollnumber;
cin.ignore(1000,'\n');
cout<<"enter a name : ";
getline(cin,name);
cout<<"enter a gender(M/F) : ";
cin>>gender;
student s;
s.setrollnumber(rollnumber);
s.setname(name.c_str());
s.setgender(gender);
ofstream f("student.eee",ios::app|ios::binary);
f.write ((char *) &s,sizeof(student));
f.close();
}
void displayListOfStudent()
{
cout<<"display List of student : "<<endl;
student s;
int rollnumber;
char name;
char gender;
ifstream f("student.eee");
if(f.fail())
{
cout<<"student not added : "<<endl;
}
while(1)
{
f.read ((char *)&s,sizeof(student));
if(f.fail()) break;
cout<<"rollnumber"<<s.getrollnumber()<<endl;
char name[21];
s.getname(name);
cout<<"name"<<name<<endl;
cout<<"gender"<<s.getgender()<<endl;
}
f.close();
}
int main ()
{
int ch;
while(1)
{
cout<<"1.addStudent"<<endl;
cout<<"2.displayListOfStudent :"<<endl;
cout<<"3.exit :"<<endl;
cout<<"enter your choice : ";
cin>>ch;
if(ch==1) addStudent ();
if(ch==2) displayListOfStudent ();
if(ch==3) break;
}
return 0;
}