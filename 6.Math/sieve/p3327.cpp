#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int vis[MAXN],prime[MAXN],num[MAXN],d[MAXN];//num存约数个数，d存一个数最小质因子的个数
void fun(int n)
{
	memset(vis,0,sizeof(vis));
	num[1]=1;
	d[1]=1;
	prime[0]=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			prime[++prime[0]]=i;
			d[i]=1;
			num[i]=2;
		}
		for(int j=1;j<=prime[0]&&i<=n/prime[j];j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				d[i*prime[j]]=d[i]+1;
				num[i*prime[j]]=num[i]/(d[i]+1)*(d[i]+2);
				break;
			}
			d[i*prime[j]]=1;
			num[i*prime[j]]=num[i]*2;
		}
	}
}
int main()
{
	fun(100);
	for(int i = 1;i <= 100; ++i) cout<<num[i]<<" ";
	cout<<endl;
	return 0;
}
