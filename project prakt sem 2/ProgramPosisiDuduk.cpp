#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef struct
{
	char nama[50];
	char panggilan[50];
	int nim;
	char lahir[50];
	char alamat[50];
	int posisikolom;
	int posisibaris;
	
}data;

data mahasiswa[100],save;
int jumlahdata,jlhdata;

void input();
void output();
void urutkan ();
void urut_nama();
void urut_lahir ();
void urut_nim(data mahasiswa[],int awal,int akhir);
void cari ();
void tempatduduk();
void dudukdisini(int *i);

int main()
{
	
	ifstream keluar_jlhdata;
	keluar_jlhdata.open ("jumlahdata.txt");
	keluar_jlhdata>>jumlahdata;
	keluar_jlhdata.close();

	int pilih;
	do
	{
		cout<<"==================================================="<<endl;
		cout<<"\t\tMENU"<<endl;
		cout<<"==================================================="<<endl<<endl;
		cout<<"1. INPUT DATA MAHASISWA\n2. OUTPUT DATA MAHASISWA\n3. CARI TEMPAT DUDUK MAHASISWA\n4. URUTAN TEMPAT DUDUK MAHASISWA\n5. KELUAR\n\n";
		cout<<"\n-Masukkan Menu Pilihan Anda : "; cin>>pilih;
		system("cls");
		switch(pilih)
		{
			case 1 :
				input ();
				urutkan ();
			break;
			//	
			case 2 :
				output ();
			break;
			//
			case 3 :
				cari();
			break;
			//
			case 4 :
				tempatduduk();
			break;
			//
			case 5 :
				return 0;
			break;
		}
		cout<<endl;
		system("pause");
		
		system("cls");
	}
	while(true);
}

void input()
{
	
	cout<<"\n-Masukkan jumlah siswa yang akan menempati kelas : "; cin>>jlhdata; 
	jlhdata=jumlahdata+jlhdata; cin.ignore();
	for(int x=jumlahdata;x<jlhdata;x++)
	{
		cout<<"Data mahasiswa ke-"<<x+1<<endl;
		cout<<"Masukkan Nama Lengkap \t\t: "; cin.getline(mahasiswa[x].nama,sizeof(mahasiswa[x].nama));
		cout<<"Masukkan Nama Panggilan \t: "; cin>>mahasiswa[x].panggilan;
		cout<<"Masukkan NIM \t\t\t: "; cin>>mahasiswa[x].nim;
		cout<<"Masukkan Tanggal Lahir(yy/mm/dd): "; cin.ignore(); cin.getline(mahasiswa[x].lahir,sizeof(mahasiswa[x].lahir));
		cout<<"Masukkan Alamat \t\t: "; cin.getline(mahasiswa[x].alamat,sizeof(mahasiswa[x].alamat));
		cout<<endl;

	}
	for(int x=jumlahdata;x<jlhdata;x++)
	{
		ofstream masuk;
		masuk.open ("dataduduk1.txt",ios::app);
		masuk<<mahasiswa[x].nama<<endl;
		masuk<<mahasiswa[x].panggilan<<endl;
		masuk<<mahasiswa[x].nim<<endl;
		masuk<<mahasiswa[x].lahir<<endl;
		masuk<<mahasiswa[x].alamat<<endl;
		masuk.close();
	}
	
	ofstream masuk_jlhdata;
	masuk_jlhdata.open ("jumlahdata.txt");
	masuk_jlhdata<<jlhdata;
	masuk_jlhdata.close();
	
	
}

void output()
{
	
	ifstream keluar_jlhdata;
	keluar_jlhdata.open ("jumlahdata.txt");
	keluar_jlhdata>>jumlahdata;
	keluar_jlhdata.close();
	
	
	ifstream keluar;
	keluar.open ("dataduduk1.txt");
	keluar.eof();
	for (int i=0;i<jumlahdata;i++)
	{ 
		keluar.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
		keluar>>mahasiswa[i].panggilan;
		keluar>>mahasiswa[i].nim;
		keluar.ignore();
		keluar.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
		keluar.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
		
	}
	keluar.close();
	
	for(int i=0;i<jumlahdata;i++)
	{
			cout<<"Data mahasiswa ke-"<<i+1<<endl;
			cout<<"Nama Lengkap \t\t: "<<mahasiswa[i].nama<<endl;
			cout<<"Nama Panggilan \t\t: "<<mahasiswa[i].panggilan<<endl;
			cout<<"NIM \t\t\t: "<<mahasiswa[i].nim<<endl;
			cout<<"Tanggal Lahir(yy/mm/dd) : "<<mahasiswa[i].lahir<<endl;
			cout<<"Alamat \t\t\t: "<<mahasiswa[i].alamat<<endl;
			cout<<endl;
	}
}

