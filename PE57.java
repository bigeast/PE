import java.io.*;
import java.util.*;
import java.math.*;
public class PE57
{
	public static void main(String[] args)
	{
		BigInteger num=BigInteger.valueOf(3);
		BigInteger den=BigInteger.valueOf(2);
		BigInteger fac= new BigInteger("1");
		BigInteger ten=new BigInteger("10");
		int ans=0;
		for(int i=0;i<1000;++i)
		{
			BigInteger t=new BigInteger(den.toString().substring(0,den.toString().length()));
			den=den.add(num);
			num=den.add(t);
			//System.out.println(num+"\t"+den);
			while(fac.compareTo(num)<=0)	
			{
				if(den.compareTo(fac)<0)
				{
					++ans;break;
				}
				if(fac.multiply(ten).compareTo(num)<=0)fac=fac.multiply(ten);
				else break;
			}
		}
		System.out.println(ans);
	}
}
