#include <iostream>
using namespace std;


typedef struct
{
	char nama[30];
	float suara,persen;
	
} paslon;
paslon ok[10];

paslon save;
void masuk(int n) 
{
	
	for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if (ok[i].persen>ok[j].persen)
				{
					save=ok[i]; ok[i]=ok[j]; ok[j]=save;
				}
			}
		}
		cout<<"jumlah perolehan suara : \n";
		for (int i=0;i<n;i++)
		{
			cout<<ok[i].nama<<":"<<ok[i].persen<<"%"<<endl;
		} 
	
}
int main ()
{
	char y;
	int n,total=0,i=0;
	do{
	cout<<"masukkan jumlah paslon : "; cin>>n; n=n+i;
	for (i=i;i<n;i++)
	{
		cout<<"nama paslon : "; cin.ignore (); cin.getline(ok[i].nama,sizeof(ok[i].nama));
		cout<<"jumlah suara : "; cin>>ok[i].suara; 
		total=total+ok[i].suara;
		
	}
	for (int i=0;i<n;i++)
	{
		ok[i].persen=ok[i].suara/total*100.0;
	}
	masuk (n);
	
	cout<<"tambahkan pasangan ?(y/n): "; cin>>y;
	} while (y=='y');
	
}

