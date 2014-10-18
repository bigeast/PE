/********************************
 * Author:			bigeast
 * Time:			2014-10-18
 * Description:		AC. answer is 354. 3286th.

 根据入射光线的斜率和法线的斜率求初射光线的斜率，开始用几何画图，发现情况比较
 多，分情况容易出错。

 然后突然想到可以用a+b=2c关系，a,b是入射和出射光线所在直线与x轴的夹角，c是法线
 与x轴的夹角。

 后来答案还是不对，仔细看了一遍题目，发现是出口必须在x轴上方，而第一个找到的x
 值在-0.01~0.01区间内的值刚好是在x轴下方，是出不去的！
 ********************************/

{
	ax = 0;
	ay = 10.1;
	bx = 1.4;
	by = -9.6;

	k = (by-ay)/(bx-ax);
	b = by - k*bx;

	ans = 0;
	while(!(abs(bx)<=0.01&&by>0),
			printf("\nIter:%d k:%lf b:%lf\n",ans+1,k*1.0,b);
			\\ calculate the interpoints.
			A = -2*k*b;
			B = sqrt(4*b^2*k^2-4*(b^2-100)*(k^2+4));
			C = 2*(4+k^2);
			x1 = (A+B)/C;
			x2 = (A-B)/C;
			printf("x1:%lf x2:%lf\n",x1,x2);
			\\ one of the root is the old point
			if(abs(x1-ax)<1e-5,bx=x2,bx=x1);

			\\ byc and byl should be the same
			byc = sqrt(100-4*bx^2);
			byl = bx*k + b;
			if(abs(byc-abs(byl))>1e-5,printf("byc:%.7f byl%.7f\n",byc,byl));

			\\ old point
			printf("ax:%lf ay:%lf\n",ax,ay);
			\\ new point
			by = byl;
			printf("bx:%lf by:%lf\n",bx,by);

			\\ find the new slop tk
				nm = by/(4.0*bx);
			nm2 = 2*nm/(1-nm^2);
			tk = (nm2-k)/(1+nm2*k);

			\\ renew
				ax = bx;
			ay = by;
			k = tk;
			b = ay - k*ax;
			ans += 1
				);
			printf("Answer is %d\n",ans-1)
}
/*
   {
   ax = 0;
   ay = 10.1;
   bx = 1.4;
   by = -9.6;

   k = (by-ay)/(bx-ax);
   b = by - k*bx;

   ans = 0;
   while(abs(bx)>0.01,
   printf("\nIter:%d k:%lf b:%lf\n",ans+1,k,b);
   A = -2*k*b;
   B = sqrt(4*b^2*k^2-4*(b^2-100)*(k^2+4));
   C = 2*(4+k^2);
   x1 = (A+B)/C;
   x2 = (A-B)/C;
   printf("x1:%lf x2:%lf\n",x1,x2);
   if(abs(x1-ax)<1e-5,bx=x2,bx=x1);
   byc = sqrt(100-4*bx^2);
   byl = bx*k + b;
   if(abs(byc-abs(byl))>1e-7,printf("byc:%.7f byl%.7f\n",byc,byl));
   \\printf("bx:%lf by line:%lf by eql:%lf\n",bx,k*bx+b,by);
   printf("ax:%lf ay:%lf\n",ax,ay);
   printf("bx:%lf by:%lf\n",bx,byl);
   printf("by:%lf byl:%lf\n",by,byl);
   by = byl;
   nm = by/4*bx;
   if(nm*k<0,nm=1/nm);
   tt= (nm-k)/(1+nm*k);
   tk = (tt+nm)/(1-nm*tt);
   ax = bx;
   ay = by;
   k = tk;
   b = ay - k*ax;
   ans += 1
   );
   printf("%d\n",ans)
   }
 */
