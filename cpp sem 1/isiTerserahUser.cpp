#include <iostream>

using namespace std;
int main()
{
	char barang[10];
	int jumlah1,jumlah2,jumlah3;
	int harga1,harga2,harga3;
	int bayar,kembali;
	
	cout<<"nama barang1\t : ";
	cin>> barang;
	cout<<"\njumlah1\t : ";
	cin>> jumlah1;
	cout<<"\nharga1\t : ";
	cin>> harga1;
	
	cout<<"\n\nnama barang2\t : ";
	cin>> barang;
	cout<<"\njumlah2\t : ";
	cin>> jumlah2;
	cout<<"\nharga2\t : ";
	cin>> harga2;
		
	cout<<"\n\nnama barang3\t : ";
	cin>> barang;
	cout<<"\njumlah3\t : ";
	cin>> jumlah3;
	cout<<"\nharga3\t : ";
	cin>> harga3;
	
	int total1=harga1*jumlah1;
	int total2=harga2*jumlah2;
	int total3=harga3*jumlah3;
	int total=total1+total2+total3;
	cout<<"\n\ntotal harga\t : "<<total;
	cout<<"\nbayar\t : ";
	cin>> bayar;
	kembali=bayar-total;
	cout<<"\nkembalian\t : "<<kembali;
	
	return 0;
}

