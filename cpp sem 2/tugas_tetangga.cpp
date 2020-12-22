
#include <iostream>
using namespace std;

typedef struct 
{
	int kode, harga, jum;
} barang;
typedef struct 
{
	int idtrans, tgltrans;
	barang beli[50][50];
} trans;

int main ()
{
	int x,total[50][50],totrans[50],tobel;
	char y;
	int a,i,b[50],j,c;
	trans doit[10];
	
	totrans[0]=0; tobel=0;
do {
	cout<<"\nSILAHKAN PILIH MENU : \n1.TRANSAKSI PERTAMA\n2.TAMBAHKAN TRANSAKSI\n3.REKAP HASIL DAN TOTAL PEMBELIAN\n\nmasukkan pilihan :"; cin>>x;

	if (x==1){
		cout<<"\nmasukkan jumlah transaksi yang akan dilakukan :"; cin>>a;
		  for (i=0;i<a;i++){
		  cout<<"\tID transaksi "<<i+1<<" :"; cin>>doit[i].idtrans;
		  cout<<"\tTanggal transaksi "<<i+1<<" :"; cin>>doit[i].tgltrans;
		  cout<<"\n\tmasukkan jumlah barang yang ditransaksi :"; cin>>b[i];
			 for (j=0;j<b[i];j++){
			 cout<<"\n\t\tKode barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].kode;
			 cout<<"\t\tHarga barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].harga;
			 cout<<"\t\tJumlah Barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].jum;
			 }
		  }
	}
	
	else if (x==2){
		  cout<<"masukkan jumlah transaksi yang akan ditambahkan :"; cin>>c; 
		  a=a+c;
		  for (i=i;i<a;i++){
		  cout<<"\tID transaksi "<<i+1<<" :"; cin>>doit[i].idtrans;
		  cout<<"\tTanggal transaksi"<<i+1<<" :"; cin>>doit[i].tgltrans;
		  cout<<"\n\tmasukkan jumlah barang yang ditransaksi :"; cin>>b[i];
			 for (j=0;j<b[i];j++){
			 cout<<"\n\t\tKode barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].kode;
			 cout<<"\t\tHarga barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].harga;
			 cout<<"\t\tJumlah Barang "<<j+1<<" :"; cin>>doit[i].beli[i][j].jum;
			 }
		  }
	}
	
	else if (x==3){
		  cout<<"hasil rekapan anda : "<<endl;
		  for (i=0;i<a;i++){
		  
		  cout<<"\n\tID transaksi "<<i+1<<" :"<<doit[i].idtrans<<endl;
		  cout<<"\tTanggal transaksi "<<i+1<<" :"<<doit[i].tgltrans<<endl;
			 for (j=0;j<b[i];j++){
			 cout<<"\n\t\tKode barang "<<j+1<<" :"<<doit[i].beli[i][j].kode<<endl;
			 cout<<"\t\tHarga barang "<<j+1<<" :"<<doit[i].beli[i][j].harga<<endl;
			 cout<<"\t\tJumlah Barang "<<j+1<<" :"<<doit[i].beli[i][j].jum<<endl;
			 total[i][j]=(doit[i].beli[i][j].harga)*(doit[i].beli[i][j].jum);
			 totrans[i]=totrans[i]+total[i][j];
			 cout<<"\n\tTotal harga :"<<total[i][j]<<endl;
			 }
		  cout<<"\nTotal pembelian transaksi "<<i+1<<" :"<<totrans[i]<<endl;
		  tobel=tobel+totrans[i];
		  }		
		  cout<<"\nTOTAL SELURUH TRANSAKSI : "<<tobel<<endl;
	}
	
cout<<"\n\ningin kembali ke menu ?(y/t) :"; cin>>y;
} while (y=='y'||y=='Y');
	
	 
}
