#include <iostream>
using namespace std;

typedef struct 
{
	int kode, harga, jum;
} barang;
typedef struct 
{
	int idtrans, tgltrans;
	barang beli[100][100];
} trans;

int main ()
{
	int x;
	int a,i,b[100],j;
	trans doit[100];
	cout<<"silahkan pilih menu : \n1.transaksi pertama\n2.tambahkan transaksii\n3.rekap hasil\nmasukkan pilihan :"; cin>>x;
	
	if (x==1){
		cout<<"masukkan jumlah transaksi yang akan dilakukan :"; cin>>a;
		  for (i=0;i<a;i++){
		  cout<<"ID transaksi "<<i+1<<" :"; cin>>doit[i].idtrans;
		  cout<<"Tanggal transaksi "<<i+1<<" :"; cin>>doit[i].tgltrans;
		  cout<<"masukkan jumlah barang yang ditransaksi :"; cin>>b[i];
			 for (j=0;j<b[i];j++){
			 cout<<"Kode barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].kode;
			 cout<<"Harga barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].harga;
			 cout<<"Jumlah Barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].jum;
			 }
		  }
	}
	
	else if (x==2){ cout<<"belum dikerjakan ";
	}
	else if (x==3){
		  for (i=0;i<a;i++){
		  cout<<"ID transaksi "<<i+1<<" :"<<doit[i].idtrans<<endl;
		  cout<<"Tanggal transaksi "<<i+1<<" :"<<doit[i].tgltrans<<endl;
		  cout<<"\tjumlah barang yang ditransaksi :"<<b[i]<<endl;
			 for (j=0;j<b[i];j++){
			 cout<<"Kode barang "<<j+1<<" :"<<doit[i].beli[i][j].kode<<endl;
			 cout<<"Harga barang "<<j+1<<" :"<<doit[i].beli[i][j].harga<<endl;
			 cout<<"Jumlah Barang "<<j+1<<" :"<<doit[i].beli[i][j].jum<<endl;
			 }
		  }
	}
	
	 
}
