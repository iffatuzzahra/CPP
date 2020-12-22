#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

FILE *point,*point2;
char namafile[20],mainfile[20]; 
char file[20];

typedef struct 
{
	int gajiayah,gajiibu,tanggungan,jlhkendaraan,mobil,motor,lainnya,gol;
	char namaayah[30],namaibu[30];
	string rumah;
} keuangan;
typedef struct 
{
	char nama[30];
	int nopes;
	int banyakdata;
	keuangan penghasilan;
} peserta;

peserta rangkup[40],save,data;


void input(int i);
void simpan (int i);
void golongan (int gol);
void seq_search (int p);
void sort (int carigol,int menu,int jlh);
void merge_sort(peserta *rangkup, int low, int high);
void merge(peserta *rangkup, int low, int high, int mid);
int quick_sort ( peserta rangkup[],int awal,int akhir);
void binsearch(int carigol,int count);
void transaksi ();
void output ();



int main ()
{

	int menuutama, menusearch, menusort;
	int i=0,jumlahpeserta;
	
	do
	{ 
	system ("cls");
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t\t SELAMAT DATANG  \t\t\t|"<<endl;
	cout<<"| FORMULIR PENENTUAN UKT CALON MAHASISWA UPNVYK 2019\t|"<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t 1. INPUT DATA \t\t\t\t\t|"<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t 2. SEARCHING\t\t\t\t\t| "<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t 3. TRANSAKSI\t\t\t\t\t|"<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t 4. TAMPILKAN DATA \t\t\t\t|"<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|\t 5. EXIT\t\t\t\t\t"<<endl;
	cout<<" ______________________________________________________"<<endl;
	cout<<"|Silahkan di Pilih :"; cin>>menuutama;
	system ("cls");
	if (menuutama==1)
	{ 
		system ("cls");
		cout<<"\nMasukkan nama file penyimpanan utama : "; cin>>mainfile;
		cout<<"\nMasukkan Jumlah Peserta yang akan mendaftar ulang :"; cin>>jumlahpeserta;
		jumlahpeserta=jumlahpeserta+i;
		for (i=i;i<jumlahpeserta;i++)
		{
			system ("cls");
			cout<<"\t\t PENGISIAN DATA  \t\t\t"<<endl;
			cout<<"_____________________________________________________"<<endl;
			cout<<"\nMasukkan Nama Peserta ["<<i+1<<"] 		 : "; 
			cin.ignore(); cin.getline(rangkup[i].nama,sizeof(rangkup[i].nama));
			cout<<"Masukkan Nomor Peserta ["<<i+1<<"]		 : "; 
			cin>>rangkup[i].nopes;
			
			//cek dahulu apakah nomor peserta yang mendaftar telah pernah mengisi datanya
			
			input(i);
			
		}
		
		
	}
	
	else if (menuutama==2)
	{
		
		bool back=true;
		do 
		{
		system("cls");
		cout<<"==MENU SEARCHING==\n1. SEQ SEARCH\n2. BINNARY SEARCH\n3. KEMBALI KE MENU UTAMA\nPilih :"; 
		cin>>menusearch;
		
			if (menusearch==1) 
			{
				seq_search (jumlahpeserta);
				
			}
		
			else if (menusearch==2)
			{
				int carigol;
				system ("cls");
				
				cout<<"\n==========CARI DATA BERDASARKAN GOLONGAN==========";
				
				cout<<"\nMasukan Golongan yang ingin dicari : ";
				cin>>carigol;
				cout<<"==METODE SORTING==\n1. BUBBLE SORT\n2. SELECTION SORT\n3. INSERTION SORT\n4. SHELL SORT\n";
				cout<<"5. MERGE SORT\n6. QUICK SORT\nPilih :"; 
				cin>>menusort; 
			
				sort (carigol,menusort,jumlahpeserta);
			
			}
		
			else if (menusearch==3) back=false;  
		
		
		} while (back);
	}
	
	else if (menuutama==3)
	{
		transaksi();
	}
	
	else if (menuutama==4) 
	{ 
		
		cout<<"Masukkan file yang akan di buka : "; cin>>namafile;
		
		system ("cls");
				point=fopen (namafile,"r");
				while (fread (&data,sizeof (data),1,point))
				{
					cout<<"Nama File Penyimpanan : "<<namafile<<endl;
					output();
				}
				fclose(point);
			
			system("pause");
		
		
	}
	
	
	else if (menuutama==5) return 0;
	
	} while (true);
	
}

