#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	char nama[50],nim[20];
	
} siap; 
siap data[10];


int main ()
{
	int pilih,jumlah=0,i=0;
	char namafile[30];
	cout<<"nama file :"; cin>>namafile;
	do { 
	cout<<"menu :\n1. input\n2. output\n pilih : "; cin>>pilih;
	
	if(pilih==1){
		cout<<"jumlah data :"; cin>>jumlah;
		jumlah=jumlah+i;
		ofstream masuk;
		masuk.open(namafile,ios::app);
		for(i=i; i<jumlah; i++){
		cout<<"masukkan nama :"; cin.ignore(); cin.getline(data[i].nama,sizeof(data[i].nama));
		//cin>>data[i].nama;
		cout<<"masukkan nim : "; cin>>data[i].nim;
		masuk<<data[i].nama<<endl;
		masuk<<data[i].nim<<endl;
		}
		masuk.close();
	}
	else{
		ifstream keluar;
		keluar.open(namafile); 
		for(int a=0; a<jumlah; a++){
			if (keluar.eof()) {
			//keluar.get(data[a].nama);
			keluar>>data[a].nama;
			keluar>>data[a].nim;
			
			}
		}
		for(int a=0; a<jumlah; a++){
		cout<<"nama : "<<data[a].nama<<endl;
		cout<<"nim : "<<data[a].nim<<endl; 
		
		}
		keluar.close(); 
	}
	} while (true);
}
