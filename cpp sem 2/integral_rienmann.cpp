#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main ()
{
	char kembali;
	int soal, partisi; float selisih,awal, batas[50], titiktengah[50],fungsix[50],total,rp ; 
	string soal1="f(x)=x^2+3 Pada interval [0,3]";
	string soal2="f(x)=x^2-1 Pada interval [-3,3]";
	string soal3="f(x)=3x^2+2x-3 Pada interval [0,4]"; 
do 
{
	system ("cls");
	cout<<"====INTEGRAL RIEMANN DENGAN LEBAR PARTISI SAMA BESAR===="<<endl;
	cout<<"Pilih soal : \n1."<<soal1<<" \n2."<<soal2<<" \n3."<<soal3<<" \nPilih : "; cin>>soal;
	system ("cls");
	if (soal==1)
	{
		awal=0; batas[0]=awal; total=0;
		cout<<"\t"<<soal1<<endl<<"masukkan jumlah partisi yang diinginkan (max50): "; cin>>partisi;
		partisi=partisi-1;
		selisih=3.0/partisi; batas[1]=selisih+awal;
		cout<<endl<<soal1<<" dengan partisi "<<batas[0];
		for (int i=1;i<partisi;i++)
		{ cout<<"<"<<batas[i]; batas[i+1]=selisih+batas[i];
		} cout<<"<"<<3; 
		
		for (int i=0;i<partisi;i++)
		{ titiktengah[i]=(batas[i]+batas[i+1])/2.0; 
		  fungsix[i]=(pow(titiktengah[i],2))+3;
		  total=total+fungsix[i]; 
		} 
		rp=total*selisih;
		cout<<endl<<"Rp = "<<rp<<endl;
	}
	
	else if (soal==2)
	{
		awal=-3; batas[0]=awal; total=0;
		cout<<"\t"<<soal2<<endl<<"masukkan jumlah partisi yang diinginkan (max50): "; cin>>partisi;
		partisi=partisi-1;
		selisih=6.0/partisi; batas[1]=selisih+awal;
		cout<<endl<<soal2<<" dengan partisi "<<batas[0];
		for (int i=1;i<partisi;i++)
		{ cout<<"<"<<batas[i]; batas[i+1]=selisih+batas[i];
		} cout<<"<"<<3; 
		
		for (int i=0;i<partisi;i++)
		{ titiktengah[i]=(batas[i]+batas[i+1])/2.0; 
		  //cout<<endl<<"x"<<i+1<<"="<<titiktengah[i];
		  fungsix[i]=(pow(titiktengah[i],2))-1;
		  //cout<<endl<<"f(x"<<i+1<<")="<<fungsix[i];
		  total=total+fungsix[i]; 
		} //cout<<endl<<total;
		rp=total*selisih;
		cout<<endl<<"Rp = "<<rp<<endl;
	}
	
	else if (soal==3)
	{
		awal=0; batas[0]=awal; total=0;
		cout<<"\t"<<soal3<<endl<<"masukkan jumlah partisi yang diinginkan (max50): "; cin>>partisi;
		partisi=partisi-1;
		selisih=4.0/partisi; batas[1]=selisih+awal;
		cout<<endl<<soal1<<" dengan partisi "<<batas[0];
		for (int i=1;i<partisi;i++)
		{ cout<<"<"<<batas[i]; batas[i+1]=selisih+batas[i];
		} cout<<"<"<<4; 
		
		for (int i=0;i<partisi;i++)
		{ titiktengah[i]=(batas[i]+batas[i+1])/2.0; 
		  fungsix[i]=(3*(pow(titiktengah[i],2)))+(2*titiktengah[i])-3;
		  total=total+fungsix[i]; 
		} 
		rp=total*selisih;
		cout<<endl<<"Rp = "<<rp<<endl;
	}
	
	cout<<endl<<"kerjakan yang lainnya? (y/n) :"; cin>>kembali;
} while (kembali=='y'||kembali=='Y');
}
