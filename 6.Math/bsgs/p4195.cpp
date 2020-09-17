/*************************************************************************
	> File Name: p4195.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年09月16日 星期三 17时18分42秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

//#define LOCAL
#define ll long long 
#define int long long
ll m, v;
unordered_map<int, int> x;
ll gcd(ll a, ll b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	while(b) a %= b, a ^= b ^= a ^= b;
	return a;
}
ll mul_mod(ll a, ll b, ll p)
{
	ll f = 0;
	while(b)
	{
		if(b & 1) f = (f + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return f;
}
ll pow_mod(ll a, ll b, ll p)
{
	ll f = 1;
	while(b)
	{
		if(b & 1) f = f * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return f;
}
void exgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
	if(!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}
ll inv(ll a, ll p)
{
	ll d, x, y;
	exgcd(a, p, d, x, y);
	return (x % p + p) % p;
}
ll bsgs(ll a, ll b, ll p)
{
	x.clear();
    m=(ll)ceil(sqrt(p));
	v = inv(pow_mod(a, m, p), p);
	x[1] = 0;
	for(int i = 1, e = 1; i < m; ++i)
	{
		e = e * a % p;
		if(!x.count(e)) x[e] = i;
	}
	for(int i = 0; i < m; ++i) 
	{
		if(x.count(b)) return (i * m + x[b]);
		b = b * v % p;
	}
	return -1;
}
ll exbsgs(ll a,ll b,ll p)
{
    if (b==1||p==1)return 0;     //特殊情况，x=0时最小解
    ll g,k=0,ag=1;
    while ((g = gcd(a, p))>1)
    {
        if (b%g!=0)return -1;    //无法整除则无解
        k++, b /= g, p /= g, ag = ag * (a / g) % p;
    	if (ag==b)return k;   //na=b说明前面的a的次数为0，只需要返回k
    }
	return ~(g = bsgs(a, b * inv(ag, p) % p, p)) ? g + k : -1;
}
signed main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll a, b, p;
	cin>>a>>p>>b;
	while(a||b||p)
    {
    	a%=p;b%=p;
        int t=exbsgs(a,b,p);
        if (t==-1)cout<<"No Solution"<<endl;
        else cout<<t<<endl;
        cin>>a>>p>>b;
    }
    return 0;	
}