void input(int i)
{
	int kendaraan,hitung=0,hit; bool a;
	
	cout<<"Masukkan Nama Ayah 			: "; 
	cin.ignore(); cin.getline(rangkup[i].penghasilan.namaayah,sizeof(rangkup[i].penghasilan.namaayah));
	cout<<"Masukkan Nama ibu 			: "; 
	cin.getline(rangkup[i].penghasilan.namaibu,sizeof(rangkup[i].penghasilan.namaibu));
	cout<<"Masukkan Penghasilan Ayah perbulan 	: "; cin>>rangkup[i].penghasilan.gajiayah;
	cout<<"Masukkan Penghasilan Ibu perbulan 	: "; cin>>rangkup[i].penghasilan.gajiibu;
	cout<<"Masukkan Jumlah Tanggungan Orangtua 	: "; cin>>rangkup[i].penghasilan.tanggungan;
	cout<<"Masukkan Jumlah kendaraan Pribadi 	: "; cin>>rangkup[i].penghasilan.jlhkendaraan;
		if (rangkup[i].penghasilan.jlhkendaraan!=0)
		{
			do { kendaraan=0;  a=false;
			cout<<"Masukkan Jumlah Mobil		 : "; cin>>rangkup[i].penghasilan.mobil; 
			kendaraan=kendaraan+rangkup[i].penghasilan.mobil;
			cout<<"Masukkan Jumlah Motor		 : "; cin>>rangkup[i].penghasilan.motor; 
			kendaraan=kendaraan+rangkup[i].penghasilan.motor;
			cout<<"Masukkan Jumlah Kendaraan Lainnya : "; cin>>rangkup[i].penghasilan.lainnya; 
			kendaraan=kendaraan+rangkup[i].penghasilan.lainnya;
			if (kendaraan!=rangkup[i].penghasilan.jlhkendaraan) 
			{ 
				cout<<"jumlah kendaraan belum sesuai! silahkan masukkan kembali"<<endl;a=true; 
			}
			} while(a);
		}
	do { a=false;
	cout<<"Masukkan Status Rumah (Pribadi/Kontrak) : "; cin>>rangkup[i].penghasilan.rumah;
	if (rangkup[i].penghasilan.rumah!="kontrak"&&rangkup[i].penghasilan.rumah!="pribadi") 
	{
		cout<<"status tidak tersedia!ulangi kembali"<<endl; a=true;
	}
	} while(a);
	
	if (rangkup[i].penghasilan.jlhkendaraan==0) hitung=hitung+1;
	if (rangkup[i].penghasilan.mobil>1||rangkup[i].penghasilan.motor>3) hitung=hitung+1;
	else if (rangkup[i].penghasilan.mobil==0||rangkup[i].penghasilan.motor==0) hitung=hitung+2;
	if (rangkup[i].penghasilan.tanggungan<2) hitung=hitung+2;
	else if (rangkup[i].penghasilan.tanggungan<4) hitung=hitung+1;
	if (rangkup[i].penghasilan.rumah=="pribadi") hitung=hitung-1;
	if (rangkup[i].penghasilan.rumah=="kontrak") hitung=hitung-2;
	
	hit=((rangkup[i].penghasilan.gajiayah+rangkup[i].penghasilan.gajiibu)/5)+hitung*100000;
	if (hit>5350000) {rangkup[i].penghasilan.gol=6;}
	else if (hit>3400000) {rangkup[i].penghasilan.gol=5;}
	else if (hit>1550000) {rangkup[i].penghasilan.gol=4;} 
	else if (hit>500000) {rangkup[i].penghasilan.gol=3;}
	else if (hit>250000)  {rangkup[i].penghasilan.gol=2; }
	else rangkup[i].penghasilan.gol=1;
	
	//rangkup[i].banyakdata=i;
	
	simpan (i);
	golongan (rangkup[i].penghasilan.gol);
		
}

