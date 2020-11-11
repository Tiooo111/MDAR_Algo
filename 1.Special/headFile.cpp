//#define LOCAL
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
//========================================================
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define FOR(i, j, k) for(int (i) = (j); (i) <= k; (i)+=1)
#define REP(i, j) for(int (i) = 0; (i) < j; (i)+=1)
#define MID(l, r) (((r)-(l)>>1)+l)
#define LOWBIT(i) ((i)&(-i))
#define PA(idx) ((idx)>>1)
#define LC(idx) ((idx)<<1)
#define RC(idx) ((idx)<<1|1)
#define ALL(A) A.begin(),A.end()
#define MP make_pair
#define PB push_back
#define PP pop_back
#define il inline
#define cl const ll &
//========================================================
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using ulll = unsigned __int128;
using std::cin;
using std::cout;
using std::endl;
using std::abs;
//========================================================
template<class T> inline void read(T &x)
{
	int f; char c = getchar();
	for(f = x = 0; (c < 48 || c > 57) && c > 0; c = getchar()) if(c == '-') f = 1;
	for(;c > 47 && c < 58; c = getchar()) x = (x << 3)+(x << 1)+(c & 15);
	if (f) x = -x;
}
template<class T>inline void write(T x)
{
    static char q[130]; int cnt = 0;
    if(!x) putchar('0'); if(x<0) putchar('-'),x = -x;
    while(x) q[cnt++]=x % 10 + 48, x /= 10;
    while(cnt--) putchar(q[cnt]);
}
template<class T,class... Args> inline void read(T &x, Args&... args) { read(x), read(args...); }
template<class T>inline void write(T x, char c) { write(x); putchar(c); }
template<class T>inline void xmax(T &x, const T &y) { x = x > y ? x : y; }
template<class T>inline void xmin(T &x, const T &y) { x = x < y ? x : y; }
//========================================================
const double pi = acos(-1.0);
const double eps = 1e-6;
//========================================================
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	IOS
	clock_t stime = clock();
	//========================================================

	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl;
	return 0;
}