void urutkan ()
{
	
	ifstream keluar_jlhdata;
	keluar_jlhdata.open ("jumlahdata.txt");
	keluar_jlhdata>>jumlahdata;
	keluar_jlhdata.close();
	
	ifstream keluar;
	keluar.open ("dataduduk1.txt");
	keluar.eof();
	for (int i=0;i<jumlahdata;i++)
	{
		keluar.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
		keluar>>mahasiswa[i].panggilan;
		keluar>>mahasiswa[i].nim;
		keluar.ignore();
		keluar.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
		keluar.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
		
	}
	keluar.close();
	
	int awal,akhir; 
	awal=0; akhir=jumlahdata-1;
	
	urut_nama();
	urut_lahir();
	urut_nim(mahasiswa,awal,akhir);
	
}

void urut_nama()
{
	for(int i=0;i<jumlahdata;i++)
	{
 
		int j,bd;
		j=i;
		for(int k=i+1;k<jumlahdata;k++)
		{
			 bd=strcmp(mahasiswa[j].nama,mahasiswa[k].nama);
			 if(bd==1) j=k;       
		}
		if(j!=i)
		{
			save=mahasiswa[i]; mahasiswa[i]=mahasiswa[j]; mahasiswa[j]=save;
		}
	}

		int i=0;
		for (int a=1;a<=4;a++)
		{
			for (int b=1;b<=5;b++)
			{
				if (i<jumlahdata)
				{
				mahasiswa[i].posisibaris=a;
				mahasiswa[i].posisikolom=b;
				}
				i++;
			}
		}
	
	ofstream masuk_bulan12;
	masuk_bulan12.open ("bulan12.txt");
	for(int i=0;i<jumlahdata;i++)
	{
	
	masuk_bulan12<<mahasiswa[i].nama<<endl;
	masuk_bulan12<<mahasiswa[i].panggilan<<endl;
	masuk_bulan12<<mahasiswa[i].nim<<endl;
	masuk_bulan12<<mahasiswa[i].lahir<<endl;
	masuk_bulan12<<mahasiswa[i].alamat<<endl;
	masuk_bulan12<<mahasiswa[i].posisibaris<<endl;
	masuk_bulan12<<mahasiswa[i].posisikolom<<endl;
	}
	masuk_bulan12.close();

}

void urut_lahir()
{
	//maret-april //selection sort
	
	for(int i=0;i<jumlahdata;i++)
	{
 
		int j,bd;
		j=i;
		for(int k=i+1;k<jumlahdata;k++)
		{
			 bd=strcmp(mahasiswa[j].lahir,mahasiswa[k].lahir);
			 if(bd==1) j=k;       
		}
		if(j!=i)
		{
			save=mahasiswa[i]; mahasiswa[i]=mahasiswa[j]; mahasiswa[j]=save;
		}
	}
	
		int i=0; 
		for (int a=1;a<=4;a++)
		{
			for (int b=1;b<=5;b++)
			{
				if (i<jumlahdata)
				{
				mahasiswa[i].posisibaris=a;
				mahasiswa[i].posisikolom=b;
				}
				i++;
			}
		}
	
	ofstream masuk_bulan34;
	masuk_bulan34.open ("bulan34.txt");
	for(int i=0;i<jumlahdata;i++)
	{
	
	masuk_bulan34<<mahasiswa[i].nama<<endl;
	masuk_bulan34<<mahasiswa[i].panggilan<<endl;
	masuk_bulan34<<mahasiswa[i].nim<<endl;
	masuk_bulan34<<mahasiswa[i].lahir<<endl;
	masuk_bulan34<<mahasiswa[i].alamat<<endl;
	masuk_bulan34<<mahasiswa[i].posisibaris<<endl;
	masuk_bulan34<<mahasiswa[i].posisikolom<<endl;
	}
	masuk_bulan34.close();
}



void urut_nim(data mahasiswa[],int awal,int akhir)
{
	
	//mei-juni //bubble sort
	data tengah;
	int low,high;
		low=awal; high=akhir;
		tengah=mahasiswa[(awal+akhir)/2];
		do
		{
			while (mahasiswa[low].nim<tengah.nim) low++;
			while (mahasiswa[high].nim>tengah.nim) high--;
			
			if (low<=high)
			{
				save=mahasiswa[low]; 
				mahasiswa[low++]=mahasiswa[high]; 
				mahasiswa[high--]=save;
			}
		} while (low<=high);
		if (awal<high) urut_nim(mahasiswa,awal,high);
		if (low<akhir) urut_nim(mahasiswa,low,akhir);	
		//	
		int i=0;
		for (int a=1;a<=4;a++)
		{
			for (int b=1;b<=5;b++)
			{
				if (i<jumlahdata)
				{
				mahasiswa[i].posisibaris=a;
				mahasiswa[i].posisikolom=b;
				}
				i++;
			}
		}
	
	ofstream masuk_bulan56;
	masuk_bulan56.open ("bulan56.txt");
	for(int i=0;i<jumlahdata;i++)
	{
	masuk_bulan56<<mahasiswa[i].nama<<endl;
	masuk_bulan56<<mahasiswa[i].panggilan<<endl;
	masuk_bulan56<<mahasiswa[i].nim<<endl;
	masuk_bulan56<<mahasiswa[i].lahir<<endl;
	masuk_bulan56<<mahasiswa[i].alamat<<endl;
	masuk_bulan56<<mahasiswa[i].posisibaris<<endl;
	masuk_bulan56<<mahasiswa[i].posisikolom<<endl;
	}
	masuk_bulan56.close();
}

