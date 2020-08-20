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
const int MAXN=1000005;
int n, q, a[MAXN];
struct PST{
	int l, r, num;
}pst[MAXN * 20];
int top, root[MAXN];
inline void build(int &idx, int l, int r){
	idx = ++top;
	if(l == r)
	{
		pst[idx].num = a[l];
		return;
	}
	build(pst[idx].l, l, OMID);
	build(pst[idx].r, OMID + 1, r);
	return;
}
inline void update(int &idx, int pre, int l, int r, int pos, int v){
	idx = ++top;
	pst[idx] = pst[pre];
	if(l == r) pst[idx].num = v;
	else if(pos <= OMID) update(pst[idx].l, pst[pre].l, l, OMID, pos, v);
	else update(pst[idx].r, pst[pre].r, OMID + 1, r, pos, v);
	return ;
}
inline int query(int idx, int l, int r, int pos){
	if(l == r) return pst[idx].num;
	else if(pos <= OMID) return query(pst[idx].l, l, OMID, pos);
	else return query(pst[idx].r, OMID + 1, r, pos);
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	n = read<int>(), q = read<int>();
	for(int i = 1; i <= n; ++i) a[i] = read<int>();
	build(root[0], 1, n);
	for(int i = 1; i <= q; ++i)
	{
		int k = read<int>(), op = read<int>() , idx = read<int>(), v;
		if(op == 1)
		{
			v = read<int>();
			update(root[i], root[k], 1, n, idx, v);
		}
		else if(op == 2)
		{
			print(query(root[k], 1, n, idx));
			pc('\n');
			root[i] = root[k];
		}
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
