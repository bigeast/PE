/********************************
 * Author:			bigeast
 * Time:			2014-10-11
 * Description:		AC. answer is 376. 18412th
 * Two_Pairs函数写的有问题，找了老半天，偶然发现了775行的情况不对，调完之后答
 * 案对了。
 ********************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct card {
	int v;
	char s;
} Card;
int cmp(const Card &p1,const Card &p2) {
	return p1.v < p2.v;
}
// One pair op
int op;
// Straight from st to st+4
int st;
// two pairs of tp1 and tp2
int tp1,tp2;
// Full_House fh2,fh3
int fh2,fh3;
// Four_of_a_Kind 
int fk;
// Three_of_a_Kind 
int tk;
enum ENUM_rank_hands {
	ROYAL_FLUSH,
	STRAIGHT_FLUSH,
	FOUR_OF_A_KIND,
	FULL_HOUSE,
	FLUSH,
	STRAIGHT,
	THREE_OF_A_KIND,
	TWO_PAIRS,
	ONE_PAIR,
	HIGH_CARD
};
int print_Card(Card *h)
{
	for (int i = 0; i < 5; i++) {
		printf("%d%c ",h[i].v,h[i].s);
	}
	putchar('\n');
	return 0;
}
int Convert(char c) 
{
	int res;
	switch(c) {
		case 'A':
			res=14;
			break;
		case 'T':
			res=10;
			break;
		case 'J':
			res=11;
			break;
		case 'Q':
			res=12;
			break;
		case 'K':
			res=13;
			break;
		default:
			res=c -'0';
			break;
	}
	return res;
}
int Straight(Card *h)
{
	int t = h[0].v;
	for (int i = 0; i < 5; i++) {
		if(h[i].v != t+i){
			return 0;
		}
	}
	return h[0].v; 
}
int Flush(Card *h)
{
	return (h[0].s == h[1].s && h[1].s == h[2].s && h[2].s == h[3].s && h[3].s == h[4].s);
}
int Royal_Flush(Card *h)
{
	return (h[0].v==10 && h[1].v==11 && h[2].v==12 && h[3].v==13 && h[4].v==14) && Flush(h);
}
int Straight_Flush(Card *h)
{
	return Flush(h) && Straight(h);
}
int Four_of_a_Kind(Card *h)
{
	int cnta=0,cntb=0;
	for (int i = 0; i < 5; i++) {
		if(h[0].v==h[i].v)++cnta;
		if(h[4].v==h[i].v)++cntb;
	}
	if(cnta==4) {
		return fk = h[0].v;
	}
	else if(cntb==4) {
		return fk = h[4].v;
	}
	else {
		return 0;
	} 
}
int Full_House(Card *h)
{
	int cnta=0,cntb=0;
	for (int i = 0; i < 5; i++) {
		if(h[0].v==h[i].v)++cnta;
		if(h[4].v==h[i].v)++cntb;
	}
	if (cnta==2 && cntb==3) {
		fh2 = h[0].v;
		fh3 = h[4].v;
		return fh2+fh3;
	}
	else if(cnta==3 && cntb==2) {
		fh3 = h[0].v;
		fh2 = h[4].v;
		return fh2+fh3;
	}
	else {
		return 0;
	}
}
int Three_of_a_Kind(Card *h)
{
	int cnt[15];
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < 5; i++) {
		cnt[h[i].v]++;
	}
	for (int i = 0; i < 15; i++) {
		if(cnt[i]==3)
		{
			return tk = i;
		}
	}
	return 0;
}
int Two_Pairs(Card *h)
{
	int cnt[15];
	int res=0;
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < 5; i++) {
		cnt[h[i].v]++;
	}
	for (int i = 0; i < 15; i++) {
		if(cnt[i]==2) {
			++res;
		}
	}
	if(res==2) {
		for (int i = 0; i < 5; i++) {
			if(cnt[h[i].v]==2) {
				tp1 = h[i].v;
				break;
			}
		}
		for (int i = 4; i >= 0; i--) {
			if(cnt[h[i].v]==2) {
				tp2 = h[i].v;
				break;
			}
		}
		return 1;
	}
	return 0;
}
int One_Pair(Card *h)
{
	int cnt[15];
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < 5; i++) {
		if(cnt[h[i].v]==0)cnt[h[i].v]++;
		else {
			return op = h[i].v;
		}
	}
	return 0;
}
// if A wins B return true
int High_Card(int rank,Card *A,Card *B)
{
	int a1,a2,a3;
	switch(rank) {
		case STRAIGHT_FLUSH:
		case STRAIGHT:
			return A[0].v > B[0].v;
		case FOUR_OF_A_KIND:
			return Four_of_a_Kind(A) > Four_of_a_Kind(B);
		case FULL_HOUSE:
			Full_House(A);
			a2 = fh2;
			a3 = fh3;
			Full_House(B);
			// fh3 == a3 is impossible
			return a3>fh3;
		case THREE_OF_A_KIND:
			int a;
			a = Three_of_a_Kind(A);
			Three_of_a_Kind(B);
			return a > tk;
		case TWO_PAIRS:
			Two_Pairs(A);
			a1 = tp1;
			a2 = tp2;
			Two_Pairs(B);
			// -1 means a tie
			return tp2 < a2 ? 1: tp2==a2?(tp1<a1?1:(tp1==a1)?-1:0):0;
		case ONE_PAIR:
			return One_Pair(A) > One_Pair(B);
		case HIGH_CARD:
			int i=4;
			while(A[i].v==B[i].v) {
				i--;
			}
			return (A[i].v>B[i].v);
	}
}
int Rank_Hands(Card *h)
{
	if(Royal_Flush(h))return ROYAL_FLUSH;
	else if(Straight_Flush(h)) {
		return STRAIGHT_FLUSH;
	}
	else if(Four_of_a_Kind(h)) {
		return FOUR_OF_A_KIND;
	}
	else if(Full_House(h)) {
		return FULL_HOUSE;
	}
	else if(Flush(h)) {
		return FLUSH;
	}
	else if(Straight(h)) {
		return STRAIGHT;
	}
	else if(Three_of_a_Kind(h)) {
		return THREE_OF_A_KIND;
	}
	else if(Two_Pairs(h)) {
		return TWO_PAIRS;
	}
	else if(One_Pair(h)) {
		return ONE_PAIR;
	}
	else {
		return HIGH_CARD;
	}
}
int main(int argc, const char *argv[])
{
/*
	Card A[5]={{10,'D'},{11,'D'},{12,'D'},{13,'D'},{14,'D'}};
	printf("%d\n",Rank_Hands(A));
*/
	char buf[100];
	int T=1000;
	Card A[5],B[5];
	int Awin=0;
	freopen("p054_poker.txt","r",stdin);
	for (int k = 0; k < T; k++) {
		cin.getline(buf,100);
		for (int i = 0; i < 5; i++) {

			A[i].v=Convert(buf[3*i]);
			A[i].s=buf[3*i+1];
		}
		for (int i = 0; i < 5; i++) {
			B[i].v=Convert(buf[15+3*i]);
			B[i].s=buf[15+3*i+1];
		}
		sort(A,A+5,cmp);
		sort(B,B+5,cmp);
		int Ra,Rb;
		Ra = Rank_Hands(A);
		Rb = Rank_Hands(B);
		if(Ra < Rb) {
			++Awin;
		}
		else if(Ra == Rb) {
			if(High_Card(Ra,A,B)) {
/*
				printf("Case %d: A Win\n",k+1);
				print_Card(A);
				print_Card(B);
				putchar('\n');
*/
				++Awin;
			}
		}
	}
	printf("%d\n",Awin);
	return 0;
}
