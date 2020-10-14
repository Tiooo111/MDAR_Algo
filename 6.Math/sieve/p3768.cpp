//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
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

template<class T> inline T  Omin(T &a,const T &b) {return a<b?a:b;}
template<class T> inline T  Omax(T &a,const T &b) {return a>b?a:b;}
template<class T> inline T  Osqr(const T &a) {return sqrt((a));}

using u32=unsigned int;
using i64=long long;
using u64=unsigned long long;
using ipair=std::pair<int,int>;
using VI=std::vector<int>;
using VD=std::vector<double>;
using VVI=std::vector<VI>;

const double pi=acos(-1.0);
const double eps=1e-11;

template<typename T>inline T read(){
    i64 f, x;char c;
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
const int MAXN = 5e6+5;
i64 p;
unordered_map<i64, i64> mp;
i64 inv4, inv6;
i64 pri[MAXN], v[MAXN], tot, phi[MAXN], sum_f[MAXN];
void pre()
{
	phi[1] = 1;
	for(int i = 2; i < MAXN; ++i)
	{
		if(!v[i]) pri[tot++] = i, phi[i] = i - 1;
		for(int j = 0; j < tot && i * pri[j] < MAXN; ++j)
		{
			v[i * pri[j]] = 1;
			if(i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j] % p;
				break;
			}
			phi[i * pri[j]] = phi[pri[j]] * phi[i] % p;
		}
	}
	for(int i = 1; i < MAXN; ++i)
		sum_f[i] = ((1ll*(sum_f[i - 1] + 1ll * phi[i] * i % p * i % p) % p) + p )% p; 
}
i64 fastPow(i64 a, i64 k, i64 p)
{
	i64 f = 1;
	while(k)
	{
		if(k & 1) f = f * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return (f%p+p)%p;
}
void init()
{
	inv4 = fastPow(4, p-2, p);
	inv6 = fastPow(6, p-2, p);
}

inline i64 f(i64 x)
{
	x %= p;
	return ((1ll*(x)*(x+1)%p*(x)%p*(x+1)%p)*inv4%p+p)%p;
}
inline i64 f2(i64 x)
{
	x %= p;
	return (1ll * x * (x+1) % p * (2*x+1) % p * inv6 % p+p)%p;
}
i64 du(i64 n)
{
	if(n < MAXN) return sum_f[n];
	if(mp.count(n)) return mp[n];
	i64 ans = f(n);
	i64 pre = 1, cnt;
	for(i64 l = 2, r; l <= n; l = r + 1)
	{
		r = min(n, n/(n/l));
		cnt = f2(r);
		ans -= 1ll*(cnt - pre % p)*du(n/l)%p;
		ans = (ans%p) + p % p;
		pre = cnt;
	}
	return mp[n] = ans;
}
i64 solve(i64 n)
{
	pre();
	i64 ans = 0;
	i64 pre = 0, cnt;
	for(i64 l = 1, r; l <= n; l = r + 1)
	{
		r = min(n, n/(n/l));
		cnt = du(r);
		ans += 1ll * (cnt - pre % p) * (f(n/l)) % p;
		ans = (ans%p) + p % p;
		pre = cnt;
	}
	return ((ans%p)+p)%p;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	i64 n;
	p = read<i64>(); n = read<i64>();
	init();
	print<i64>(solve(n));
	pc('\n');
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
