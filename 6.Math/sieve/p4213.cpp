#include<bits/stdc++.h>
using namespace std;

#define il inline
#define re register


#define ll long long
#define mod 1000000007
il int read()
{
    re int x=0,f=1;re char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return x*f;
}
#define maxn 5000000
ll pai[maxn+5];
int prim[maxn+5],cnt,mu[maxn+5];
bool vis[maxn+5];
unordered_map<int,int> ans_mu;
unordered_map<int,ll> ans_pai;
il void init()
{
    mu[1]=pai[1]=1;
    for(re int i=2;i<=maxn;++i)
    {
        if(!vis[i]) prim[++cnt]=i,mu[i]=-1,pai[i]=i-1;
        for(re int j=1;j<=cnt&&prim[j]*i<=maxn;++j)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)
            {
                pai[i*prim[j]]=pai[i]*prim[j];
                break;
            }
            pai[i*prim[j]]=pai[prim[j]]*pai[i];
            mu[i*prim[j]]=-mu[i];
        }
    }
    for(re int i=1;i<=maxn;++i) mu[i]+=mu[i-1],pai[i]+=pai[i-1];
}
il ll get_pai(ll x)
{
    if(x<=maxn) return pai[x];
    if(ans_pai[x]) return ans_pai[x];
    ll ans=((1ll+x)*x)/2ll;
    for(re int l=2,r;l<=x;l=r+1)//其实这里可能会爆int，可以改用用unsigned int
    {
        r=x/(x/l);
        ans-=1ll*(r-l+1)*get_pai(x/l);
    }
    return ans_pai[x]=ans;
}
il int get_mu(int x)
{
    if(x<=maxn) return mu[x];
    if(ans_mu[x]) return ans_mu[x];
    int ans=1;
    for(re int l=2,r;l<=x;l=r+1)
    {
        r=x/(x/l);
        ans-=(r-l+1)*get_mu(x/l);
    }
    return ans_mu[x]=ans;
}
il void doit()
{
    int T=read();
    while(T--)
    {
        int x=read();
        printf("%lld %d\n",get_pai(x),get_mu(x));
    }
}
signed main()
{
    init(),doit();
    return 0;
}
