#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string a;
	while(true)
	{
		cin>>a;
		cout<<a<<"��"<<a.size()<<"λ��"<<endl;
		for(int i=0;i<a.size();i++)
		{
			switch(i+1)
			{
				case 1:cout<<"��λ ";break;
				case 2:cout<<"ʮλ ";break;
				case 3:cout<<"��λ ";break;
				case 4:cout<<"ǧλ ";break;
			}
			cout<<a[a.size()-i-1]<<endl;
		}
		cout<<endl;
	}
}
