/********************************
 * Author:			bigeast
 * Time:			2014-10-12
 * Description:		AC. answer is 34029210557338. 5504th
 * 第一次使用PARI/GP！
 * 语法总结：
没有大括号，用小括号中的逗号表示语法块的分界，例如for循环：for(I=1,100,print(I))
if语句：if(A,[A is true] B,[else] C)
列表的大小：#list

core(n)表示从n中去掉平方数因子后剩下的数，因此core(n)==n就代表n是square free的
。
 ********************************/

ans = 1;
a = List([1])
{
for(X=2,50, for(Y=1,X/2, t=binomial(X,Y); if(t==core(t), listinsert(a,t,1); if(#a == #Set(a), ans=ans+t,a=List(Set(a))))))
}
printf("%d\n",ans);
