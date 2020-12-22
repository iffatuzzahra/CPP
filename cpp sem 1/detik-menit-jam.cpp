#include <iostream>
using namespace std;
void jam(int *a);
void menit(int *a);
void detik(int a);
void angka(int c);
int main ()
{
	int a;
	cout<<"masukkan waktu dalam detik : "; cin>>a;
	if (a>3600) jam(&a);
	if (a>60) menit(&a);
	detik (a);
	
}
void jam(int *a)
{
	int b;
	b=*a/3600; angka(b); cout<<" jam ";
	*a=*a-(b*3600);
}
void menit(int *a)
{
	int b,c;
	b=*a/60; 
	if (b>19||b==10){ c=b/10; angka(c); b=b-c*10; angka(b); }
	else if (b>9) { c=b-10; cout<<"1";angka(c); } 
	else angka(b); cout<<" menit ";
	*a=*a-(b*60);
}
void detik(int a)
{
	int b;
	if (a>19||a==10){ b=a/10; angka(b); a=a-b*10; angka(a); }
	else if (a>9) { b=a-10; cout<<"1";angka(b); } 
	else angka(a);
	cout<<" detik ";
}
void angka(int c)
{
	if (c==1) cout<<"1";
	if (c==2) cout<<"2";
	if (c==3) cout<<"3";
	if (c==4) cout<<"4";
	if (c==5) cout<<"5";
	if (c==6) cout<<"6";
	if (c==7) cout<<"7";
	if (c==8) cout<<"8";
	if (c==9) cout<<"9";
}
