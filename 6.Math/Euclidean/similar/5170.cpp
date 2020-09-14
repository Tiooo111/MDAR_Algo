//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>

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
const int P = 998244353;
int i2 = 499122177, i6 = 166374059;
struct data
{
	int64 f, g, h;
	data(){ f = g = h = 0;}
};

data calc(int64 n, int64 a, int64 b, int64 c) {
	int64 ac = a / c, bc = b / c, m = (a * n + b) / c, n1 = (n + 1), n21 = (2 * n + 1);
	data e;
	if(a == 0)
	{
		e.f = bc * n1 % P;
		e.g = bc * n % P * n1 % P * i2 % P;
		e.h = bc * bc % P * n1 % P;
		return e;
	}
	if(a >= c || b >= c)
	{
		e.f = n1 * n % P * i2 % P * ac % P + bc * n1 % P;
		e.g = ac * n % P * n1 % P * n21 % P * i6 % P + bc *
				n1 % P * n % P * i2 % P;
		e.h = ac * ac % P * n % P * n1 % P * n21 % P * i6 %
				P + ac * bc % P * n % P * n1 % P +
				bc * bc % P * n1 % P;
		e.f %= P, e.g %= P, e.h %= P;

		data t = calc(n, a % c, b % c, c);

		e.f += t.f;
		e.g += t.g;
		e.h += t.h + 2 * bc % P * t.f % P + 2 * ac % P * t.g % P;
		e.f %= P, e.g %= P, e.h %= P;
		return e;
	}
		data t = calc(m - 1, c, c - b - 1, a);
		e.f = n * m % P - t.f; e.f = (e.f % P + P) % P;
		e.g = n * m % P * n1 % P - t.f - t.h; e.g = (e.g * i2 % P + P) % P;
		e.h = n * m % P * (m + 1) % P - 2 * t.g - 2 * t.f - e.f; e.h = (e.h % P + P) % P;
	return e;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	int T = read<int>();
	int64 n, a, b, c;
	while(T--)
	{
		n = read<int64>();
		a = read<int64>();
		b = read<int64>();
		c = read<int64>();
		data ans = calc(n, a, b, c);
		printf("%lld %lld %lld\n", ans.f, ans.h, ans.g);
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
