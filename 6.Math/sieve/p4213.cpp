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

const int MAXN = 2e6;
i64 mu[MAXN], sum_mu[MAXN];
int p[MAXN], v[MAXN], tot;
std::unordered_map <int, int> mp;
void pre()
{
	mu[1] = 1;
	for(int i = 2; i < MAXN; ++i)
	{
		if(!v[i]) p[tot++] = i, mu[i] = -1;
		for(int j = 0; j < tot && i * p[j] < MAXN; ++j)
		{
			v[i * p[j]] = 1;
			if(i % p[j] == 0)
			{
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	for(int i = 1; i < MAXN; ++i) sum_mu[i] = sum_mu[i-1]+mu[i];
}
inline i64 S(i64 n)
{
	return (n)*(n+1)>>1;
}
inline i64 mu_res(i64 n)
{
	if(n < MAXN) return sum_mu[n];
	if(mp.count(n)) return mp[n];
	i64 ans = 1;
	for(i64 l = 2, r; l <= n; l = r + 1)
	{
		r = std::min(n, n/(n/l));
		ans -= 1ll*(mu_res(n/l)*(r-l+1));
	}
	return mp[n] = ans;
}
inline i64 phi_res(i64 n)
{
	i64 ans = 0;
	for(i64 l = 1, r; l <= n; l = r + 1)
	{
		r = std::min(n, n/(n/l));
		ans += 1ll*S(n/l)*(mu_res(r)-mu_res(l-1));
	}
	return ans;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	pre();
	int T = read<int>();
	i64 n;
	while(T--)
	{
		n = read<i64>();
		print(phi_res(n)); pc(' ');
		print(mu_res(n)); pc('\n');
	}
	
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
