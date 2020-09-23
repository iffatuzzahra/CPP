#include <iostream>
using namespace std;
int main ()
{
	int umur[100][100], n, max, min,tomax, tomin, so[100],j;
	cout<<"banyak orang (maks 100) :" ; cin>>n;
	for (int i=0; i<n; i++)
	{ 
		cout<<"orang ke "<<i+1<<" bersaudara sebanyak :"; cin>>so[i];
		for (j=0;j<so[i];j++){
			cout<<"umur saudara ke "<<j+1<<" :"; cin>>umur[i][j];
		}
		
	} max=0; min=1000; 
	cout<<"\ndata yang diinput : \n";
	for (int i=0; i<n; i++)
	{ 
		cout<<"\norang ke "<<i+1<<" bersaudara sebanyak :"<<so[i];
		for (j=0;j<so[i];j++){
			cout<<"\numur saudara ke "<<j+1<<" :"<<umur[i][j];
			if (umur[i][j]>max)  max=umur[i][j];
			if (umur[i][j]<min)  min=umur[i][j];
		}
	} tomax=0; tomin=0;
	for (int i=0; i<n; i++)
	{ for (int j=0;j<so[i];j++){
		if (umur[i][j]==max) tomax++;
		if (umur[i][j]==min) tomin++;}
	}
	cout<<endl;
	
	cout<<"\numur maximal : "<<max<<endl;
	cout<<"\numur minimal : "<<min<<endl;
	cout<<"\njumlah yang max : "<<tomax<<endl;
	cout<<"\njumlah yang min : "<<tomin<<endl;
	
}
