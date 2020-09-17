/*************************************************************************
	> File Name: uva10179.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年09月12日 星期六 16时53分49秒
 ************************************************************************/
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define ll int
int read()//快读
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-48;
		c=getchar();
	}
	return k;
}
ll phi(ll x)
{
	ll res = x, sqr = sqrt(x);
	for(int i = 2; i <= sqr; ++i)
	{
		if(!(x % i))
		{
			res = res / i * (i - 1);
			while(!(x % i)) x /= i;
		}
	}
	if(x > 1) res = res / x * (x - 1);
	return res;
}
int main(){
	ll n = read();
	while(n != 0)
	{
		if(n == 1) printf("0\n");
		else printf("%d\n", phi(n));
		n = read();
	}
    return 0;	
}
