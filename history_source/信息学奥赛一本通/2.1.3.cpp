#include<iostream>
#include<string>
using namespace std;
void swap(string &a,string &b)
{
	string c;
	c=a;
	a=b;
	b=c;
}
void eraseZero(string &a)
{
	while(a[0]=='0'&&a.size()>1) a.erase(0,1);
}
string add_(string a,string b)
{
	string c;
	int ai,bi,j=0,x;
	eraseZero(a);
	eraseZero(b);
	if(b.size()>a.size()) swap(a,b);
	for(ai=a.size()-1,bi=b.size()-1;bi>=0;bi--,ai--)
	{
		x=j+a[ai]+b[bi]-2*'0';
		c=char('0'+x%10)+c;
		j=x/10;
	}
	while(ai>=0)
	{
		x=j+a[ai]-'0';
		c=char('0'+x%10)+c;
		j=x/10;
		ai--;
	}
	if(j) c="1"+c;
	eraseZero(c);
	return c;
}
int main()
{
	string ans="1";
	int n;
	cin>>n;
	for(int i=0;i<n;i++) ans=add_(ans,ans);
	cout<<ans<<endl;
	return 0;
}
