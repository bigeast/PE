#include <cstdio>
typedef long long LL;
bool isok(LL a) {
    while(a) {
        if(a % 10 > 2) return false;
        a /= 10;
    }
    return true;
}
int main(int argc, char *argv[])
{
    int N = 10000;
    LL a[]={0,1,10,11,100,101,110,111};
    LL b[]={1, 1000,1000000,1000000000};
    LL ans = 0;
    LL n = 111333555778ll, nt;
    int mask=0;
    for(int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    nt = (n + a[i] * b[3] + a[j] * b[2] + a[k] * b[1] + a[l] * b[0]);
                    if(isok(999 * nt)) {
                        for(int d = 1; d < 10; ++d) {
                            if(!(mask&(1<<(d-1))) && nt % d == 0) {
                                ans += nt / d;
                                mask |= (1<<(d-1));
                                printf("%d: %lld\n", d, nt);
                                if(mask==(1<<10)-1) return 0;
                            }
                        }
                    }
                    else {
                        //printf("%lld %lld %lld: %lld\n", a[i], a[j], a[k], nt);
                    }
                }
            }
        }
    }

    /*for (int i = 1; i < 10; ++i) {
      LL k = 0;
      while(++k<1e10) {
      if(isok(9 * i * k)) {
      printf("%d: %lld %lld\n", i, k, i*k);
      break;
      }
      }
      }*/
    
    for (int i = 1; i < N - 1; ++i) {
        if(i % 999 == 0) continue;
        for (LL k = 1; ; k++) {
            if(k > 1e12) { 
                printf("not found %d %d\n", i, i % 111);
                break;
            }
            if(isok(i * k)) {
                //printf("%d: %lld\n", i, (LL)i * k);
                ans += k;
                break;
            }
        }
    }

    ans += 1; // for f(10000)

    ans += 1111333355557778ll; // for f(9999)

    ans += n * 2; // for f(999*5)

    printf("Ans: %lld\n", ans);
    return 0;
}
