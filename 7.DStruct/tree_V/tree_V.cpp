#include <cstdio>
using namespace std;
const int MAXN = 500005;
int n, m, tree_V[MAXN];

int lowbit(int x){
	return x & -x;
}
void update(int ind, int x){
	while(ind <= n)
	{
		tree_V[ind] += x;
		ind += lowbit(ind);
	}
}
int getSum(int ind){
	int res = 0;
	while(ind)
	{
		res += tree_V[ind];
		ind -= lowbit(ind);
	}
	return res;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int x; scanf("%d", &x);
		update(i, x);
	}
	while(m--)
	{
		int no, x, y;
		scanf("%d%d%d", &no, &x, &y);
		if(no == 1)
		{
			update(x, y);
		}
		else
		{
			printf("%d\n", getSum(y) - getSum(x - 1)); 
		} 
		
	}
	return 0;
} 
