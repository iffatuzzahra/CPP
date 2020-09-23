#include <iostream>

using namespace std;
int main()
{
	int pilihan,B;
	cout<<"masukkan angka : ";
	cin>>B;
	pilihan=(B%3)+3-2+1-2;
	switch (pilihan){
		case 0 : 
		cout<<'X'; break;
		case 1 :
		cout<<'Y'; break;
		case 2 :
		cout<<'Z'; break;
		default :
		cout<<'S';
	}
}
