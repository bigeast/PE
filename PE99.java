import java.lang.Math;
import java.io.*;
import java.util.*;
public class PE99
{
	public static void main(String[] args)throws IOException
	{
		double maxv=0.0,t;
		int i=0,a,b,pos=0;
		Scanner sc=new Scanner(new File("base_exp.txt"));
		while(sc.hasNext())
		{
			++i;
			a=sc.nextInt();
			b=sc.nextInt();
			t=b*Math.log10(a+0.0);
			if(maxv<t){maxv=t;pos=i;}
		//	System.out.println(t+"\t"+i);
		//	if(i>10)break;
		}
		System.out.println(maxv+"\t"+pos);
	}
}
