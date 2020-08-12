#include<iostream>

const int MOD=101;

int quick(int x,int n,int m){
	int r=1;
	while(n)
	{
		if(n & 1) (r*=x)%=m;
		(x*=x)%=m;
		n>>=1;
	}
	return r;
} 

int main()
{
	int res=0;
	int div=quick(2019,2019,100);
	for(int i=1;i<=11;++i) (res+=quick(i,div,MOD))%=MOD;
	std::cout<<res<<std::endl;
	return 0;
}
