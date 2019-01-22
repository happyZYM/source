#include<cstdio>
#include<cstring>
int n,res;
int a[40005],b[40005];
void GB(int *a,int *b,int len)
{
	if(len<=1) return;
	int M=len/2;
	GB(a,b,M); GB(a+M,b+M,len-M);
	int p1=0,p2=M,p=0;
	while(p1<M&&p2<len)
	{
		if(a[p1]<=a[p2]) b[p++]=a[p1++];
		else res+=M-p1,b[p++]=a[p2++];
	}
	while(p1<M) b[p++]=a[p1++];
	while(p2<len) b[p++]=a[p2++];
	memcpy(a,b,sizeof(int)*len);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	GB(a,b,n);
	printf("%d\n",res);
	return 0;
}
