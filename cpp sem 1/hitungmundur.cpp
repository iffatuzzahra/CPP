#include <iostream>
using namespace std;
int main()
{
	int hitung, hit;
	cout<<"berapa kali perulangan? ";
	cin>>hitung;
	hit=hitung;
	cout<<"menghitung mundur.."<<endl;
	
	for(hitung=hit; hitung>0; hitung--)
	{
		cout<<"mencetak : "<<hitung<<endl;
	}
	cout<<endl;
	if (hit<=0)
	{
		cout<<"tidak ada pertulangan..";
		cout<<endl;
	}
	else
	{
		cout<<"selesai mengulang.."<<endl;
		cout<<"perhitungan terakhir : "<<hitung;
	}
	
}
