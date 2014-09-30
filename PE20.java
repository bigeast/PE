import java.math.BigInteger;

public class PE20
{
	public static void main(String[] args)
	{
		BigInteger ans=new BigInteger("1");
		BigInteger tmp=new BigInteger("1");
		for(int i=2;i<=100;++i)
			ans=ans.multiply(tmp.valueOf(i));
		int cnt=0;
		String t=ans.toString();
		for(int i=0;i<t.length();++i)
			cnt+=(t.charAt(i)-'0');	
		System.out.println(cnt);
	}
}
