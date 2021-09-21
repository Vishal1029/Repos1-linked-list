#include <iostream>
using namespace std;
int main()
{
	int a=2,b=4,i,j;
	{
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=5;j++)
			{
				
				if(j==(5/2)||i==(5/2+1))
				cout<<b;
				else
				cout<<" ";
			}cout<<"\n";
			b++;
			a=a+2;
		}if(i==(5/2))
		cout<<b;
		b++;
	}
	return 0;
}