void simpan (int i)
{
	
	cout<<"Silahkan buat file penyimpanan anda!\n(using .txt format contoh :aaa.txt )"<<endl;
	cout<<"Nama file : "; cin>>namafile;
	data=rangkup[i];
	point=fopen (namafile,"w");
	fwrite (&data,sizeof (data),1,point);
	fclose (point);
	
	cout<<"TERIMKASIH TELAH MENYELESAIKAN PENGISIAN DATA"<<endl;
	system("pause");
	
	point=fopen(mainfile,"a");
	fwrite (&data,sizeof (data),1,point);
	fclose (point);
}

void golongan (int gol)
{
	
	int ukt;
	if (gol==1) ukt=500000;
	else if (gol==2) ukt=1000000;
	else if (gol==3) ukt=2000000;
	else if (gol==4) ukt=3500000;
	else if (gol==5) ukt=5000000;
	else if (gol==6) ukt=700000;
	
	system ("cls");
	cout<<"Golongan UKT anda adalah golongan ["<<gol<<"] \ndengan jumlah pembayaran per semester sebesar "<<ukt<<endl;
	system("pause");
}

void seq_search (int p)
{
	bool found=false;
	char carinama[30];
	system ("cls");
	cout<<"\n==========CARI DATA BERDASARKAN NAMA==========";
	cout<<"\nMasukan Nama yang ingin dicari : ";
	cin>>carinama;
	for(int j=0; j<p; j++)
	{
		if (strstr(rangkup[j].nama,carinama)) 
		{
			found=true;
			cout<<"Nama : "<<rangkup[j].nama<<endl;
			cout<<"Golongan : "<<rangkup[j].penghasilan.gol<<endl;
		}
	}
	if(!found)
	{
		cout<<"Nama yang dicari tidak ditemukan"<<endl;
	}
	system("pause");
}

void sort (int carigol,int menu,int jlh)
{
	
	if (menu==1) 
	{
		//bubble sort
		
		for (int i=0;i<jlh-1;i++)
		{
			for (int j=0;j<jlh-1-i;j++)
			{
				if (rangkup[j].penghasilan.gol>rangkup[j+1].penghasilan.gol)
				{
					save=rangkup[j]; 
					rangkup[j]=rangkup[j+1];
					rangkup[j+1]=save;
				}
			}
		}
	}
	
	else if (menu==2)
	{
		//selection sort
		
		for (int i=0;i<jlh;i++)
		{
			for (int j=i+1;j<jlh;j++)
			{
				if (rangkup[i].penghasilan.gol>rangkup[j].penghasilan.gol)
				{
					save=rangkup[i]; 
					rangkup[i]=rangkup[j]; 
					rangkup[j]=save;
				}
			}
		}
	}
	
	else if (menu==3)
	{
		//insertion sort
		
		for (int i=1;i<jlh;i++)
		{
			save=rangkup[i]; int j=i-1;
			while (save.penghasilan.gol<rangkup[j].penghasilan.gol&&j>=0)
			{
				
				rangkup[j+1]=rangkup[j]; j=j-1; 
				rangkup[j+1]=save;
			}
		}
	}
	
	else if (menu==4)
	{
		//shell sort
		
		for (int i=jlh/2;i>0;i/=2)
		{
			for (int j=i;j<jlh;j++)
			{
				for (int k=j-i;k>=0;k-=i)
				{
					if (rangkup[k+i].penghasilan.gol>=rangkup[k].penghasilan.gol) break;
					else 
					{
						save=rangkup[k]; 
						rangkup[k]=rangkup[k+i]; 
						rangkup[k+i]=save;
					}
				}
			}
		}
	}
	
	else if (menu==5) 
	{
		//merge sort
		merge_sort(rangkup, 0, jlh-1);
	}
	
	else if (menu==6)
	{
		//quick sort
		int awal,akhir; 
		awal=0; akhir=jlh-1;
		quick_sort (rangkup,awal,akhir);
		
	}

	
	//binnary search
	binsearch(carigol,jlh);
	system ("cls");
	char n;
	cout<<"Simpan hasil pengurutan ke dalam file ? (y/n)"; cin>>n;
	
	if (n=='y')
	{
		cout<<"Silahkan buat file penyimpanan data urut!\n(using .txt format contoh :aaa.txt )"<<endl;
		cout<<"Nama file : "; cin>>namafile;
		point=fopen (namafile,"a");
		for (int i=0;i<jlh;i++)
		{
			data=rangkup[i];
			fwrite (&data,sizeof (data),1,point);
		}
		fclose (point);
	}
}

