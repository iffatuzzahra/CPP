#include <iostream>

using namespace std;

int main ()
{
	float celcius;
	float fahrenheit;
	float reamur;
	float kelvin;
	
	cout<<"suhu dalam celcius : ";
	cin>>celcius;
	
	fahrenheit=celcius*1.8+32;
	reamur=celcius*0.8;
	kelvin=celcius+273.15;
	
	cout<<"\nsuhu dalam fahrenheit : "<<fahrenheit;
	cout<<"\nsuhu dalam reamur : "<<reamur;
	cout<<"\nsuhu dalam kelvin : "<<kelvin;
}
