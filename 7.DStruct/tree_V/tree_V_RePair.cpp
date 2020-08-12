/*************************************************************************
	> File Name: tree_V_RePair.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年08月10日 星期一 20时52分54秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
struct node{
	int val, num;
}A[MAXN];
int n, tree_V[MAXN], rank_[MAXN];
int lowbit(int x){
	return x & -x;
}
void  update(int ind, int x){
	while(ind <= n)
	{
		tree_V[ind] += x;
		ind += lowbit(ind);
	}
	return;
}
int getSum(int ind){
	int ans = 0;
	while(ind)
	{
		ans += tree_V[ind];
		ind -= lowbit(ind);
	}
	return ans;
}
bool cmp1(node x, node y){
	if(x.val == y.val) return x.num > y.num;
	return x.val > y.val;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &A[i].val);
		A[i].num = i;
	}
	sort(A + 1, A + 1 + n, cmp1);
	long res = 0;
	for(int i = 1; i <= n; ++i)
	{
		update(A[i].num, 1);
		res += getSum(A[i].num - 1);
	}
	printf("%ld\n", res);
    return 0;	
}
