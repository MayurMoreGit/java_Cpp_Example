#include<iostream>
#define true 1
#define True 1
#define TRUE 1
#define FALSE 0
#define false 0
#define False 0
#define FASLE 0
#define bool int
using namespace std;
class Iterator
{
private:
int releaseIteratorAfterIteration;
Iterator *iterator;
public:
Iterator()
{
this->releaseIteratorAfterIteration=1;
this->iterator=NULL;
}
Iterator(Iterator *iterator)
{
this->releaseIteratorAfterIteration=1;
this->iterator=iterator;
}
Iterator(const Iterator &other)
{
this->releaseIteratorAfterIteration=1;
this->iterator=other.iterator;
}
virtual ~Iterator()
{
if(this->releaseIteratorAfterIteration) delete[] this->iterator;
}
void setreleaseIteratorAfterIteration(int releaseIteratorAfterIteration)
{
this->releaseIteratorAfterIteration=releaseIteratorAfterIteration;
}
Iterator &operator =(const Iterator &other)
{
this->iterator=other.iterator;
return *this;
}
virtual int hasMoreElement()
{
if(iterator!=NULL) return this->iterator->hasMoreElement();
return 0;
}
virtual int next()
{
if(iterator!=NULL) return this->iterator->next();
return 0;
}
};
class Iterable
{
public:
virtual Iterator getIterator()=0;
};
class TMList:public Iterable
{
public:
virtual void add(int data,int *success)=0;
virtual int get(int index,int *success)const=0;
virtual int getSize()const=0;
virtual void update(int data,int index,int *success)=0;
virtual void insertAt(int data,int index,int *success)=0;
virtual int removeAt(int index,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
};                               
class TMArrayList:public TMList
{
private:
char allocationflag;
int **ptr;
int size;
int capacity;
bool addrow () ;
public:
class TMArrayListIterator:public Iterator
{
private:
int **ptr;
int index;
int size;
public:
TMArrayListIterator(int **ptr,int size)
{
this->ptr=ptr;
this->size=size;
this->index=0;
}
TMArrayListIterator(const TMArrayListIterator &other)
{
this->ptr=other.ptr;
}
TMArrayListIterator & operator =(const TMArrayListIterator &other)
{
this->ptr=other.ptr;
return *this;
}
int hasMoreElement()
{
return index<size;
}
int next()
{
if(index==size) return 0;
int rowindex=index/10;
int columnindex=index%10;
int data=this->ptr[rowindex][columnindex];
index++;
return data;
}
};
public:
Iterator getIterator()
{
TMArrayListIterator * tmArrayListIterator;
tmArrayListIterator=new TMArrayListIterator(this->ptr,this->size);
Iterator k(tmArrayListIterator);
k.setreleaseIteratorAfterIteration(0);
return k;
}
TMArrayList();
virtual ~TMArrayList();
TMArrayList(int bufferSize);
TMArrayList(const TMArrayList &other);
TMArrayList(const TMList &other);
TMArrayList & operator=(const TMArrayList &other);
TMArrayList & operator=(const TMList &other);
void operator+=(const TMArrayList &other);
void operator+=(const TMList &other);
TMArrayList operator+(const TMArrayList &other);
TMArrayList operator+(const TMList &other);
void add(int data,int *success);
void insertAt(int data,int index,int *success);
int removeAt(int index,int *success);
void update(int data,int index,int *success);
int get(int index,int *success)const;
int getSize()const;
void removeAll();
void clear();
};
bool TMArrayList::addrow ()
{
if(this->capacity%100==0)
{
int NumberOfPointer;
NumberOfPointer=this->capacity/10;
int **tmp=new int*[NumberOfPointer+10];
if(tmp==NULL) return false;
for(int e=0;e<NumberOfPointer;e++)tmp[e]=this->ptr[e];
delete [ ] this->ptr;
this->ptr=tmp;
}
int i=this->capacity/10;
this->ptr[i]=new int[10];
if(this->ptr[i]==NULL) return false;
this->capacity=this->capacity+10;
return true;
}
TMArrayList ::TMArrayList()
{
this->allocationflag==0;
this->ptr=new int*[10];
this->ptr[0]=new int[10];
this->size=0;
this->capacity=10;
}
TMArrayList ::TMArrayList(int bufferSize)
{
this->allocationflag==0;
if(bufferSize<0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->size=0;
this->capacity=10;
}
int row;
int NumberOfPointer;
row=bufferSize/10;
if(bufferSize%10!=0) row++;
NumberOfPointer=row+(10-(row%10));
this->ptr=new int*[NumberOfPointer];
for(int e=0;e<row;e++)
{
this->ptr[e]=new int[10];
}
this->capacity=row*10;
this->size=0;
}
TMArrayList ::TMArrayList(const TMArrayList &other)
{
this->allocationflag==0;
int bufferSize(bufferSize==other.size);
if(bufferSize<=0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->size=0;
this->capacity=10;
}
else
{
int row;
int NumberOfPointer;
row=bufferSize/10;
if(bufferSize%10!=0) row++;
NumberOfPointer=row+(10-(row%10));
this->ptr=new int*[NumberOfPointer];
for(int e=0;e<row;e++)
{
this->ptr[e]=new int[10];
}
this->capacity=row*10;
this->size=0;
}
int succ;
for(int x=0;x<other.size;x++)
{
this->add(other.get(x,&succ),&succ);
}
}
TMArrayList ::TMArrayList(const TMList &other)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->size=0;
this->capacity=10;
int succ;
for(int x=0;x<other.getSize();x++)
{
this->add(other.get(x,&succ),&succ);
}
}
TMArrayList & TMArrayList ::operator=(const TMArrayList &other)
{
if(other.allocationflag==0)
{
this->size=0;
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
else
{
int row=this->capacity/10;
for(int e=0;e<row;e++)
{
delete[ ] this->ptr[e];
}
delete[ ] this->ptr;
this->size=other.size;
this->ptr=other.ptr;
this->capacity=other.capacity;
}
return *this;
}
TMArrayList & TMArrayList ::operator=(const TMList &other)
{
this->size=0;
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
return *this;
}
void TMArrayList ::operator+=(const TMArrayList &other)
{
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
void TMArrayList ::operator+=(const TMList &other)
{
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}
TMArrayList  TMArrayList ::operator+(const TMArrayList &other)
{
TMArrayList k;
int succ;
for(int x=0;x<this->size;x++)
{
k.add(this->get(x,&succ),&succ);
}
for(int e=0;e<other.size;e++)
{
k.add(other.get(e,&succ),&succ);
}
k.allocationflag=1;
return k;
}
TMArrayList  TMArrayList ::operator+(const TMList &other)
{
TMArrayList k;
int succ;
for(int x=0;x<this->getSize();x++)
{
k.add(this->get(x,&succ),&succ);
}
for(int e=0;e<other.getSize();e++)
{
k.add(other.get(e,&succ),&succ);
}
return k;
}
void TMArrayList ::add(int data,int *success)
{
if(success) *success=false;
if(this->size==this->capacity)
{
if(!addrow()) return;
}
int rowindex,columnindex;
rowindex=this->size/10;
columnindex=this->size%10;
this->ptr[rowindex][columnindex]=data;
this->size++;
if(success) *success=true;
}
int TMArrayList ::get(int index,int *success) const
{
if(success) *success=false;
if(index<0 || index>=this->size) return 0;
int rowindex,columnindex;
rowindex=index/10;
columnindex=index%10;
if(success) *success=true;
return this->ptr[rowindex][columnindex];
}
int TMArrayList ::getSize()const
{
return this->size;
}
void TMArrayList ::removeAll()
{
this->size=0;
}
void TMArrayList ::clear()
{
this->size=0;
}
void TMArrayList ::insertAt(int data,int index,int *success)
{
if(success) *success=false;
if(index<0 || index>=this->size) return;
if(index==this->size)
{
this->add(data,success);
}
bool succ;
int k=this->get(this->size-1,&succ);
this->add(k,&succ);
if(succ==false) return;
int j;
j=this->size-3;
while(j>=index)
{
this->update(j+1,this->get(j,&succ),&succ);
j--;
}
this->update(data,index,&succ);
if(success) *success=true;
}
int TMArrayList ::removeAt(int index,int *success)
{
if(success) *success=false;
if(index<0|| index>=this->size) return 0;
bool succ;
int data=this->get(index,&succ);
int ep,j;
ep=this->size-2;
j=index;
while(j<=ep)
{
this->update(j,this->get(j+1,&succ),&succ);
j++;
}
this->size--;
if(success) *success=true;
return data;
}
void TMArrayList ::update(int data,int index,int *success)
{
if(success) *success=false;
if(index<0 || index>=this->size) return;
int rowindex,columnindex;
rowindex=index/10;
columnindex=index%10;
this->ptr[rowindex][columnindex]=data;
if(success) *success=true;
}
TMArrayList ::~TMArrayList()
{
if(this->allocationflag==0)
{
int row=this->capacity/10;
for(int e=0;e<row;e++)
{
delete[ ] this->ptr[e];
}
delete[ ] this->ptr;
}
}

//TMForwardList implemantion start here
#include<iostream>
#define true 1
#define True 1
#define TRUE 1
#define FALSE 0
#define false 0
#define False 0
#define FASLE 0
#define bool int
using namespace std;
class TMForwardList:public TMList
{
class TMnode
{
public:
int data;
TMnode *next;
TMnode ()
{
this->next==NULL;
}
};
private:
char allocationflag;
TMnode *start,*end;
int size;
public:
class TMForwardListIterator:public Iterator
{
private:
TMnode *ptr;
public:
TMForwardListIterator()
{
this->ptr=NULL;
}
TMForwardListIterator(TMnode *ptr)
{
this->ptr=ptr;
}
TMForwardListIterator(const TMForwardListIterator &other)
{
this->ptr=other.ptr;
}
TMForwardListIterator & operator =(const TMForwardListIterator &other)
{
this->ptr=other.ptr;
return *this;
}
int hasMoreElement()
{
return this->ptr!=NULL;
}
int next()
{
if(this->ptr==NULL) return 0;
int data=this->ptr->data;
this->ptr=this->ptr->next;
return data;
}
};
TMForwardListIterator tmForwardListIterator;
public:
Iterator getIterator()
{
TMForwardListIterator * tmForwardListIterator;
tmForwardListIterator=new TMForwardListIterator(this->start);
Iterator k(tmForwardListIterator);
k.setreleaseIteratorAfterIteration(0);
return k;
}
TMForwardList();
virtual ~TMForwardList();
TMForwardList(int bufferSize);
TMForwardList(const TMForwardList &other);
TMForwardList & operator=(const TMForwardList &other);
void operator+=(const TMForwardList &other);
TMForwardList operator+(const TMForwardList &other);
TMForwardList(const TMList &other);
TMForwardList & operator=(const TMList &other);
void operator+=(const TMList &other);
TMForwardList operator+(const TMList &other);
void add(int data,int *success);
void insertAt(int data,int index,int *success);
int removeAt(int index,int *success);
void update(int data,int index,int *success);
int get(int index,int *success)const;
int getSize()const;
void removeAll();
void clear();
};
TMForwardList ::TMForwardList()
{
this->allocationflag==0;
this->start=NULL;
this->end=NULL;
this->size=0;
}
TMForwardList ::TMForwardList(int bufferSize)
{
this->allocationflag==0;
this->start=NULL;
this->end=NULL;
this->size=0;
}
TMForwardList ::TMForwardList(const TMForwardList &other)
{
this->allocationflag==0;
this->start=NULL;
this->end=NULL;
this->size=0;
int succ;
for(int x=0;x<other.getSize();x++)
{
this->add(other.get(x,&succ),&succ);
}
}
TMForwardList ::TMForwardList(const TMList &other)
{
this->allocationflag==0;
this->start=NULL;
this->end=NULL;
this->size=0;
int succ;
for(int x=0;x<other.getSize();x++)
{
this->add(other.get(x,&succ),&succ);
}
}
TMForwardList & TMForwardList ::operator=(const TMForwardList &other)
{
this->clear ();
if(other.allocationflag==0)
{
this->size=other.size;
this->start=other.start;
this->end=other.end;
}
else
{
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}
return *this;
}
TMForwardList & TMForwardList ::operator=(const TMList &other)
{
this->clear ();
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
return *this;
}
void TMForwardList ::operator+=(const TMForwardList &other)
{
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}
void TMForwardList ::operator+=(const TMList &other)
{
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}
TMForwardList  TMForwardList ::operator+(const TMForwardList &other)
{
TMForwardList k;
k+=(*this);
k+=other;
k.allocationflag==1;
return k;
}
TMForwardList  TMForwardList ::operator+(const TMList &other)
{
TMForwardList k;
k+=(*this);
k+=other;
return k;
}
void TMForwardList ::add(int data,int *success)
{
if(success) *success=false;
TMnode *t;
t=new TMnode;
if(t==NULL) return;
t->data=data;
if(this->start==NULL)
{
this->start=t;
this->end=t;
}
else
{
this->end->next=t;
this->end=t;
}
this->size++;
if(success) *success=true;
}
int TMForwardList ::get(int index,int *success) const
{
if(success) *success=false;
if(index<0 || index>this->size) return 0;
TMnode *t;
int x;
t=this->start;
for(x=0;x<index;x++) t=t->next;
return t->data;
if(success) *success=true;
}
int TMForwardList ::getSize()const
{
return this->size;
}
void TMForwardList ::removeAll()
{
this->clear();
}
void TMForwardList ::clear()
{
TMnode *t;
t=new TMnode;
if(t==NULL) return;
while(this->start!=NULL)
{
t=this->start;
this->start=this->start->next;
delete t;
}
this->size=0;
this->end==NULL;
}
void TMForwardList ::insertAt(int data,int index,int *success)
{
if(success)*success=false;
if(index<0 || index>this->size) return;
if(index==this->size)
{
this->add(data,success);
return;
}
TMnode *t;
t=new TMnode;
if(t==NULL) return;
t->data=data;
int x;
TMnode *p1,*p2;
p1=this->start;
for(x=0;x<index;x++)
{
p2=p1;
p1=p1->next;
}
if(p1==this->start)
{
t->next=this->start;
this->start=t;
}
else
{
p2->next=t;
t->next=p1;
}
this->size++;
if(success) *success=true;
}
int TMForwardList ::removeAt(int index,int *success)
{
if(success) *success=false;
int data=0;
if(index<0 || index>this->size) return data;
TMnode *j,*t;
int x;
t=this->start;
for(x=0;x<index;x++)
{
j=t;
t=t->next;
}
if(t==this->start && t==this->end)
{
this->start=NULL;
this->end=NULL;
}else if(t==this->start)
{
this->start=this->start->next;
}else if(t==this->end)
{
j->next=NULL;
this->end=j;
}
else
{
j->next=t->next;
}
this->size--;
delete t;
if(success) *success=true;
return t->data;
}
void TMForwardList ::update(int data,int index,int *success)
{
if(success) *success=false;
if(index<0 || index>this->size) return;
TMnode *t;
int x;
t=this->start;
for(x=0;x<index;x++) t=t->next;
data=t->data;
if(success) *success=true;
}
TMForwardList ::~TMForwardList()
{
if(allocationflag==0)
{
this->clear();
}
}
int main ()
{
cout<<"now iterator after Iteration Forward List"<<endl;
int k;
TMForwardList list1;
list1.add(544,&k);
list1.add(434,&k);
list1.add(43,&k);
list1.add(34,&k);
list1.add(44,&k);
list1.add(10,&k);
Iterator iterator1=list1.getIterator();
Iterator iterator2=list1.getIterator();
Iterator iterator3=list1.getIterator();
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
cout<<"*****************"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
cout<<"now iterator after Iteration Array List"<<endl;
TMArrayList list2;
list2.add(544,&k);
list2.add(434,&k);
list2.add(43,&k);
list2.add(34,&k);
list2.add(44,&k);
list2.add(10,&k);
iterator1=list2.getIterator();
iterator2=list2.getIterator();
iterator3=list2.getIterator();
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
cout<<"*****************"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
return 0;
}