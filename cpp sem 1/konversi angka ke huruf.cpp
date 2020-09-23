#include <iostream>
#include <stdlib.h>
using namespace std;
int main ()
{int a; 
	cout<<"masukkan angka : "; cin>>a;
	
	if ((a-1000)<1000){ cout<<"seribu "; a=a%1000; }
	
	if (a>=1000000&&a<1000000000)
	{
	if (a>=100000000&&a<1000000000)
	{int p=a/100000000;
		if (p==1) cout<<"se";else if (p==2) cout<<"dua ";
		else if (p==3) cout<<"tiga ";
		else if (p==4) cout<<"empat ";
		else if (p==5) cout<<"lima ";
		else if (p==6) cout<<"enam ";
		else if (p==7) cout<<"tujuh ";
		else if (p==8) cout<<"delapan ";
		else if (p==9) cout<<"sembilan ";
			cout<<"ratus ";a=a%(p*100000000);}
	if (a>10000000&&a<20000000)
	{int m=a%10000000; int n=m/1000000; 
		if (n==1) cout<<"se";else if (n==2) cout<<"dua ";
		else if (n==3) cout<<"tiga ";
		else if (n==4) cout<<"empat ";
		else if (n==5) cout<<"lima";
		else if (n==6) cout<<"enam ";
		else if (n==7) cout<<"tujuh ";
		else if (n==8) cout<<"delapan ";
		else if (n==9) cout<<"sembilan ";
			cout<<"belas ";a=a%((n*1000000)+10000000);}
	if ((a>=20000000&&a<100000000)||(a==10000000))
	{int k=a/10000000;
		if (k==1) cout<<"se";else if (k==2) cout<<"dua ";
		else if (k==3) cout<<"tiga ";
		else if (k==4) cout<<"empat ";
		else if (k==5) cout<<"lima ";
		else if (k==6) cout<<"enam ";
		else if (k==7) cout<<"tujuh ";
		else if (k==8) cout<<"delapan ";
		else if (k==9) cout<<"sembilan ";
			cout<<"puluh ";a=a%(k*10000000);}
	if (a>=1000000&&a<10000000)
	{int h=a/1000000;
		if (h==1) cout<<"satu ";else if (h==2) cout<<"dua ";
		else if (h==3) cout<<"tiga ";
		else if (h==4) cout<<"empat ";
		else if (h==5) cout<<"lima ";
		else if (h==6) cout<<"enam ";
		else if (h==7) cout<<"tujuh ";
		else if (h==8) cout<<"delapan ";
		else if (h==9) cout<<"sembilan ";
			a=a%(h*1000000);} cout<<"juta ";}
			
	if (a>=1000&&a<1000000)
	{
	if (a>=100000&&a<1000000)
	{int g=a/100000;
		if (g==1) cout<<"se";else if (g==2) cout<<"dua ";
		else if (g==3) cout<<"tiga ";
		else if (g==4) cout<<"empat ";
		else if (g==5) cout<<"lima ";
		else if (g==6) cout<<"enam ";
		else if (g==7) cout<<"tujuh ";
		else if (g==8) cout<<"delapan ";
		else if (g==9) cout<<"sembilan ";
			cout<<"ratus ";a=a%(g*100000);}
	if (a>10999999&&a<20000)
	{int i=a%10000; int j=i/1000; 
		if (j==1) cout<<"se";else if (j==2) cout<<"dua ";
		else if (j==3) cout<<"tiga ";
		else if (j==4) cout<<"empat ";
		else if (j==5) cout<<"lima";
		else if (j==6) cout<<"enam ";
		else if (j==7) cout<<"tujuh ";
		else if (j==8) cout<<"delapan ";
		else if (j==9) cout<<"sembilan ";
			cout<<"belas ";a=a%((j*1000)+10000);}
	if ((a>=20000&&a<100000)||(a>=10000&&a<11000000))
	{int f=a/10000;
		if (f==1) cout<<"se";else if (f==2) cout<<"dua ";
		else if (f==3) cout<<"tiga ";
		else if (f==4) cout<<"empat ";
		else if (f==5) cout<<"lima ";
		else if (f==6) cout<<"enam ";
		else if (f==7) cout<<"tujuh ";
		else if (f==8) cout<<"delapan ";
		else if (f==9) cout<<"sembilan ";
			cout<<"puluh ";a=a%(f*10000);}
	if (a>=1000&&a<10000)
	{int e=a/1000;
		if (e==1) cout<<"satu ";else if (e==2) cout<<"dua ";
		else if (e==3) cout<<"tiga ";
		else if (e==4) cout<<"empat ";
		else if (e==5) cout<<"lima ";
		else if (e==6) cout<<"enam ";
		else if (e==7) cout<<"tujuh ";
		else if (e==8) cout<<"delapan ";
		else if (e==9) cout<<"sembilan ";
			a=a%(e*1000);} cout<<"ribu ";}
	
	if (a>=100&&a<1000)
	{int c=a/100;
		if (c==1) cout<<"se";else if (c==2) cout<<"dua ";
		else if (c==3) cout<<"tiga ";
		else if (c==4) cout<<"empat ";
		else if (c==5) cout<<"lima ";
		else if (c==6) cout<<"enam ";
		else if (c==7) cout<<"tujuh ";
		else if (c==8) cout<<"delapan ";
		else if (c==9) cout<<"sembilan ";
			cout<<"ratus ";a=a%(c*100);}
	if (a>10&&a<20)
	{a=a%10;
		if (a==1) cout<<"se";else if (a==2) cout<<"dua ";
		else if (a==3) cout<<"tiga ";
		else if (a==4) cout<<"empat ";
		else if (a==5) cout<<"lima";
		else if (a==6) cout<<"enam ";
		else if (a==7) cout<<"tujuh ";
		else if (a==8) cout<<"delapan ";
		else if (a==9) cout<<"sembilan ";
			cout<<"belas ";a=0;}
	if ((a>=20&&a<100)||(a==10))
	{int d=a/10;
		if (d==1) cout<<"se";else if (d==2) cout<<"dua ";
		else if (d==3) cout<<"tiga ";
		else if (d==4) cout<<"empat ";
		else if (d==5) cout<<"lima ";
		else if (d==6) cout<<"enam ";
		else if (d==7) cout<<"tujuh ";
		else if (d==8) cout<<"delapan ";
		else if (d==9) cout<<"sembilan ";
			cout<<"puluh ";a=a%(d*10);}
	if (a>0&&a<10)
	{
		if (a==1) cout<<"satu ";else if (a==2) cout<<"dua";
		else if (a==3) cout<<"tiga";
		else if (a==4) cout<<"empat";
		else if (a==5) cout<<"lima";
		else if (a==6) cout<<"enam ";
		else if (a==7) cout<<"tujuh ";
		else if (a==8) cout<<"delapan ";
		else if (a==9) cout<<"sembilan";}
 }
