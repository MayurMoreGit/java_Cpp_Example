#include<iostream>
#include<limits>
#include<fstream>
#include<ios>
#include<string.h>
using namespace std;
void addStudent()
{
int rollnumber;
string name;
char gender;
cout<<"enter a rollnumber :" ;
cin>>rollnumber;
cin.ignore(numeric_limits<streamsize>::max (),'\n');
cout<<"enter a name : ";
getline(cin,name);
cout<<"enter a gender (M/F) : ";
cin>>gender;
ofstream f("filename.data",ios:: app);
f<<rollnumber;
f<<" ";
f<<name;
f<<'\n';
f<<gender;
f.close();
cout<<"student added "<<endl;
}
void displayListOfStudent()
{
int rollnumber;
string name;
char gender;
ifstream f("filename.data");
if(f.fail())
{
cout<<"student not added"<<endl;
return;
}
while(1)
{
f>>rollnumber;
if(f.fail()) break;
f>>name;
f>>gender;
cout<<"rollnumber : "<<rollnumber<<  "name : "<<name  <<  "gender :"<<gender  <<endl;
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
