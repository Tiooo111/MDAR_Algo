//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>
#include <algorithm>
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
template<typename T>inline T read(){
    int f, x;char c;
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
template<class T> inline T  OMIN(T &a,T &b) {return a=min(a,b);}
template<class T> inline T  OMAX(T &a,T &b) {return a=max(a,b);}
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
//========================================================
void exgcd(int a, int b, int64 &c, int64 &x, int64 &y)
{
	if(!b)
	{
		c = a;
		x = 1;
		y = 0;
	}
	else
	{
		exgcd(b, a % b, c, y, x);
		y -= x * (a / b);
	}
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
	while(T--)
	{
		int a = read<int>(), b = read<int>(), c = read<int>();
		int64 d = 0, x = 0, y = 0;
		exgcd(a, b, d, x, y);
		if(c % d)
		{
			print(-1);
			pc('\n');
			continue;
		}
		x = x * c / d, y = y * c / d;
		int64 a1 = a / d, b1 = b / d;
		int64 k = ceil((1.0 - x) / b1);
		x += k * b1;
		y -= k * a1;
		int64 x_min = x, y_max = y;
		if(y <= 0)
		{
			print(x_min); pc(' ');
			k = (y - 1)/a1;
			if(((y - 1)/a1)*a1 != (y-1)) --k; 
			print<int64>(y - a1 * 1ll * k); pc('\n');
		}
		else
		{
			k = 1ll * ((y - 1) / a1);
			x += k * b1;
			y -= k * a1;
			print((x - 1) / b1 + 1); pc(' ');
			print(x_min); pc(' ');
			print(y); pc(' ');
			print(x); pc(' ');
			print(y_max); pc('\n');
		}
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
