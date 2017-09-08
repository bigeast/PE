{
    N = 100000;
    trifb = vector(N);
    trifb[1] = trifb[2] = trifb[3] = 1;
    for(i=4, N,
            trifb[i] = trifb[i-1] + trifb[i-2] + trifb[i-3]
       );
       idx = 1;
    for(i=3, 10000,
            flag=1;
            for(j = 1, N,
                if(trifb[j] % i == 0, flag=0;break)
            );
            if(flag, print(idx, " ", i); idx += 1);
            if(idx==125, break);
            i+=1
       );
}
