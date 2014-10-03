import java.io.*;
import java.util.*;
public class PE81
{
	public static void main(String[] args)throws IOException
	{
		int mat[][]=new int[90][];
		for(int i=0;i<90;++i)mat[i]=new int[90];
		Scanner sc=new Scanner(new File("matrix.txt"));
		for(int i=0;i<80;++i)
		for(int j=0;j<80;++j)
			mat[i][j]=sc.nextInt();
		for(int i=1;i<80;++i)
		{
			mat[0][i]+=mat[0][i-1];
			mat[i][0]+=mat[i-1][0];
		}
		for(int i=1;i<80;++i)
			for(int j=1;j<80;++j)
				mat[i][j]+=mat[i-1][j]<mat[i][j-1]?mat[i-1][j]:mat[i][j-1];
		System.out.println(mat[79][79]);
	}
}
