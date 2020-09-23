#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

typedef struct typenode *typeptr;
struct typenode {
	// struk yang digunakan di stack
	char namabarang[30];
	typeptr next;
	
	// struk yang digunakan di queue
	int noantrian;
	char nama[20];
	char alamat[30];
	char keluhan[50];
	char solusi[60];
	char notelp[15];
	char bingkisan[30];
	typeptr belakang;
};
typeptr tunjuk,pilih;
typeptr awalstack, akhirstack;
typeptr awalqueue, akhirqueue;
typeptr awallist,akhirlist;
int jlhstack; //digunakan saat menampilkan stack
int jlhantrian,sisaantrian; // untuk menghitung nomor antrian secara otomatis dan sisa antrian 

void viewlist();
void menucs();
void pop();
void dequeue();
void enqueue();
void batalantri();
void queue();
void push ();
void stack ();

int main()
{
	jlhstack=0;// dignakan saat menampilkan stack
	int menu;
	sisaantrian=0;
	jlhantrian=0;
	stack(); // membuat stack
	queue(); // membuat antrian 	
	
	do{
		system("cls");
		cout<<"MENU PELAYANAN KELUHAN PELANGGAN "<<endl<<endl;
		cout<<"1. AMBIL ANTRIAN"<<endl; //apabila ingin memasukkan pelanggan ke dalam antrian 
		cout<<"2. BATAL MENGANTRI"<<endl;
		cout<<"3. PANGGIL ANTRIAN BERIKUTNYA"<<endl; //memaggil antrian
		cout<<"4. MENU COSTUMER SERVICE"<<endl; //menu khusus cs
		cout<<"5. EXIT\n PILIH : "; cin>>menu;
		
		if (menu==1){
			enqueue(); 
		}
		else if (menu==2){
			batalantri();
		}
		else if (menu==3){
			dequeue(); 
		}
		else if (menu==4){
			menucs();
		}
		else if (menu==5) {
			return (0);
		}
		else cout<<"Menu Tidak tersedia "<<endl;
		
	} while(true);
	
}

void stack ()
{
	tunjuk=awalstack;
	akhirstack=awalstack;
	awalstack=NULL;
	
	cout<<"\tSELAMAT DATANG CUSTOMER SERVICE"<<endl;
	push (); //stack diisi terlebih dahulu
	cout<<"TERIMA KASIH\nSELAMAT BEKERJA\n"<<endl;
	system("pause");
}

void push ()
{
	int jlhbonus;
	cout<<"Silahkan masukkan  jumlah bingkisan yang disediakan : "; cin>>jlhbonus;
	cin.ignore();
	for (int i=0;i<jlhbonus;i++) { //jlh tumpukan sesuai jumlah barang yang dimasukkan 
		//dibuat list baru untuk setiap stack
		tunjuk=(typenode *) malloc(sizeof(typenode)); 
		cout<<"Masukkan nama barang ke-"<<i+1<<" : "; cin.getline(tunjuk->namabarang, sizeof (tunjuk->namabarang));
		cout<<endl;
		if (awalstack==NULL) awalstack=tunjuk;
		else {
			tunjuk->next=akhirstack;
			akhirstack=tunjuk;
		}
		jlhstack++; //digunakan saat menampilkan stack
	}
}
void queue()
{ 
	awalqueue=(typenode *) malloc(sizeof(typenode));
	awalqueue=NULL;
	akhirqueue=awalqueue;
}

void enqueue()
{
	//dibuat queue baru setiap mengantri
	tunjuk=(typenode *) malloc(sizeof(typenode));
	tunjuk->noantrian=jlhantrian+1; //menambahkan banyaknya pengantri  sekaligus menjadi no antrian
	if (jlhantrian==0) //apabila atrian belum ada
		awalqueue=tunjuk; 
	else 
		akhirqueue->belakang=tunjuk;
		
	akhirqueue=tunjuk;
	akhirqueue->belakang=NULL;
	jlhantrian++;
	sisaantrian++;
	
	cout<<endl<<"Nomor antrian anda : "<<tunjuk->noantrian<<endl;
	system("pause");
}

