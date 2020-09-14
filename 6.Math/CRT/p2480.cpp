//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define OMID (r-l>>1)+l
#define LOWBIT(i) (i)&(-i)
#define REP(i,k) for(int i=0;i<(k);++i)
#define FOR(i,j,k) for(int i=(j);i<(k);++i)
#define MP make_pair
#define PB push_back
#define PP pop_back
#define SIZE(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define PA ((idx)>>1)
#define LC ((idx)<<1)
#define RC ((idx)<<1|1)
#define ch() getchar()
#define pc(x) putchar(x)

template<class T> inline T  Omin(T &a,T &b) {return a=min(a,b);}
template<class T> inline T  Omax(T &a,T &b) {return a=max(a,b);}
template<class T> inline T  Osqr(T a) {return sqrt((a));}

using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=std::pair<int,int>;
using VI=std::vector<int>;
using VD=std::vector<double>;
using VVI=std::vector<VI>;

const double pi=acos(-1.0);
const double eps=1e-11;

template<typename T>inline T read(){
    int64 f, x;char c;
    for(f=1,c=ch();!isdigit(c);c=ch())if(c=='-')f=-f;
    for(x=0;isdigit(c);c=ch())x=x*10+(c&15);
	return x*f;
}
template<typename T>inline void print(T x){
    static char q[64];int cnt=0;
    if(!x)pc('0');if(x<0)pc('-'),x=-x;
    while(x)q[cnt++]=x%10+'0',x/=10;
    while(cnt--)pc(q[cnt]);
}
//========================================================
const int64 mod = 999911658, m = 999911659;
int64 B[5] = {0, 2, 3, 4679, 35617}, A[5], fac[50000], inv[50000];
int64 fastPow(int64 a, int64 b, int64 p)
{
	int64 f = 1;
	while(b)
	{
		if(b & 1) f = f * a % p;
		a *= a;
		a %= p;
		b >>= 1;
	}
	return f % p;
}
void init(int64 n)
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i < n; ++i) fac[i] = fac[i - 1] * i % n;
	inv[n - 1] = fastPow(fac[n - 1], n - 2, n);
	for(int i = n - 2; i; --i)
	{
		inv[i] = 1ll * inv[i + 1] * (i + 1) % n;
	}
}
int64 C(int64 m, int64 n, int64 p)
{
	if(m > n) return 0;
	return 1ll * fac[n] * inv[m] % p * inv[n - m] % p;
}
int64 lucas(int64 m, int64 n, int64 p)
{
	if(!m) return 1;
	return 1ll * C(m % p, n % p, p) * lucas(m / p, n / p, p) % p;
}

int64 CRT()
{
	int64 val = 0;
	for(int i = 1; i <= 4; ++i)
		val = (val + A[i] * (mod / B[i]) % mod * fastPow(mod / B[i], B[i] - 2, B[i]) % mod) % mod;
	return val;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	int64 n, g;
	n = read<int64>();
	g = read<int64>();
	if(!(g % (mod + 1)))
	{
		printf("0\n");
		return 0;
	}
	memset(A, 0, sizeof A);
	int64 sqr = sqrt(n);
	int64 p[50000];
	int cnt = 0;
	for(int64 i = 1; i <= sqr; ++i) if(!(n % i))
		p[cnt++] = i, p[cnt++] = n / i;
	cnt -= p[cnt - 2] == p[cnt - 1];
	for(int i = 1; i <= 4; ++i)
	{
		init(B[i]);
		for(int j = 0; j < cnt; ++j) (A[i] += lucas(p[j], n, B[i])) %= B[i];
	}
	printf("%lld\n", 1ll * fastPow(g, CRT(), m));
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
