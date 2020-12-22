#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	int pilih,jumlah;
	char namafile[30],data[30][30], namafile2[30];
	
	do { 
	cout<<"menu :\n1. input\n2. output\n pilih : "; cin>>pilih;
	
	if(pilih==1){
		cout<<"nama file :"; cin>>namafile;
		cout<<"jumlah data :"; cin>>jumlah;
		ofstream masuk;
		masuk.open(namafile,ios::app);
		for(int i=0; i<jumlah; i++){
		cout<<"masukkan nama :"; cin>>data[i];
		masuk<<data[i]<<endl;
		}
		masuk.close();
	}
	else{
		cout<<"nama file :"; cin>>namafile;
		ifstream keluar;
		ifstream keluar2;
		keluar.open(namafile);int  i=0;
		keluar2.open(namafile2);
		while (keluar>>data[i]){
		cout<<"nama : "<<data[i]<<endl; i++;
		}
		int j=0;
		while (keluar2>>data[j]){
		cout<<"nama : "<<data[j]<<endl; j++;
		}
		keluar.close();
		keluar2.close();
	}
	} while (true);
}
