import java.io.*;
import java.util.*;
public class PE35
{
	static boolean[] isp=new boolean[1000001];
	static boolean[] vis=new boolean[1000001];
	static boolean isPrime(int n)
	{
		double a=Math.sqrt(n+1);
		for(int i=2;i<a;++i)
			if(n%i==0)return false;
		return true;
	}
	static void init()
	{
		for(int i=2;i<1000000;++i)
		{
			isp[i]=isPrime(i);
		}
	}
	public static void main(String[] args)
	{
		init();
		System.out.println("OK,prime is here");
		int ans=0;
		String str;
		for(int fac=1;fac<1000000;fac*=10)
			for(int i=fac,t;i<10*fac;++i)
			{
				if(vis[i]||!isp[i])continue;
				str=Integer.toString(i,10);
				if(str.contains("0"))
					continue;
				t=i%10*fac+i/10;
				vis[i]=true;
				while(t!=i)
				{
					if(!isp[t])break;
					t=t%10*fac+t/10;//开始这里的t/10写成了i/10,一直找不到错误
				}
				if(t==i)++ans;
			}
		System.out.println(ans);
	}
}