void merge_sort(peserta *rangkup, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		
		merge_sort(rangkup, low, mid);
		merge_sort(rangkup, mid+1, high);
 
		
		merge(rangkup, low, high, mid);
	}
}

void merge(peserta *rangkup, int low, int high, int mid)
{

	int i, j, k;
	peserta temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high)
	{
		if (rangkup[i].penghasilan.gol< rangkup[j].penghasilan.gol)
		{
			temp[k] = rangkup[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = rangkup[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		temp[k] = rangkup[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = rangkup[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		rangkup[i] = temp[i-low];
	}
}

int quick_sort ( peserta rangkup[],int awal,int akhir)
{
	peserta tengah;
	int low,high;
		low=awal; high=akhir;
		tengah=rangkup[(awal+akhir)/2];
		do
		{
			while (rangkup[low].penghasilan.gol<tengah.penghasilan.gol) low++;
			while (rangkup[high].penghasilan.gol>tengah.penghasilan.gol) high--;
			
			if (low<=high)
			{
				save=rangkup[low]; 
				rangkup[low++]=rangkup[high]; 
				rangkup[high--]=save;
			}
		} while (low<=high);
		if (awal<high) quick_sort (rangkup,awal,high);
		if (low<akhir) quick_sort (rangkup,low,akhir);	
	return true;
}


void binsearch(int carigol,int count)
{
	
	int first = 0,middle;
	int last = count-1;
	
	while (first <= last)
	{
		 middle = (first + last)/2; 
	    if(rangkup[middle].penghasilan.gol < carigol)
	    {
		first = middle + 1;

	    }
	    else if(rangkup[middle].penghasilan.gol == carigol)
	    {
			
			cout<<"Nama	: "<<rangkup[middle].nama<<endl;
			break;
        } 
        else 
        { 
            last = middle - 1; 
        }
       
    } 
    
    if(first > last)
	{
	  cout<<"Golongan yang dicari tidak ditemukan"<<endl;
	}
	system("pause");

}

void transaksi ()
{
	int jlhmerge;
	system("cls");
	cout<<"PADA MENU INI AKAN DILAKUKAN TRANSAKSI BERUPA MERGE SAMBUNG DAN SPLITTING DATA\n";
	cout<<"tekan enter/spasi jika telah paham!"<<endl;
	system("pause");
	cout<<"\n-----------------MERGE SAMBUNG----------------\n";
	cout<<"Masukkan nama file untuk data yang telah di sambungkan :"; cin>>file;
	cout<<"Masukkan jumlah file yang akan di sambung :"; cin>>jlhmerge;
	
	for (int x=0;x<jlhmerge;x++)
	{
		cout<<"Masukkan nama file "<<x+1<<":"; cin>>namafile;
		point=fopen (namafile,"r");
		while (fread (&data,sizeof (data),1,point))
		{
			point2=fopen(file,"a");
			fwrite(&data,sizeof(data),1,point2);
			fclose(point2);
		}
		fclose(point);
	}
	system("pause");
	system ("cls");
	point2=fopen (file,"r");
	while (fread (&data,sizeof (data),1,point2))
	{
		cout<<"Nama File Penyimpanan : "<<file<<endl;
		output();
	}
	fclose(point2);
	
	cout<<"\nData ini akan di split menjadi 2 (UKT gol 1,2,3 dan UKT gol 4,5,6)\n";
	cout<<"tekan enter/spasi juntuk melanjutkan!"<<endl;
	system("pause");
	
	system("cls");
	
	cout<<"\n-----------------SPLITTING----------------\n";
	cout<<"Masukkan nama file untuk UKT golongan 1,2,3 : "; cin>>namafile;
	cout<<"Masukkan nama file untuk UKT golongan 4,5,6 : "; cin>>mainfile;
	system ("cls");
	
	point2=fopen (file,"r");
	while (fread (&data,sizeof (data),1,point2))
	{
	
		if (data.penghasilan.gol==1||data.penghasilan.gol==2||data.penghasilan.gol==3)
		{
			point=fopen(namafile,"a");
			fwrite(&data,sizeof(data),1,point);
			fclose(point);
		}
	
		if (data.penghasilan.gol==4||data.penghasilan.gol==5||data.penghasilan.gol==6)
		{
			point=fopen(mainfile,"a");
			fwrite(&data,sizeof(data),1,point);
			fclose(point);
		}
	}
	fclose(point2);
	
	point=fopen (namafile,"r");
		cout<<"-------------------------------------"<<endl;
		cout<<"=========UKT GOLONGAN 1,2,3==========\n";
		cout<<"Nama File Penyimpanan : "<<namafile<<endl;
		while (fread (&data,sizeof (data),1,point))
		{
			output ();
			cout<<endl;
		}
	fclose(point);
	
	point=fopen (mainfile,"r");
		cout<<"-------------------------------------"<<endl;
		cout<<"=========UKT GOLONGAN 4,5,6==========\n";
		cout<<"Nama File Penyimpanan : "<<mainfile<<endl;
		while (fread (&data,sizeof (data),1,point))
		{
			output ();
			cout<<endl;
		}
	fclose(point);
	system("pause");
}

void output()
{
	
	cout<<"\t\t REKAP DATA  \t\t\t"<<endl;
	cout<<"_____________________________________________________"<<endl;
	cout<<"Nama Peserta : "<<data.nama<<endl;
	cout<<"Nomor Peserta : "<<data.nopes<<endl;
	
	cout<<"Nama Ayah 			: "<<data.penghasilan.namaayah<<endl;
	cout<<"Nama ibu 			: "<<data.penghasilan.namaibu<<endl;
	cout<<"Penghasilan Ayah perbulan 	: "<<data.penghasilan.gajiayah<<endl;
	cout<<"Penghasilan Ibu perbulan 	: "<<data.penghasilan.gajiibu<<endl;
	cout<<"Jumlah Tanggungan Orangtua 	: "<<data.penghasilan.tanggungan<<endl;
	cout<<"Jumlah kendaraan Pribadi 	: "<<data.penghasilan.jlhkendaraan<<endl;
		if (data.penghasilan.jlhkendaraan!=0)
		{
			cout<<"Jumlah Mobil		 : "<<data.penghasilan.mobil<<endl; 
			
			cout<<"Jumlah Motor		 : "<<data.penghasilan.motor<<endl; 
			
			cout<<"Jumlah Kendaraan Lainnya : "<<data.penghasilan.lainnya<<endl; 
		}
	
	cout<<"Status Rumah (Pribadi/Kontrak) : "<<data.penghasilan.rumah<<endl;
	cout<<endl<<"UKT GOLONGAN :"<<data.penghasilan.gol<<endl;
}

