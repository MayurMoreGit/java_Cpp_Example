class TmArrayList<T>
{
private Object  collection[];
private int size;
public TmArrayList()
{
this.collection=new Object [10];
this.size=0;
}
public void clear()
{
this.size=0;
}

public void add(T data)
{
if(this.size==collection.length)
{
Object  tmp[]=new Object [collection.length+10];
for(int e=0;e<collection.length;e++) tmp[e]=this.collection[e];
this.collection=tmp;
}
this.collection[this.size]=data;
this.size++;
}
public T removeAt(int index)
{
if(index<0 && index>this.size) throw new ArrayIndexOutOfBoundsException("invalid Index : "+index);
T data=(T)this.collection[index];
int pp=size-2;
for(int i=index;i<pp;i++)
{
this.collection[i]=this.collection[i+1];
}
this.size--;
return data;
}


public void add(T data,int index)
{
if(index<0 && index>this.size) throw new ArrayIndexOutOfBoundsException("invalid Index : "+index);
if(this.size==collection.length)
{
Object  tmp[]=new Object [this.size+10];
for(int e=0;e<this.size;e++) tmp[e]=this.collection[e];
this.collection=tmp;
}
int e;
for(e=this.size;e>index;e--)
{
this.collection[e]=this.collection[e-1];
}
this.collection[e]=data;
this.size++;
}
 
public T get(int index)
{
if(index<0 && index>this.size) throw new ArrayIndexOutOfBoundsException("invalid Index : "+index);
return (T)this.collection[index];
}
public int size()
{
return this.size;
}




}
class psp
{
public static void main(String gg[])
{
TmArrayList<Integer> list;
list=new TmArrayList<Integer>();
int x;
for(x=1;x<200;x++)
{
list.add(x);
}
System.out.println("list of Size" +list.size());
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}
System.out.println("list add ********************");
list.add(40000000,48);
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}
list.clear();
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}

System.out.println("new list .add");
list.add(300);
list.add(400);
list.add(500);
list.add(600);
list.add(3700);
list.add(800);
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}
System.out.println("new list remove");

list.removeAt(3);
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}
System.out.println("added");
list.add(6000,2);
for(int e=0;e<list.size();e++)
{
System.out.println(list.get(e));
}
System.out.println("list2************************");
TmArrayList <String>list2;
list2=new TmArrayList<String>();
list2.add("mayur");
list2.add("suresh");
list2.add("kalu");
list2.add("balu");
list2.add("lalu");
list2.add("ujjain");
list2.add("indore");
list2.add("dewas");
list2.add("sagar");
list2.add("mahesh");
list2.add("chalu");
list2.add("zero");
for(int e=0;e<list2.size();e++)
{
System.out.println(list2.get(e));
}
}
}
