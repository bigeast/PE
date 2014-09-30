//数学函数在lang包的Math类里，都是静态方法
//自定义类中的方法要使用时必须通过对象调用。否则声明为静态方法后可以通过类名调用。
//所有的自身值等于各位数字的五次方之和的数，考虑到f(n)=10^n/(n-1),他必须小于9^5,易知f(n)是递增的，且f(6)>9^5>f(5),故只需在1..10^6的范围内寻找答案
import java.io.*;
import java.util.*;
public class PE30
{
	static int[] pows=new int [10];
	static void init()
	{
		for(int i=0;i<10;++i)
			pro30.pows[i]=(int)Math.pow(i,5);
	}
	static int powsum(int n)
	{
		int sum=0;
		while(n!=0)
		{
			sum+=pro30.pows[n%10];
			n/=10;
		}
		return sum;
	}
	public static void main(String[] args)
	{
		pro30.init();
		int ans=0;
		for(int i=10;i<1000000;++i)
		{
			if(i==pro30.powsum(i))ans+=i;
		}
		System.out.println(ans);
	}
}