void cari ()
{
	ifstream keluar_jlhdata;
	keluar_jlhdata.open ("jumlahdata.txt");
	keluar_jlhdata>>jumlahdata;
	keluar_jlhdata.close();
	
	int bulan;
	char cari[50],y;
do
{
	system ("cls");
	cout<<"\n-CARI TEMPAT DUDUK BULAN :\n";
	cout<<"\n1.JANUARI dan FEBRUARI\n2.MARET dan APRIL\n3.MEI dan JUNI\n\n-Pilih Bulan : "; cin>>bulan;
	cout<<"\n-Masukkan Nama Yang Ingin Dicari : "; cin>>cari;
		bool ketemu=false;
	if (bulan==1)
	{
		ifstream keluar_bulan12;
		keluar_bulan12.open ("bulan12.txt");
		keluar_bulan12.eof();
		for (int i=0;i<jumlahdata;i++)
		{
			keluar_bulan12.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan12>>mahasiswa[i].panggilan;
			keluar_bulan12>>mahasiswa[i].nim;
			keluar_bulan12.ignore();
			keluar_bulan12.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan12.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan12>>mahasiswa[i].posisibaris;
			keluar_bulan12>>mahasiswa[i].posisikolom;
			keluar_bulan12.ignore();
		}
		keluar_bulan12.close();
		
		for (int i=0;i<jumlahdata;i++)
		{
			if (strstr(mahasiswa[i].nama,cari)) 
			{
				dudukdisini (&i); ketemu=true;
			}
		}
		if (!ketemu) cout<<"\nMOHON MAAF NAMA YANG ANDA CARI TIFAK DITEMUKAN!\n";
		
	}
	
	else if (bulan==2)
	{
		ifstream keluar_bulan34;
		keluar_bulan34.open ("bulan34.txt");
		keluar_bulan34.eof();
		for (int i=0;i<jumlahdata;i++)
		{	
			keluar_bulan34.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan34>>mahasiswa[i].panggilan;
			keluar_bulan34>>mahasiswa[i].nim;
			keluar_bulan34.ignore();
			keluar_bulan34.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan34.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan34>>mahasiswa[i].posisibaris;
			keluar_bulan34>>mahasiswa[i].posisikolom;
			keluar_bulan34.ignore();
		}
		keluar_bulan34.close();
		
		for (int i=0;i<jumlahdata;i++)
		{
			if (strstr(mahasiswa[i].nama,cari)) 
			{
				dudukdisini (&i); ketemu=true;
			}
		}
		if (!ketemu) cout<<"\nMOHON MAAF NAMA YANG ANDA CARI TIFAK DITEMUKAN!\n";
	}
	
	else if (bulan==3)
	{
		ifstream keluar_bulan56;
		keluar_bulan56.open ("bulan56.txt");
		keluar_bulan56.eof();
		for (int i=0;i<jumlahdata;i++)
		{
			keluar_bulan56.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan56>>mahasiswa[i].panggilan;
			keluar_bulan56>>mahasiswa[i].nim;
			keluar_bulan56.ignore();
			keluar_bulan56.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan56.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan56>>mahasiswa[i].posisibaris;
			keluar_bulan56>>mahasiswa[i].posisikolom;
			keluar_bulan56.ignore();
		}
		keluar_bulan56.close();
		
		for (int i=0;i<jumlahdata;i++)
		{
			if (strstr(mahasiswa[i].nama,cari)) 
			{
				dudukdisini (&i); ketemu=true;
			}
		}
		if (!ketemu) cout<<"\nMOHON MAAF NAMA YANG ANDA CARI TIFAK DITEMUKAN!\n";
		
	}
	else cout<<"\nMOHON MAAF MENU TIDAK TERSEDIA!\n";
	cout<<endl;
	cout<<"\n-Lihat Dibulan Yang Lain (y/n) ? "; cin>>y;
} while (y=='y'||y=='Y');
}

