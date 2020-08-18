//#define LOCAL
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <vector>
#include <cmath>

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

#define LOWBIT(i) (i)&(-i)
#define REP(i,k) for(int i=0;i<(k);++i)
#define FOR(i,j,k) for(int i=(j);i<(k);++i)
#define MP make_pair
#define PB push_back
#define PP pop_back
#define SIZE(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define Parent(i) ((i)>>1)
#define LChild(i) ((i)<<1)
#define RChild(i) ((i)<<1|1)

using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;

const double pi=acos(-1.0);
const double eps=1e-11;
//========================================================
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	clock_t stime = clock();
	//========================================================
	
	//========================================================
	std::cess << "Time:" << clock() - stime << std::endl; 
	return 0;
}
