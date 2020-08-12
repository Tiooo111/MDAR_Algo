#include<iostream>
#include<cstdio>
using namespace std;

int a[500010],tree[500010],n;

	
inline int lowbit(int x){
	return x&-x;
}

void add1(int l,int x){
	for(int i=l;i<=n;i+=lowbit(i)) tree[i]+=x; 
}
int sum(int i){
	int s=0;
	for(;i;i-=lowbit(i)) s+=tree[i];
	return s;
}

int main(){
	int M;
	cin>>n>>M;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);

	}
	int f,l,r,x;
	while(M--)
	{
		cin>>f;
		if(f==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			add1(l,x);
			add1(r+1,-x);
		}
		else
		{
			scanf("%d",&l);
			printf("%d\n",a[l]+sum(l));
		}
	}
	return 0;
}
