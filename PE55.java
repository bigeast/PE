import java.io.*;
import java.util.*;
import java.math.*;
public class PE55
{
	public static BigInteger next(BigInteger n)
	{
		StringBuffer a=new StringBuffer(n.toString());
		StringBuffer b=new StringBuffer();
		int len=a.length();
		for(int i=0;i<len;++i)
			b.append(a.charAt(len-i-1));
		BigInteger c=new BigInteger(b.toString());
		n=n.add(c);
		return n;
	}
	public static boolean isPal(BigInteger n)
	{
		StringBuffer a=new StringBuffer(n.toString());
		int len=a.length();
		for(int i=0;i<len/2;++i)
			if(a.charAt(i)!=a.charAt(len-i-1))return false;
		return true;
	}
	public static boolean isLychrel(int n)
	{
		BigInteger a=BigInteger.valueOf(n);
		BigInteger t=new BigInteger("0");
		for(int i=0;i<50;++i)
		{
			t=next(a);
			//System.out.println(t);
			if(isPal(t))return false;
			else a=t;
		}
		return true;
	}
	public static void main(String[] args)
	{
		int ans=0;
		for(int i=11;i<10000;++i)
		{
			if(isLychrel(i))++ans;
		}
		System.out.println(ans);
	}
}
