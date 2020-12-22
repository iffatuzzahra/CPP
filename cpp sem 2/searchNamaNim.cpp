#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main ()
{ int i=0,n;
  char kembali;
  bool z=true;
	int pilih,nim[20], carinim;
	char nama[20][40], carinama[10]; 
	
do{
	system ("cls");
	kembali='n'; n=i;
	cout<<"1. INPUT DATA\n2. OUTPUT DATA\n3. CARI DATA BERDASARKAN NIM\n4. CARI DATA BERDASARKAN NAMA\n5. KELUAR\npilih : ";
	cin>>pilih;
	system ("cls"); 
	if (pilih==1)
	{	
		cout<<"INPUT DATA\n\n";
		cout<<"NIM \t: "; cin>>nim[i];
		cout<<"Nama \t: "; cin.ignore(); cin.getline(nama[i],40); 
		i++; 
		kembali='y';
	}  

else if (pilih!=1)
{
	if (pilih==2) 
	{ 
		cout<<"OUTPUT DATA\n";
		for (int a=0;a<n;a++)
		{
			cout<<endl<<"NIM \t: "<<nim[a]<<endl<<"Nama \t: "<<nama[a]<<endl<<endl;
		}
	}
	
	else if (pilih==3)
	{
		cout<<"CARI DATA BERDASARKAN NIM\n\nmasukkan NIM yang ingin dicari : "; cin>>carinim;
		for (int a=0;a<n;a++)
		{
			if (carinim==nim[a]) {cout<<endl<<"NIM \t: "<<nim[a]<<endl<<"Nama \t: "<<nama[a]<<endl; z=false;}
		}
		if (z) cout<<"\ndata tidak ditemukan\n";
	}
	
	else if (pilih==4)
	{
		cout<<"CARI DATA BERDASARKAN NAMA\n\nmasukkan nama yang ingin dicari : "; cin>>carinama;
		for (int a=0;a<n;a++)
		{
			if (strstr(nama[a],carinama)) {cout<<endl<<"NIM \t: "<<nim[a]<<endl<<"Nama \t: "<<nama[a]<<endl; z=false;}
		}
		if (z) cout<<"\ndata tidak ditemukan\n";
	}
	
	else if (pilih==5) return 0;
	
    cout<<"\nkembali ke menu(y/n) :"; cin>>kembali;
	
}
}while (kembali=='y');
}
