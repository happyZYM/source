//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0301%20%E9%80%92%E5%BD%92%E5%AE%9E%E7%8E%B0%E6%8C%87%E6%95%B0%E5%9E%8B%E6%9E%9A%E4%B8%BE
#include<cstdio>
int main()
{
	int n; scanf("%d",&n);
	for(int st=0;st<(1<<n);st++)
	{
		for(int j=0;j<20;j++) if(st&(1<<j)) printf("%d ",j+1);
		puts("");
	}
	return 0;
}
