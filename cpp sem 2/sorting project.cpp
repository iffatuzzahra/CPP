#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h> // include untuk fopen dan fclose
#include <conio.h>
using namespace std;
int quick_sort (int data[],int awal,int akhir);
int mergesort (int kiri,int kanan);
int merge(int kiri,int tengah,int kanan);  
void urutnama();
int main ()
{
	int menu,jlh,data[30];
	cout<<"jumlah yang ingin dimasukkan : "; cin>>jlh;
	for (int i=0;i<jlh;i++)
	{
	cout<<"masukkan angka 1-8 random : "; cin>>data[i];
	}
	
	cout<<"==METODE SORTING==\n1. BUBBLE SORT\n2. SELECTION SORT\n3. INSERTION SORT\n4. SHELL SORT\n";
	cout<<"5. MERGE SORT\n6. QUICK SORT\n7. Nama Nama \nPilih :"; cin>>menu; 
	
	if (menu==1) 
	{
		//bubble sort
		int save;
		for (int i=0;i<jlh-1;i++)
		{
			for (int j=0;j<jlh-1-i;j++)
			{
				if (data[j]>data[j+1])
				{
					save=data[j]; data[j]=data[j+1]; data[j+1]=save;
				}
			}
		}
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		} 
		
	}
	
	else if (menu==2)
	{
		//selection sort
		int save;
		for (int i=0;i<jlh;i++)
		{
			for (int j=i+1;j<jlh;j++)
			{
				if (data[i]>data[j])
				{
					save=data[i]; data[i]=data[j]; data[j]=save;
				}
			}
		}
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		} 
	}
	
	else if (menu==3)
	{
		//insertion sort
		int save;
		for (int i=1;i<jlh;i++)
		{
			save=data[i]; int j=i-1;
			while (save<data[j]&&j>=0)
			{
				
				data[j+1]=data[j]; j=j-1; data[j+1]=save;
			}
		}
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		}
	}
	
	else if (menu==4)
	{
		//shell sort
		int save;
		for (int i=jlh/2;i>0;i/=2)
		{
			for (int j=i;j<jlh;j++)
			{
				for (int k=j-i;k>=0;k-=i)
				{
					if (data[k+i]>=data[k]) break;
					else 
					{
						save=data[k]; data[k]=data[k+i]; data[k+i]=save;
					}
				}
			}
		}
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		}
	}
	
	else if (menu==5)
	{
		//merge sort
		mergesort (0,jlh);
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		}
	}
	
	else if (menu==6)
	{
		//quick sort
		int awal,akhir; 
		awal=0; akhir=jlh-1;
		quick_sort (data,awal,akhir);
		
		for (int i=0;i<jlh;i++)
		{
			cout<<data[i]<<endl;
		}
	}
	
	else if (menu==7)
	{
		urutnama();
	}
}

int quick_sort (int data[],int awal,int akhir)
{
	int tengah,save,low,high;
		low=awal; high=akhir;
		tengah=data[(awal+akhir)/2];
		do
		{
			while (data[low]<tengah) low++;
			while (data[high]>tengah) high--;
			
			if (low<=high)
			{
				save=data[low]; data[low++]=data[high]; data[high--]=save;
			}
		} while (low<=high);
		if (awal<high) quick_sort (data,awal,high);
		if (low<akhir) quick_sort (data,low,akhir);	
	return true;
}

int mergesort (int kiri,int kanan)
{
 int tengah;  
 if(kiri<kanan)  
 {  
  tengah=(kiri+kanan)/2;  
  mergesort(kiri,tengah);  
  mergesort(tengah+1,kanan);  
  merge(kiri,tengah,kanan);  
 }  
 return true;
}
int merge(int kiri,int tengah,int kanan)  
{  
 int h,i,j,b[20],a[20],k;  
 h=kiri;  
 i=kiri;  
 j=tengah+1;  
 while((h<=tengah)&&(j<=kanan))  
 {  
  if(a[h]<=a[j])  
  {  
   b[i]=a[h]; h++;  
  }  
  else  
  {  
   b[i]=a[j]; j++;  
  } i++;  
 }  
 if(h>tengah)  
 {  
  for(k=j;k<=kanan;k++)  
  {  
   b[i]=a[k]; i++;  
  }  
 }  
 else  
 {  
  for(k=h;k<=tengah;k++)  
  {  
   b[i]=a[k]; i++;  
  }  
 }  
 for(k=kiri;k<=kanan;k++)  
  a[k]=b[k];  
  
  return true;
}  

void urutnama()
{
	int orang;
	char nama[40][40];
	cout<<"masukkan jumlah orang : "; cin>>orang;
	for (int i=0;i<orang;i++)
	{
	cout<<"masukkan nama ["<<i+1<<"]:"; cin>>nama[i];
	}
	
	for(int i=0;i<orang;i++)
	{
 
		int j,bd;
		j=i;
		for(int k=i+1;k<orang;k++)
		{
			 bd=strcmp(nama[j],nama[k]);
			 if(bd==1) j=k;       
		}
		if(j!=i)
		{
			char save[30]; /* Swapping */
			strcpy(save,nama[j]);
			strcpy(nama[j],nama[i]);
			strcpy(nama[i],save);
		}
	}
	for (int i=0;i<orang;i++)
	{ /* Menampilkan hasil */
		cout<<"Nama : ";
		puts(nama[i]); cout<<endl;
	}
	getchar();
}
