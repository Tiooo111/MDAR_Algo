/*************************************************************************
	> File Name: headFile.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年08月11日 星期二 16时58分14秒
 ************************************************************************/

//#define LOCAL
//#include <bits/stdc++.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <list>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-11;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
    int f; char c;
    for(f = 1, c = ch(); c<'0' || c > '9'; c = ch()) if(c == '-')
	{
		f = -f;
	}
    for(x = 0; c <= '9' && c >= '0'; c = ch())
	{
		x = x * 10 + (c & 15);
	} 
	x *= f;
}
template<typename T>inline void write(T x){
    static char q[64]; int cnt = 0;
    if(!x) pc('0');
	if(x < 0) pc('-'), x = -x;
    while(x)
	{
		q[cnt++] = x % 10 + '0';
		x /= 10;
	}
	while(cnt--)
	{
		pc(q[cnt]);
	}
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
#define Parent(i) (((i)-1)>>1)
#define LChild(i) (1+((i)<<1))
#define RChild(i) ((1+(i))<<1)
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	return 0;
}
