import java.math.BigInteger;
public class PE25
{
	public static void main(String[] args)
	{
		BigInteger a[]=new BigInteger[10000];
		BigInteger b=new BigInteger("1");
		a[1]=b;
		a[2]=b;
		for(int i=3;;++i)
		{
			a[i]=a[i-1].add(a[i-2]);
			if((a[i].toString().length())>=1000)
			{
				System.out.println(i);
				break;
			}
		}
	}
}
