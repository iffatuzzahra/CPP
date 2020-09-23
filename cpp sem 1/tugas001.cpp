#include <iostream>

using namespace std;
int main()
{
	string menu;
	int n;
	int i, k, j;
	cout<<"menu";
	cout<<"\n1=output1 \n2=output2 \n3=output3 \n4=output4";
	cout<<"\npilih menu: ";
	cin>>menu;
	if (menu=="1")
	{cout<<"masukkan nilai :";
		cin>>n;
		for (i=0;i<n;i++)
		{
			for (k=n;k>i;k--)
			{cout<<" x";}
			cout<<endl;
			for (j=0; j<=i; j++)
			{cout<<"  ";}	
		}
		 
	}
	else if (menu=="2")
	{cout<<"masukkan nilai :";
		cin>>n;
		for (i=1;i<=n;i++)
		{
			for (k=0;k<n;k++)
			{cout<<" x";}
			 cout<<endl;	
		}
	}
	else if (menu=="3")
	{cout<<"masukkan nilai :";
		cin>>n;
		for (i=0;i<n;i++)
		{
			if (i%2!=0)
			{
			for (k=0;k<n;k++)
				{cout<<" x";}
			cout<<endl;
			}
			if (i%2!=1)
			{for (k=0;k<n;k++)
				{cout<<" x";} 
			cout<<endl;
			cout<<" ";
			}
		}
	}
	else if (menu=="4")
	{cout<<"masukkan nilai :";
		cin>>n;
		for (int i=n;i>=0;i--)
		{
			for (int k=n;k>i;k--)
			{cout<<"  ";}
			cout<<endl;
			for (int j=1; j<=i; j++)
			{cout<<" x";}
		}
	}
	return 0;
}
