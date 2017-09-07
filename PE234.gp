{
    N = 999966663333;
    /*N = 15;*/
    n = primepi(sqrt(N)) + 1;
    pri=vector(n,x);
    idx = 1;
    forprime(p=1, sqrt(N), pri[idx]=p; idx++);
    pri[idx] = nextprime(pri[idx - 1] + 1);
    len = length(pri);
    ans = 0;
    for(i=1, len - 1,
            for(a = pri[i] + 1, floor(pri[i + 1]^2 / pri[i]), 
                mul = pri[i] * a;
                if(mul < N && a != pri[i + 1],ans += mul)
               );
            for(a = ceil(pri[i]^2 / pri[i + 1]), pri[i + 1] - 1,
                mul = pri[i + 1] * a;
                if(mul < N && a != pri[i], ans += mul)
               );
       );
    print(ans);
}
