#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	float a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if(!((a+b>c)&&(a+c>b)&&(b+c>a))) cout<<"No!"<<endl;
		else
		{
			if(a==b&&a==c) cout<<"�ȱ�������"<<endl;
			else
			{
				if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)) cout<<"ֱ��������"<<endl;
				else cout<<"һ��������"<<endl;
			}
		}
	}
}
