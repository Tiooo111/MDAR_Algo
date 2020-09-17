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
template <typename T> inline void Omax(T &x, T y){ x = x > y ? x : y; }
struct Node{
	int l, r;
	long sum,lazy;
	Node(){} 
	Node(int _l, int _r) : l(_l), r(_r){
        sum = lazy = 0;
    } 
};
Node *segT;
int n, m;
long A[200005];
void pushup(int idx){
	segT[idx].sum = max(segT[lchild(idx)].sum , segT[rchild(idx)].sum);
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
void update(int l, int idx, long v){
    if(l >= segT[idx].r || l < segT[idx].l) return;
	if(l == segT[idx].l && segT[idx].r - 1 == l)
	{
        Omax(segT[idx].sum, v);
	}
	else
	{
		int mid = Omid(segT[idx].l ,segT[idx].r);
		if(l >= mid) update(l, rchild(idx), v);
		else  update(l, lchild(idx), v);
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
		int mid = Omid(segT[idx].l ,segT[idx].r);
		if(l >= mid) return query(l, r, rchild(idx));
		else if(r <= mid) return query(l, r, lchild(idx));
		else
		{
			return max(query(l, r, rchild(idx)), query(l, r, lchild(idx)));
		}
	}
}

int main(){
	read(n); read(m);
	REP(i, n)
	{
		read(A[i]);
	}
	segT = new Node[n << 2];
	make(0, n, 0);
	int l, r;
    char a;
	while(m--)
	{
		a = getchar();
		while(!isupper(a)) a = getchar();//小技巧：一个一个地读，读到字母为止
		read(l); read(r);
		if(a == 'U')
		{
			update(l - 1, 0, r);
		}
		else
		{
			write<long>(query(l - 1, r, 0));
            pc('\n');
		}
	}
    return 0;	
}
