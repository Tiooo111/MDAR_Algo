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
const int MAXN = 1e6 + 7;
class heap{
	int A[MAXN], n;
public:
	heap(){ n = 0;}
	void pushup(int idx)
	{
		while(idx > 1 && A[idx] < A[PA])
		{
			std::swap(A[idx], A[PA]);
			idx = PA;
		}
	}
	void pushdown(int idx)
	{
		while(LC <= n)
		{
			int tmp  = A[idx] < A[LC] ? idx : LC;
			if(RC <= n)
			{
				tmp = A[tmp] < A[RC] ? tmp : RC;
			}
			if(tmp == idx) break;
			std::swap(A[tmp], A[idx]);
			idx = tmp;
		}
	}
	void heap_push(int num)
	{
		A[++n] = num;
		pushup(n);
	}
	int heap_pop()
	{
		int ans = A[1];
		std::swap(A[1], A[n--]);
		if(n) pushdown(1);
		return ans;
	}
	int top()
	{
		if(!n) return 0;
		return A[1];
	}
};
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	int n = read<int>();
	heap h1;
	while(n--)
	{
		int op = read<int>();
		if(op == 1)
		{
			int x = read<int>();
			h1.heap_push(x);
		}
		else if(op == 2)
		{
			print(h1.top());
			pc('\n');
		}
		else if(op == 3)
		{
			h1.heap_pop();
		}
	}
	//========================================================
	std::cerr << "Time:" << clock() - stime << std::endl; 
	return 0;
}
