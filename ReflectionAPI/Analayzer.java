import java.lang.reflect.*;
public class Analayzer
{
public static void main(String gg [])
{
if(gg.length!=1)
{
System.out.println("usage java :className");
return;
}
try
{
String classToName=gg[0];
Class c=Class.forName(classToName);
System.out.println("Name (package name include)  "+c.getName());
System.out.println("Simple nameOf include "+c.getSimpleName());
Method methods[];
methods=c.getDeclaredMethods();
System.out.println("method.length  "+methods.length);
Method m;
String methodName;
Class methodReturnType;
Class parameter [];
for(int i=0;i<methods.length;i++)
{
m=methods[i];
methodName=m.getName();
System.out.println("name of method  "+methodName);
methodReturnType=m.getReturnType();
System.out.println("Type of method  "+methodReturnType);
parameter=m.getParameterTypes();
System.out.println("parameter length  "+parameter.length);
for(int j=0;j<parameter.length;j++)
{
System.out.printf("parameter length %d type: %s\n  ",j+1,parameter[j].getName());
}
System.out.println("*************");

}
Field fields[];
fields=c.getDeclaredFields();
System.out.println("fields.length  "+fields.length);
Field f;
String fieldName;
Class fieldType;
for(int i=0;i<fields.length;i++)
{
f=fields[i];
fieldName=f.getName();
fieldType=f.getType();
System.out.printf("field length %d,Name %s,Type %s\n",i+1,fieldName,fieldType.getName());
}
}catch(ClassNotFoundException nfe)
{
System.out.println("class   "+nfe.getMessage()+"Not found");
}

}
}