void tempatduduk()
{
	ifstream keluar_jlhdata;
	keluar_jlhdata.open ("jumlahdata.txt");
	keluar_jlhdata>>jumlahdata;
	keluar_jlhdata.close();
	
	int bulan;
	char y;
do
{
	system ("cls");
	cout<<"\n    Denah Tempat Duduk Yang Tersedia"<<endl;
	cout<<"    --------------------------------"<<endl<<endl;
	cout<<"\tA 	B	C	D	E\n"<<endl;
	cout<<" 1	O	O	O	O	O\n"<<endl;
	cout<<" 2	O	O	O	O	O\n"<<endl;
	cout<<" 3	O	O	O	O	O\n"<<endl;
	cout<<" 4	O	O	O	O	O\n"<<endl<<endl;
	cout<<"\n-Susunan Tempat Duduk Yang Telah Di Perbarui : ";
	cout<<"\n\n1.JANUARI dan FEBRUARI\n2.MARET dan APRIL\n3.MEI dan JUNI\n\n-Lihat Tempat Duduk Bulan : "; cin>>bulan;

	if (bulan==1)
	{
		//urutnama
		ifstream keluar_bulan12;
		keluar_bulan12.open ("bulan12.txt");
		keluar_bulan12.eof();
		for (int i=0;i<jumlahdata;i++)
		{
			keluar_bulan12.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan12>>mahasiswa[i].panggilan;
			keluar_bulan12>>mahasiswa[i].nim;
			keluar_bulan12.ignore();
			keluar_bulan12.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan12.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan12>>mahasiswa[i].posisibaris;
			keluar_bulan12>>mahasiswa[i].posisikolom;
			keluar_bulan12.ignore();
		}
		keluar_bulan12.close();
		
		cout<<"\n| Nama\t\t: [Kode Tempat Duduk]"<<endl;
		for (int i=0;i<jumlahdata;i++)
		{
			dudukdisini (&i);
			
		}
		
	}
	
	else if (bulan==2)
	{
		//urut ttl
		ifstream keluar_bulan34;
		keluar_bulan34.open ("bulan34.txt");
		keluar_bulan34.eof();
		for (int i=0;i<jumlahdata;i++)
		{
			keluar_bulan34.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan34>>mahasiswa[i].panggilan;
			keluar_bulan34>>mahasiswa[i].nim;
			keluar_bulan34.ignore();
			keluar_bulan34.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan34.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan34>>mahasiswa[i].posisibaris;
			keluar_bulan34>>mahasiswa[i].posisikolom;
			keluar_bulan34.ignore();
		}
		keluar_bulan34.close();
		
		cout<<"\n| Nama\t\t: [Kode Tempat Duduk]"<<endl;
		for (int i=0;i<jumlahdata;i++)
		{
			dudukdisini (&i);
		}
	}
	
	else if (bulan==3)
	{
		//urut nim
		ifstream keluar_bulan56;
		keluar_bulan56.open ("bulan56.txt");
		keluar_bulan56.eof();
		for (int i=0;i<jumlahdata;i++)
		{
			keluar_bulan56.getline(mahasiswa[i].nama,sizeof(mahasiswa[i].nama));
			keluar_bulan56>>mahasiswa[i].panggilan;
			keluar_bulan56>>mahasiswa[i].nim;
			keluar_bulan56.ignore();
			keluar_bulan56.getline(mahasiswa[i].lahir,sizeof(mahasiswa[i].lahir));
			keluar_bulan56.getline(mahasiswa[i].alamat,sizeof(mahasiswa[i].alamat));
			keluar_bulan56>>mahasiswa[i].posisibaris;
			keluar_bulan56>>mahasiswa[i].posisikolom; 
			keluar_bulan56.ignore();
		}
		keluar_bulan56.close();
		
		cout<<"\n| Nama\t\t: [Kode Tempat Duduk]"<<endl;
		for (int i=0;i<jumlahdata;i++)
		{
			dudukdisini (&i);
		}
	}
	else cout<<"\nMOHON MAAF MENU TIDAK TERSEDIA!\n";
	cout<<endl;
	cout<<"\n-Lihat Bulan Yang Lain (y/n) ? "; cin>>y;
} while (y=='y'||y=='Y');
}

void dudukdisini (int *i)
{
	cout<<endl<<"| "<<mahasiswa[*i].nama<<"\t: [";
	cout<<mahasiswa[*i].posisibaris;
	if (mahasiswa[*i].posisikolom==1) cout<<'A';
	if (mahasiswa[*i].posisikolom==2) cout<<'B';
	if (mahasiswa[*i].posisikolom==3) cout<<'C';
	if (mahasiswa[*i].posisikolom==4) cout<<'D';
	if (mahasiswa[*i].posisikolom==5) cout<<'E';
	cout<<"]";
}
