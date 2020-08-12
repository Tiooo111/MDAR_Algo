#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
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
const int MAXN = 1000010;
long long int tree_V[MAXN], tree_V_sum[MAXN];
int n, m;

inline long lowbit(long x){
    return x & -x;
}
void add(int ind, long x){
    if(ind <= 0) return;
    for(register_t  i = ind; i <= n; i += lowbit(i))
    {
        tree_V[i] += x;
        tree_V_sum[i] += (x * (ind - 1));
    }
}
long long int getSum(int ind){
    long res = 0;
    for(register_t i = ind; i > 0; i -= lowbit(i))
    {
        res += ((ind * tree_V[i]) - tree_V_sum[i]);
    }
    return res;
}
inline long long int getRangeSum(int l, int r){
    return getSum(r) - getSum(l - 1);
}
int main(){
    read(n); read(m);
    long last = 0, x = 0;
    for(int i = 1;i <= n; ++i)
    {
        read(x);
        add(i, x - last);
        last = x;
    }
    long l, r;
    while(m--)
    {
        read(last);
        read(l); read(r);
        read(x);
        if(last == 1) x = -x;
        add(l, x); add(r + 1, -x);
    }
    read(l); read(r);
    write(getSum(r) - getSum(l - 1));
	return 0;
}
