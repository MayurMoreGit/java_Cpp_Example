#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class TmString
{
private:
int size;
char *ptr;
public:
TmString();
TmString(const char *ptr);
TmString &operator =(const TmString &other);
TmString &operator =(const char *ptr);
~ TmString();
int operator<(const TmString &other);
int operator<=(const TmString &other);
int operator>(const TmString &other);
int operator>=(const TmString &other);
int operator==(const TmString &other);
int operator!=(const TmString &other);
void operator +=(const TmString &other);
TmString operator +(const TmString &other);
friend ostream & operator<<(ostream &out,TmString &tmString);
};  
TmString ::TmString()
{
this->ptr=NULL;
this->size=0;
}
TmString ::TmString(const char *ptr)
{
this->ptr==NULL;
if(ptr==NULL) return;
this->size=strlen(ptr);
this->ptr=new char(this->size+1);
strcpy(this->ptr,ptr);
}
TmString &TmString ::operator =(const TmString &other)
{
if(this->ptr) delete[]this->ptr;
this->ptr==NULL;
this->size=0;
if(other.ptr==NULL) return *this;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);
return * this;
}
TmString &TmString ::operator =(const char *ptr)
{
if(this->ptr) delete[]this->ptr;
this->ptr==NULL;
this->size=0;
if(ptr==NULL) return *this;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return * this;
}
TmString ::~ TmString()
{
if(this->ptr) delete[] this->ptr;
}
ostream & operator<<(ostream &out,TmString &tmString)
{
if(tmString.ptr==NULL) return out;
out<<tmString.ptr;
return out;
}
int TmString ::operator<(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<0;
}
int TmString :: operator<=(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<=0;
}
int TmString :: operator>(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>0;
}
int TmString :: operator>=(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>=0;
}
int TmString :: operator==(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)==0;
}
int TmString :: operator!=(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)!=0;
}
void TmString :: operator +=(const TmString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return;
if(other.ptr==NULL) return;
if(this->ptr==NULL) 
{
*this=other;
return;
}
char *tmp=new char(this->size+other.size+1);
strcpy(tmp,this->ptr);
strcat(tmp,other.ptr);
this->ptr=tmp;
this->size=(this->size+other.size+1);
}
TmString TmString ::operator +(const TmString &other)
{
TmString k;
if(this->ptr==NULL && other.ptr==NULL) return k;
if(this->ptr==NULL) k=(*this);
else if(other.ptr==NULL) k=other;
else
{
k=(*this);
k+=other;
}
return k;
}
int main ()
{
int e,f,m,y;
TmString x[5];
x[0]="mayur";
x[1]="naveen";
x[2]="danish";
x[3]="more";
x[4]="gunu";
TmString g;
m=3;
while(m>=0)
{
e=0;
f=e+1;
while(e<=m)
{
if(x[f]<=x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
for(y=0;y<=4;y++)
{
cout<<x[y]<<endl;
}
return 0;
}

