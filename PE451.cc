#include <cstdio>
#define N 101
int main(int argc, const char *argv[])
{
	for (int i = 1; i < N; i++) {
		for (int j = i-2; j >= 0; --j){
			if(j*j%i==1){
				printf("%d %d\n",i,j);
				break;
			}
		}
	}
	return 0;
}
