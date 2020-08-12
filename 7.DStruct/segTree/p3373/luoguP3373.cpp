

/*************************************************************************
	> File Name: luoguP3372.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年08月12日 星期三 13时10分48秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
#define lchild(x) ((x) << 1) + 1
#define rchild(x) ((x) + 1) << 1
#define parent(x) ((x) - 1) >> 1
#define Omid(l, r) ((r) - (l) >> 1) + (l)
#define FOR(i, j, k) for(int (i) = (j); (i) < (k); ++(i))
#define REP(i, j) for(int (i) = 0; (i) < (j); ++i)
template <typename T>
inline void read(T &x){
	int flg;
	char c;
	for(flg = 1, c = ch(); !isdigit(c); c = ch()) if(c == '-') flg = -1;
	for(x = 0; isdigit(c); c = ch()) x = 10 * x + (c & 15);
	x *= flg;
}
template <typename T>
inline void write(T x){
	static char q[64]; int cnt = 0;
	if(x == 0) pc('0');
	if(x < 0) pc('-'), x = -x;
	while(x) q[cnt++] = x % 10 + '0', x /= 10;
	while(cnt--) pc(q[cnt]);
}
struct Node{
	int l, r;
	long sum, lazy, lazy_mul;
	Node(){} 
	Node(int _l, int _r) : l(_l), r(_r){
        sum = lazy = 0;
		lazy_mul = 1;
    } 
};
Node *segT;
int n, m, p;
long A[100005];
inline void pushup(int idx){
	segT[idx].sum = (segT[lchild(idx)].sum + segT[rchild(idx)].sum) % p;
}
inline void pushdown(int idx){
	int l = lchild(idx), r = rchild(idx);
	segT[l].sum += (segT[l].r - segT[l].l) * segT[idx].lazy;
	segT[l].sum %= p;
	segT[r].sum += (segT[r].r - segT[r].l) * segT[idx].lazy;
	segT[r].sum %= p;
	(segT[l].lazy += segT[idx].lazy) %= p;
	(segT[r].lazy += segT[idx].lazy) %= p;
	segT[idx].lazy = 0;
}
inline void pushdown_mul(int idx){
	int l = lchild(idx), r = rchild(idx);
	segT[l].sum *=  segT[idx].lazy_mul;
	segT[l].sum %= p;
	segT[r].sum *=  segT[idx].lazy_mul;
	segT[r].sum %= p;
	(segT[l].lazy_mul *= segT[idx].lazy_mul) %= p;
	(segT[r].lazy_mul *= segT[idx].lazy_mul) %= p;
	(segT[l].lazy *= segT[idx].lazy_mul) %= p;
	(segT[r].lazy *= segT[idx].lazy_mul) %= p;
	segT[idx].lazy_mul = 1;
}
inline void ppush(int idx){
	if(segT[idx].lazy_mul != 1) pushdown_mul(idx);
	if(segT[idx].lazy) pushdown(idx);
}
void make(int l, int r, int idx){
    segT[idx] = Node(l, r);
	if(l == r - 1) segT[idx].sum = A[l];
	else
	{
		int mid = Omid(l, r);
		make(l, mid, lchild(idx));
		make(mid, r, rchild(idx));
		pushup(idx);
	}
}
void update(int l, int r, int idx, long v){
    if(l >= segT[idx].r || r <= segT[idx].l) return;
	if(l <= segT[idx].l && segT[idx].r <= r)
	{
		segT[idx].sum += (segT[idx].r - segT[idx].l) * v;
		segT[idx].sum %= p;
		segT[idx].lazy += v;
        segT[idx].lazy %= p;
	}
	else
	{
		if(segT[idx].lazy || segT[idx].lazy_mul != 1) ppush(idx);
		int mid = Omid(segT[idx].l ,segT[idx].r);
		if(l >= mid) update(l, r, rchild(idx), v);
		else if(r <= mid) update(l, r, lchild(idx), v);
		else
		{
			update(l, r, rchild(idx), v);
			update(l, r, lchild(idx), v);
		}
		pushup(idx);
	}
}
void mul_update(int l, int r, int idx, long v){
    if(l >= segT[idx].r || r <= segT[idx].l) return;
	if(l <= segT[idx].l && segT[idx].r <= r)
	{
		segT[idx].sum *= v;
		segT[idx].sum %= p;
		segT[idx].lazy_mul *= v;
		segT[idx].lazy_mul %= p;
		segT[idx].lazy *= v;
		segT[idx].lazy %= p;
	}
	else
	{
		if(segT[idx].lazy || segT[idx].lazy_mul != 1) ppush(idx);
		int mid = Omid(segT[idx].l ,segT[idx].r);
		if(l >= mid) mul_update(l, r, rchild(idx), v);
		else if(r <= mid) mul_update(l, r, lchild(idx), v);
		else
		{
			mul_update(l, r, rchild(idx), v);
			mul_update(l, r, lchild(idx), v);
		}
		pushup(idx);
	}
}
long query(int l, int r, int idx){
	if(l >= segT[idx].r || r <= segT[idx].l) return 0;
	if(l <= segT[idx].l && segT[idx].r <= r)
	{
		return segT[idx].sum;
	}
	else
	{
		if(segT[idx].lazy || segT[idx].lazy_mul != 1) ppush(idx);
		int mid = Omid(segT[idx].l ,segT[idx].r);
		if(l >= mid) return query(l, r, rchild(idx));
		else if(r <= mid) return query(l, r, lchild(idx));
		else
		{
			return query(l, r, rchild(idx)) + query(l, r, lchild(idx));
		}
	}
}
int main(){
	read(n); read(m); read(p);
	REP(i, n)
	{
		read(A[i]);
	}
	segT = new Node[n << 2];
	make(0, n, 0);
	int a, l, r;
	while(m--)
	{
		read(a);
		read(l); read(r);
		if(a == 2)
		{
			long v;
			read<long>(v);
			update(l - 1, r, 0, v);
		}
		else if(a == 3)
		{
			write<long>(query(l - 1, r, 0) % p);
            pc('\n');
		}
		else if(a == 1)
		{
			long v;
			read<long>(v);
			mul_update(l - 1, r, 0, v);
		}
	}
    return 0;	
}
