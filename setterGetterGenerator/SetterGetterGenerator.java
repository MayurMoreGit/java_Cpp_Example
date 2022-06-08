package com.thinking.machine.util;
import java.lang.reflect.*;
import java.io.*;
public class SetterGetterGenerator
{
public static void main (String gg[])
{
if(gg.length!=1 && gg.length!=2)
{
System.out.println("usage java jar_file com/thinking/machine/util/ SetterGetterGenetrator className constructor =true/false");
return; 
}
if(gg.length==2)
{
if(gg[1].equalsIgnoreCase("constructor=true")==false || gg[2].equalsIgnoreCase("constructor=false")==false)
{
System.out.println("usage java jar_file com/thinking/machine/util/ SetterGetterGenetrator className constructor =true/false");
return; 
}
}
try
{
String className;
className=gg[0];
Class c=Class.forName(className);
Field fields[];
fields=c.getDeclaredFields();
Field field;
TmList<String> list=new TmArrayList<String>();
String setterName;
String getterName;
String line;
String fieldName;
String tmp;
Class fieldType;
if(gg.length==1 || (gg.length==2 && gg[1].equalsIgnoreCase("construct=true")))
{
line="public "+c.getSimpleName()+"()";
list.add(line);
list.add("{");
for(int e=0;e<fields.length;e++)
{
field=fields[e];
line="this."+field.getName()+"="+getDefaultValue(field.getType())+";";
list.add(line);
}
list.add("}");
}
for(int e=0;e<fields.length;e++)
{
field=fields[e];
fieldName=field.getName();
fieldType=field.getType();
if(fieldName.charAt(0)>=97 && fieldName.charAt(0)<=122)
{       
tmp=fieldName.substring(0,1).toUpperCase()+fieldName.substring(1);
}
else
{
tmp=fieldName;
}



//dateOfBirth=DateOfBirth
setterName="set"+tmp;
getterName="get"+tmp;
line="public void"+" "+setterName+"("+fieldType.getName()+" "+fieldName+")";
list.add(line);
list.add("{");
line="this."+fieldName+"="+fieldName+";";
list.add(line);
list.add("}");
//public void setrollNumber(int rollNumber)
//{
//this.rollNumber=rollNumber;
//}
line="public "+fieldType.getName()+" "+getterName+"()"; 
list.add(line);
list.add("{");
line="return"+" "+"this."+fieldName+";";
list.add(line);
list.add("}");
//public int getrollNumber()
//{
//return this.rollNumber;
//}
File file=new File("tmp.tmp");
if(file.exists()) file.delete();
RandomAccessFile randomAccessFile;
randomAccessFile=new RandomAccessFile(file,"rw");
TmIterator <String>iterator=list.iterator();
while(iterator.hasNext())
{
line=iterator.next();
randomAccessFile.writeBytes(line+"\r\n");
}
randomAccessFile.close();
}
System.out.println("setter/getter for: c.getName() ,genterating  a file name is tmp.tmp");
}catch(ClassNotFoundException classNotFoundException)
{
System.out.println("unable to load a file invalid class path");
} 
catch(IOException ioException)
{
System.out.println("ioException.getMessage()");
}
}
private static String getDefaultValue(Class c)
{
String className=c.getName();
if(className.equals("java.lang.Long") || className.equals("long")) return "0";
if(className.equals("java.lang.Integer") || className.equals("int")) return "0";
if(className.equals("java.lang.Short") || className.equals("short")) return "0";
if(className.equals("java.lang.Double") || className.equals("double")) return "0.0";
if(className.equals("java.lang.Float") || className.equals("float")) return "0.0f";
if(className.equals("java.lang.character") || className.equals("char")) return "' '";
if(className.equals("java.lang.Bytes") || className.equals("bytes")) return "0";
if(className.equals("java.lang.Boolean") || className.equals("boolean")) return "false";
if(className.equals("java.lang.String")) return "\"\"";
return null;
}
}
