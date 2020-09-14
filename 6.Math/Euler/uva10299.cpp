#include<iostream>
#include<cstdio>
using namespace std;

int n;

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

void fhi(int N)//
{
	int k=N;
	if(N==1)
	{
		printf("0\n");
		return;
	}
	for(int i=2;i*i<=N;++i)//分解质因数
	{
		if(N%i==0)
		{
			k=(k/i)*(i-1);//欧拉公式
			while(N%i==0)
			{
				N=N/i;
			}
		}
	}
	if(N>1)//N经过上面处理后可能会有不等于1的情况
	{
		k=(k/N)*(N-1);//欧拉公式
	}
	printf("%d\n",k);
	return;
}

int main()
{
	n=read();
	while(n!=0)
	{
		fhi(n);
		n=read();
	}
	return 0;
}
