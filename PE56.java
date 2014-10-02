import java.io.*;
import java.util.*;
import java.math.*;
public class PE56
{
	public static int digitSum(BigInteger a)
	{
		String s=a.toString();
		int sum=0;
		for(int i=0;i<s.length();++i)
			sum+=s.charAt(i)-'0';
		return sum;
	}
	public static void main(String[] args)
	{
		int t,maxv=0,maxi=0,maxj=0;
		for(int i=1;i<100;++i)
			for(int j=1;j<100;++j)
			{
				t=digitSum(BigInteger.valueOf(i).pow(j));
				if(t>maxv){maxv=t;maxi=i;maxj=j;}
			}
		System.out.println(maxv+"\n"+maxi+"\n"+maxj);
	}
}
