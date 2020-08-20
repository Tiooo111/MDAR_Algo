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
//========================================================
const int MAXN = 200010;
int n, q, m, cnt;
int a[MAXN], b[MAXN], root[MAXN];
struct pst{
	int l, r, sum;
}pst[MAXN << 5];
inline void insert(int &idx, int pre, int l, int r, int x){
	idx = ++cnt;
	pst[idx] = pst[pre];
	++pst[idx].sum;
	if(l == r) return;
	if(x <= OMID) insert(pst[idx].l, pst[pre].l, l, OMID, x);
	else insert(pst[idx].r, pst[pre].r, OMID + 1, r, x);
}
inline int query(int u, int v, int l, int r, int k){
	if(l == r) return l;
	int x = pst[pst[v].l].sum - pst[pst[u].l].sum;
	if(x >= k) return query(pst[u].l, pst[v].l, l, OMID, k);
	else return query(pst[u].r, pst[v].r, OMID + 1, r, k - x);
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	n = read<int>();
	q = read<int>();
	for(int i = 1; i <= n; ++i) b[i] = a[i] = read<int>();
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; ++i)
	{
		int t = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		insert(root[i], root[i - 1], 1, m, t);
	}
	while(q--)
	{
		int x = read<int>(), y = read<int>(), z = read<int>();
		print(b[query(root[x - 1], root[y], 1, m, z)]);
		pc('\n');
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
