#include<cstdio>
#include<algorithm>
using std::swap;
int n,a[100005];
void sort(int L,int R)
{
	if(L>=R) return;
	int k=a[(L+R)>>1],p1=L,p2=R;
	do
	{
		while(a[p1]<k) p1++;
		while(a[p2]>k) p2--;
		if(p1<=p2)
		{
			swap(a[p1],a[p2]);
			p1++;
			p2--;
		}
	}
	while(p1<=p2);
	sort(L,p2);
	sort(p1,R);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	sort(0,n-1);
	for(int i=0;i<n;i++)
	{
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
