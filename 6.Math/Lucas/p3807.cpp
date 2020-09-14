/*************************************************************************
	> File Name: p3807.cpp
# Author: Tiooo111
# mail: tiooo111@163.com
	> Created Time: 2020年09月13日 星期日 10时22分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int64 long long

int64 P;
int64 C(int64 m, int64 n)
{
	int64 res = 1;
	for(int i = 0; i < m; ++i)
	{
		res *= (n - i);
		res %= P;
	}
	for(int i = 1; i <= m; ++i)
		(res /= i) %= P;
	return res % P;
}
int64 lucas(int64 m, int64 n, int64 p)
{
	if(m == 0) return 1;
	return C(m % p, n % p) * lucas(m / p, n / p, p) % p;
}
int main(){
	int T;
	cin >> T;
	int64 n, m;
	while(T--)
	{
		cin >> n >> m >> P;
		cout<<lucas(m, m + n, P);
	}
    return 0;	
}