void dequeue()
{ //pada proses ini node antrian diisi dengan data, dikeluarkan dari antrian, dan dipindahkan kepada list pelanggan yg telah dilayani
	tunjuk=awalqueue;
	//cs mengisi data dan keluhan pelanggan saat melakukan panggilan
	cin.ignore();
	cout<<"Nama Pelanggan : "; cin.getline(tunjuk->nama, sizeof (tunjuk->nama)); 
	cout<<"Alamat Pelanggan : "; cin.getline(tunjuk->alamat, sizeof (tunjuk->alamat)); 
	cout<<"No Telp Pelanggan : "; cin.getline(tunjuk->notelp, sizeof (tunjuk->notelp)); 
	cout<<"Keluhan Pelanggan : "; cin.getline(tunjuk->keluhan, sizeof (tunjuk->keluhan)); 
	cout<<"Solusi yang Kami Berikan : "; cin.getline(tunjuk->solusi, sizeof (tunjuk->solusi));
	strcpy(tunjuk->bingkisan,akhirstack->namabarang); //bingkisan diambil dari stack barang
	cout<<"Bingkisan Tanda Permintaan Maaf : "<<tunjuk->bingkisan<<endl;
	
	pop(); //bingkisan pada stack diambil dan di pop dari stack
	
	if (sisaantrian==1||tunjuk->noantrian==1) { //apabila antrian tersisa 1 atau bernomor antrian pertama
		if (tunjuk->noantrian==1) //apabila yang dipanggil antrian pertama kali
			awallist=tunjuk; 
		if (sisaantrian==1) { //apabila antrian tersisa 1
			akhirlist->belakang=tunjuk;
			queue(); //dibuat list baru untuk antrian karna antrian habis dan list dipindahkan
			cout<<"Antrian habis,, Silahkan menunggu pelanggan berikutnya "<<endl;
		}
		else { //apabila yg dipanggil bukan antrian pertama kali
			awalqueue=awalqueue->belakang;
		}
	}
	else { //sisa antrian lebih dari 1 
		awalqueue=awalqueue->belakang;
		akhirlist->belakang=tunjuk;
	}
	akhirlist=tunjuk;
	akhirlist->belakang=NULL;
	sisaantrian--;
	system("pause");
}

void batalantri()
{
	int batal;
	cout<<endl<<"Masukkan Nomor Antrian : "; cin>>batal;
	pilih=awalqueue;
	while(pilih!=NULL&&pilih->noantrian!=batal) { //mencari letak antrian
		tunjuk=pilih;
		pilih=pilih->belakang;
	}
	if (pilih==NULL) cout<<"Nomor Antrian Tidak Ditemukan"<<endl; 
	else {
		if (pilih==awalqueue) //apabila nomor yang akan dihapus ada di awal antrian 
			awalqueue=pilih->belakang;
		else if (pilih==akhirqueue) { //apabila nomor yang akan dihapus ada di akhir antrian 
			akhirqueue=tunjuk;
			akhirqueue->belakang=NULL;
		}
		else //apabila nomor yang akan dihapus ada di tengan antrian 
			tunjuk->belakang=pilih->belakang;
		cout<<"Nomor Antrian "<<pilih->noantrian<<" Telah Keluar"<<endl;
		free(pilih);
		if (sisaantrian==1) 
			cout<<"Antrian habis,, Silahkan menunggu pelanggan berikutnya "<<endl;
		sisaantrian--;
	}
}

void pop()
{
	pilih=akhirstack;
	if (jlhstack==1){ //apabila stack sudah tersisa 1 bingkisan
		awalstack=NULL;
		cout<<"Persediaan bingkisan baru saja habis.. Silahkan isi kembali melalui menu CS"<<endl;
	}
	else { //apabila tersisa lebih dari 1 bingkisan 
		akhirstack=akhirstack->next;
		free(pilih);
	}
	jlhstack--;
}

void menucs()
{ //menu ini merupakan menu customer service 
	bool kembali=false;
	int menu;
	do {
		system("cls");
		cout<<"MENU COSTUMER SERVICE "<<endl<<endl;
		cout<<"1. LIHAT ANTRIAN TERSISA"<<endl; //melihat antrian yang belum di panggil
		cout<<"2. LIHAT PELAYANAN HARI INI"<<endl; //lihat pelayanan yang telah dilakukan 
		cout<<"3. TAMBAH STOK BINGKISAN "<<endl; 
		cout<<"4. LIHAT SISA STOK BINKISAN"<<endl;
		cout<<"5. KEMBALI\n PILIH : "; cin>>menu;
	
		if (menu==1){
			tunjuk=awalqueue;
			for (int i=0;i<sisaantrian;i++) {
				cout<<"Antrian "<<i+1<<" >> Nomor Antrian 0"<<tunjuk->noantrian<<endl;
				tunjuk=tunjuk->belakang;
			}
		}
		if (menu==2){
			viewlist();
		}
		if (menu==3){
			push();
		}
		if (menu==4){
			cout<<"Sisa stok barang = "<<jlhstack<<endl;
		}
		if (menu==5){
			kembali=true; // agar perulangan pada menu cs berhenti
		}
		
	system("pause");
	} while(!kembali);
}

void viewlist()
{
	tunjuk=awallist;
	
	while(tunjuk!=NULL) {
		cout<<"Nomor Antrian : "<<tunjuk->noantrian<<endl;
		cout<<"Nama Pelanggan : "<<tunjuk->nama<<endl; 
		cout<<"Alamat Pelanggan : "<<tunjuk->alamat<<endl; 
		cout<<"No Telp Pelanggan : "<<tunjuk->notelp<<endl; 
		cout<<"Keluhan Pelanggan : "<<tunjuk->keluhan<<endl; 
		cout<<"Solusi yang Kami Berikan : "<<tunjuk->solusi<<endl;
		cout<<"Bingkisan Tanda Permintaan Maaf : "<<tunjuk->bingkisan<<endl;
		tunjuk=tunjuk->belakang;
		cout<<endl;
	}
}
