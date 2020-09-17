//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>
#include <cstring>

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
#define int long long 
const int N = 50005;
bool vis[N];
int mu[N], pri[N], cnt, sum[N];
int a, b, c, d, k;
void init()
{
	mu[1] = 1;
	for(int i = 2; i <= N; ++i)
	{
		if(!vis[i])
		{
			pri[cnt++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < cnt && pri[j] * i <= N; ++j)
		{
			vis[i * pri[j]] = 1;
			if(!(i % pri[j])) break;
			else mu[i * pri[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + mu[i];
}
int solo(int n, int m)
{
	int res = 0;
	n /= k; m /= k;
	for(int l = 1, r; l <= std::min(m, n); l = r + 1)
	{
		r = std::min(n/(n/l), m/(m/l));
		res += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
	}
	return res;
}

signed main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	init();
	int T = read<int>();
	while(T--)
	{
		a = read<int>();
		b = read<int>();
		c = read<int>();
		d = read<int>();
		k = read<int>();
		int w = solo(b, d) - solo(b, (c - 1)) -
			solo((a - 1), d) + solo((a - 1), (c - 1));
		print(w);
		pc('\n');
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
