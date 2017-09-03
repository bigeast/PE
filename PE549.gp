/* facints = vector(N, x, factorint(x)) */
pPower(n, p) = {
    sum(i = 1, log(n)/ log(p) + 1, floor(n/p^i))
}
isOK(idx, n) = {
    a = factorint(n);
    nfac = matsize(a)[1];
    res = 1;
    for(i = 1, nfac, if(pPower(idx, a[i, 1]) < a[i, 2], res = 0; break;));
    res;
}
minS(n) = {
    lo = 2;
    hi = n;
    old_lo = -1;
    old_hi = -1;
    mid = floor((lo + hi) / 2);
    while(lo < hi, if(isOK(mid, n), if(old_lo == lo && old_hi == hi, break, old_lo = lo; old_hi = hi); hi = mid; mid = floor((lo + mid) / 2), if(old_lo == lo && old_hi == hi, break, old_lo = lo; old_hi = hi); lo = mid; mid = floor((mid + hi) / 2)));
    hi;
}
PE549(n) = {
    sum(x = 2, n, minS(x));
}
