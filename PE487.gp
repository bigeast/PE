exp_mod(n,k,p) = {
	if(k==0,1,
	t = exp_mod(n,floor(k/2),p);
	t = t^2 % p;
	if(k%2==1,t=(t*n)%p);
	t)
}


