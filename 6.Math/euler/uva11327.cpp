/*************************************************************************
	> File Name: uva11327.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年09月12日 星期六 17时35分45秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200000;
ll vis[200005], pri[200005], phi[200005], q[200005];
int cnt;
void init()
{
	memset(vis, 0, sizeof vis);
	phi[1] = 1;
	vis[1] = 1;
	for(int i = 2; i <= MAXN; ++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			phi[i] = i - 1;
			pri[cnt++] = i;
		}
		for(int j = 0; j < cnt; ++j)
		{
			if(1ll * i * pri[j] > MAXN) break;
			vis[i * pri[j]] = 1;
			if(i % pri[j])
			{
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
			else
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
		}
	}
}
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int main(){
	init();
	memset(q, 0, sizeof q);
	for(int i = 1; i <= 200000; ++i)
	{
		q[i] = q[i - 1] + phi[i];
	}
	ll n;
	while(~scanf("%lld", &n))
	{
		if(n == 0) break;
		if(n == 1)
		{
			puts("0/1");
			continue;
		}
		if(n == 2)
		{
			puts("1/1");
			continue;
		}
		--n;
		ll x = lower_bound(q + 1, q + 200001, n) - q;
		ll y = n - q[x - 1];
		ll i = 1;
		for(; i <= 200000; ++i)
		{
			if(gcd(x, i) == 1)
			{
				--y;
				if(!y) break;
			}
		}
		printf("%lld/%lld\n", i, x);
	}
	

    return 0;	
}
