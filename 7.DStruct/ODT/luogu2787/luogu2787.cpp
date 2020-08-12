/*************************************************************************
	> File Name: luogu2787.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年08月11日 星期二 17时19分05秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define IT set<node>::iterator

int n, m, nums[27];
template<typename Tp>
void read(Tp &x){
	x=0;char ch=1;int fh;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') ch=getchar(),fh=-1;
	else fh=1;
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x*=fh;
}
inline int getID(const char &c){
	if(c >= 'a') return c - 'a';
	return c - 'A';
}
struct node {
	int l, r;
	mutable int v;
	node(const int &_l, const int &_r = -1, const int &_v = 0) : l(_l), r(_r), v(_v) {}
	inline bool operator<(const node &o) const { return l < o.l; }
};
set<node> odt;
inline void push(int l, int r, char c){
    
}
inline IT split(int x) {
	if(x > n) return odt.end();
	IT it = --odt.upper_bound(node(x));
	if(it->l == x) return it;
	int l = it->l, r = it->r, v = it->v;
	odt.erase(it);
	odt.insert(node(l, x - 1, v));
	return odt.insert(node(x, r, v)).first;
}
int sum(int l, int r, char c){
	int res = 0, k = getID(c);
	IT itr = split(r + 1), itl = split(l);
	while(itl != itr)
	{
		if(itl->v == k) res += itl->r - itl->l + 1;
		++itl;
	}
	return res;
}
inline void assign(int l, int r, char c){
	IT itr = split(r + 1), itl = split(l);
	odt.erase(itl, itr);
	odt.insert(node(l, r, getID(c)));
}
inline void odt_sort(int l,int r){
    IT itr = split(r + 1), itl = split(l);
    IT tt = itl;
    memset(nums, 0, sizeof nums);
	for(; itl != itr; ++itl)
        nums[itl->v] += (itl->r - itl->l + 1);
    odt.erase(tt, itr);
	for(int i = 0; i < 27; ++i) if(nums[i] > 0)
	{
        odt.insert(node(l, l + nums[i] - 1, i));
		l += nums[i];
	}
	return;
}
char ss[50005];
int flg, x, y;
char k;
int main() {
	scanf("%d%d%s", &n, &m, ss + 1);
	for(int i = 1; i <= n; ++i)
	{
		odt.insert(node(i, i, getID(ss[i])));
	}
	while(m--)
	{
        read(flg); read(x); read(y);
		if(flg == 1)
		{
			k = getchar();
			printf("%d\n", sum(x, y, k));
		}
		else if(flg == 2)
		{
		    k = getchar();
			assign(x, y, k);
		}
		else if(flg == 3)
		{
			odt_sort(x, y);
		}
	}
    return 0;	
}
