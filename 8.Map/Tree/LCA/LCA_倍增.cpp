#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std; 
const int MAXN=500010;
struct lfs{
	int to,nex;
}e[MAXN << 1]; int head[MAXN], tot;
void add(int u, int v){
	e[++tot].to = v;
	e[tot].nex = head[u];
	head[u] = tot;
}
int depth[MAXN],fa[MAXN][22],lg[MAXN];
void dfs(int now, int fath){
	fa[now][0] = fath;
	depth[now] = depth[fath] + 1;
	for(int i = 1; i <= lg[depth[now]]; ++i)
	{
		fa[now][i] = fa[fa[now][i-1]][i-1];
	}
	for(int i = head[now]; i; i=e[i].nex) if(e[i].to != fath)
	{
		dfs(e[i].to, now);
	}
}
int LCA(int x, int y){
	if(depth[x] > depth[y])
	{
		swap(x, y);
	}
	while(depth[x] < depth[y])
	{
		y = fa[y][lg[depth[y] - depth[x]]-1];
	}
	if(x == y) return x;
	for(int k = lg[depth[x]] - 1; k >= 0; --k) if(fa[x][k] != fa[y][k])
	{
		x = fa[x][k], y = fa[y][k];
	}
	return fa[x][0];
}
int main(){
    int n,m,s;scanf("%d%d%d", &n, &m, &s);
    for(int i = 1; i <= n-1; ++i)
    {
    	int x, y; scanf("%d%d", &x, &y);
    	add(x, y);add(y, x);
	}
	for(int i = 1; i <= n; ++i)
	{
		lg[i] = lg[i-1] + (1 << lg[i-1] == i);
	}
	dfs(s, 0);
	for(int i = 1; i <= m; ++i)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", LCA(x, y));
	}
    return 0;
}
