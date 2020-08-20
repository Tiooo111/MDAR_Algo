#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
#define int64 long long
#define FOR(i, j, k) for(int (i) = (j); (i) <= (k); ++i)
#define REP(i, j) for(int (i) = 0; (i) < (j); ++i)
#define lchild(x) (x) << 1
#define rchild(x) (x) << 1 | 1
#define Omid(l, r)  (r - l >> 1) + l
template <typename T>
inline T read(){
	int ret, f; char c;
	for(f = 1, c = getchar(); !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(ret = 0; isdigit(c); c = getchar()) ret = ret * 10 + (c & 15);
	return f * ret;
}
template <typename T>
inline void print(T x){
	static char c[64]; int p = 0;
	if(x == 0) pc('0');
	else if(x < 0) pc('-'), x = -x;
	while(x)
	{
		c[p++] = (x % 10) + 48;
		x /= 10;
	}
	while(p--) pc(c[p]);
}
const int MAXN = 500005;
const int INF = 2e9 + 7;
int n, m;
int a[MAXN];
struct node{
	int l, r, fi, fi_, se, cnt;
	int add1, add1_, add2, add2_;
	int64 sum;
}t[MAXN << 2];
void pushup(int idx){
	t[idx].sum = t[lchild(idx)].sum + t[rchild(idx)].sum;
	t[idx].fi_ = max(t[lchild(idx)].fi_, t[rchild(idx)].fi_);
	if(t[lchild(idx)].fi == t[rchild(idx)].fi)
	{
		t[idx].fi = t[lchild(idx)].fi;
		t[idx].se = max(t[lchild(idx)].se, t[rchild(idx)].se);
		t[idx].cnt = t[lchild(idx)].cnt + t[rchild(idx)].cnt;
	}
	else if(t[lchild(idx)].fi > t[rchild(idx)].fi)
	{
		t[idx].fi = t[lchild(idx)].fi;
		t[idx].se = max(t[rchild(idx)].fi, t[lchild(idx)].se);
		t[idx].cnt = t[lchild(idx)].cnt;
	}
	else
	{
		t[idx].fi = t[rchild(idx)].fi;
		t[idx].se = max(t[lchild(idx)].fi, t[rchild(idx)].se);
		t[idx].cnt = t[rchild(idx)].cnt;
	}
}
void update(int o, int k1, int k1_, int k2, int k2_){
	t[o].sum+=1ll*k1*t[o].cnt+1ll*k2*(t[o].r-t[o].l+1-t[o].cnt);
	t[o].fi_=max(t[o].fi_, t[o].fi+k1_);
	t[o].add1_=max(t[o].add1_, t[o].add1+k1_);
	t[o].fi+=k1, t[o].add1+=k1;
	t[o].add2_=max(t[o].add2_, t[o].add2+k2_);
	if (t[o].se!=-INF) t[o].se+=k2;
	t[o].add2+=k2;
}
void pushdown(int idx){
	int tmp = max(t[lchild(idx)].fi, t[rchild(idx)].fi);
	if(t[lchild(idx)].fi == tmp) update(lchild(idx), t[idx].add1, t[idx].add1_, t[idx].add2, t[idx].add2_);
	else update(lchild(idx), t[idx].add2, t[idx].add2_, t[idx].add2, t[idx].add2_);
	if(t[rchild(idx)].fi == tmp) update(rchild(idx), t[idx].add1, t[idx].add1_, t[idx].add2, t[idx].add2_);
	else update(rchild(idx), t[idx].add2, t[idx].add2_, t[idx].add2, t[idx].add2_);
	t[idx].add1 = t[idx].add2 = t[idx].add1_ = t[idx].add2_ = 0;
}
void build(int l, int r, int idx){
	t[idx].l = l; t[idx].r = r;
	t[idx].add1 = t[idx].add2 = t[idx].add1_ = t[idx].add2_ = 0;
	if(l == r)
	{
		t[idx].sum = t[idx].fi = t[idx].fi_ = a[l];
		t[idx].se = -INF;
		t[idx].cnt = 1;
		return;
	}
	int mid = Omid(l, r);
	build(l, mid, lchild(idx));
	build(mid + 1, r, rchild(idx));
	pushup(idx);
}
void modify1(int l, int r, int idx, int k){
	if(r < t[idx].l || t[idx].r < l) return;
	if(l <= t[idx].l && t[idx].r <= r) 
	{
		update(idx, k, k, k, k);
		return;
	}
	pushdown(idx);
	modify1(l, r, lchild(idx), k);
	modify1(l, r, rchild(idx), k);
	pushup(idx);
}

void modify2(int l, int r, int idx, int k){
	if(r < t[idx].l || t[idx].r < l || t[idx].fi <= k) return;
	else if(l <= t[idx].l && t[idx].r <= r && t[idx].se < k)
	{
		update(idx, k - t[idx].fi, k - t[idx].fi, 0, 0);
		return;
	}
	pushdown(idx);
	modify2(l, r, lchild(idx), k);
	modify2(l, r, rchild(idx), k);
	pushup(idx);
}

int64 query3(int l, int r, int idx){
	if(r < t[idx].l || t[idx].r < l) return 0;
	if(l <= t[idx].l && t[idx].r <= r)
	{
		return t[idx].sum;
	}
	pushdown(idx);
	return query3(l, r, lchild(idx)) + query3(l, r, rchild(idx));
}

int query4(int l, int r, int idx){
	if(r < t[idx].l || t[idx].r < l) return -INF;
	if(l <= t[idx].l && t[idx].r <= r)
	{
		return t[idx].fi;
	}
	pushdown(idx);
	return max(query4(l, r, lchild(idx)), query4(l, r, rchild(idx)));
}
int query5(int l, int r, int idx){
	if(r < t[idx].l || t[idx].r < l) return -INF;
	if(l <= t[idx].l && t[idx].r <= r)
	{
		return t[idx].fi_;
	}
	pushdown(idx);
	return max(query5(l, r, lchild(idx)), query5(l, r, rchild(idx)));
}

int main(){
	n = read<int>(); m = read<int>();
	FOR(i, 1, n)
	{
		a[i] = read<int>();
	}
	build(1, n, 1);
	int q, l, r, v;
	while(m--)
	{
		q = read<int>();
		l = read<int>();
		r = read<int>();
		if(q == 1)
		{
			v = read<int>();
			modify1(l, r, 1, v);
		}
		else if(q == 2)
		{
			v = read<int>();
			modify2(l, r, 1, v);
		}
		else if(q == 3)
		{
			print(query3(l, r, 1));
			pc('\n');
		}
		else if(q == 4)
		{
			print(query4(l, r, 1));
			pc('\n');
		}
		else if(q == 5)
		{
			print(query5(l, r, 1));
			pc('\n');
		}
	}
	
}
