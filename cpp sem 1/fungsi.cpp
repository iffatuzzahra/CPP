#include <iostream>
#include <stdlib.h>
#include <math.h>
#define phi 3.14
using namespace std;
void volume_tabung (float, float);
void volume_kerucut (float, float);
float luas_segitiga (float, float);
float keliling_segitiga (float, float);
float luas_persegipanjang (float, float);
float keliling_persegipanjang (float , float );
int main ()
{
char y;
int x;
float t,r;
do
{
	system("cls");
	cout<<"----menu----\n";
	cout<<"1.volume tabung\n2.volume kerucut\n3.keliling dan luas segitiga siku siku\n4.keliling dan luas persegi panjang\n5.input nama panjang";
	cout<<"\n\npilih : ";
	cin>>x;
	
	switch (x)
	{
		case 1 :
		system("cls");
		cout<<"    volume tabung\n";
		cout<<"tinggi :"; cin>>t;
		cout<<"jari jari :"; cin>>r;
		volume_tabung (t,r);
		cout<<"\n\nkembali ke menu (y/n)"; cin>>y;
		break;
		
		case 2 :
		system("cls");
		cout<<"    volume kerucut\n";
		cout<<"tinggi :\t"; cin>>t;
		cout<<"jari jari :\t"; cin>>r;
		volume_kerucut (t,r);
		cout<<"\n\nkembali ke menu (y/n)"; cin>>y;
		break;
		
		case 3 :
		system("cls");
		cout<<"    keliling dan luas segitiga siku siku\n";
		cout<<"tinggi \t:"; cin>>t;
		cout<<"alas \t:"; cin>>r;
		cout<<"luas \t:"<<luas_segitiga (t,r);
		cout<<"\nkeliling \t:"<<keliling_segitiga (t,r);
		cout<<"\n\nkembali ke menu (y/n)"; cin>>y;
		break;
		
		case 4 :
		system("cls");
		cout<<"    keliling dan luas persegi panjang\n";
		cout<<"panjang :\t"; cin>>t;
		cout<<"lebar \t:"; cin>>r;
		cout<<"\nkeliling \t:"<<keliling_persegipanjang (t,r);
		cout<<"\nluas \t:"<<luas_persegipanjang (t,r);
		cout<<"\n\nkembali ke menu (y/n)"; cin>>y;
		break;
		
		case 5 :
		system("cls");
		char nama[30]; char nam[30];
		cout<<"    input nama panjang :"; 
		cout<<"\nnama depan \t:"; cin>>nama;
		cout<<"\nnama belakang \t:"; cin>>nam;
		cout<<"\nnama panjang \t:"<<nama<<" "<<nam;
		cout<<"\n\nkembali ke menu (y/n)"; cin>>y; break;
	}
}
while (y=='y');
}
void volume_tabung (float t, float r)
{
	float l=phi*r*r*t;
	cout<<"hasil :"<<l;
	
}
void volume_kerucut (float t, float r)
{
	float l=1/3.0*phi*r*r*t;
	cout<<"hasil :"<<l;
}
float luas_segitiga (float t, float r)
{
	return (t*r*0.5); 
}
float keliling_segitiga (float t, float r)
{
	return (sqrt(pow(t,2.0)+pow(r,2.0))+t+r);
}
float luas_persegipanjang (float t, float r)
{
	return (t*r);
}
float keliling_persegipanjang (float t, float r)
{
	return (2*t+2*r);
}

