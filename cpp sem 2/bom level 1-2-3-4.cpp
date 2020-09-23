//Nama	: Iffatuz Zahra
//NIM	: 123180039
//Plug	: B
#include <iostream>
using namespace std;
int main ()
{
	int x,y, taruh, jumlah=0, max=0, hp=100,a,b;
	int bom[3][3];
	  cout<<"\t----BOMBERMIN----\n"<<endl;
	  for (x=0;x<3;x++){
		 for (y=0;y<3;y++){
			 cout<<"baris "<<x+1<<" kolom "<<y+1<<"\napakah akan menaruh bom? (ya=1/tidak=0) "; cin>>taruh;
	 		 if (taruh==1) {cout<<"berikan damage pada bom = "; cin>>bom[x][y];}
				 else bom[x][y]=0;
		 }
	 } cout<<endl;
	 cout<<"+--+--+--+"<<endl;
	 for (x=0;x<3;x++){
		 for (y=0;y<3;y++){ 
			 if (bom[x][y]!=0) {
				 jumlah=jumlah+1;
					 if (bom[x][y]<10)cout<<"| "<<bom[x][y]; else cout<<"|"<<bom[x][y]; }
				 else cout<<"|  ";
			 if (bom[x][y]>max) max=bom[x][y];
			 if (hp>0){ hp=hp-bom[x][y];  if (hp<=0){a=x; b=y;}}	 
		 } cout<<"|\n+--+--+--+"<<endl;
	 }
	 cout<<"\n\njumlah bom pada area adalah "<<jumlah;
	 cout<<"\ndamage terbesar adalah "<<max;
	 cout<<"\ndengan HP=100, maka dinyatakan "; 
	 if (hp>0) cout<<"bertahan hidup dengan sisa HP "<<hp; 
		 else cout<<"mati pada baris ke "<<a+1<<" kolom ke "<<b+1;
}
