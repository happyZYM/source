#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int f;
	while(true)
	{
		cin>>f;
		if(f>90) cout<<"����"<<endl;
		else
		{
			if(f/10==8) cout<<"����"<<endl;
			else
			{
				if(f>=60&&f<80) cout<<"����"<<endl;
				else cout<<"������"<<endl;
			}
		}
	}
}
