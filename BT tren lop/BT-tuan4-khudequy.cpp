#include<iostream>
#include<conio.h>

using namespace std;

int main(){

	int n,i;
	int F, F1, F2, F3, F4;
	long sum = 0;
	
	//Day 1
	cout<<"Nhap so phan tu cua day so thu nhat: ";
	cin>>n;
	cout<<"Day so thu nhat: ";
	if (n<=4)
	{
		switch(n){
			case 1:
				cout<<1;
				sum+= 1;
				break;
			case 2:
				cout<<"1, 2";
				sum+= 3;
				break;
			case 3:
				cout<<"1, 2, 3";
				sum+=6;
				break;
			case 4:
				cout<<"1, 2, 3, 4";
				sum+= 10;
				break;
		}
	}
	else{
		sum = 10;//4 phan tu truoc co tong bang 10
		F1 = 4; F2 = 3; F3 = 2; F4 = 1;
		cout<<"1, 2, 3, 4, ";
		for (int i = 5; i <= n; i++)
		{
			F = F1 -F2 + F3+ F4;
			sum+= F;
			cout<<F<<", ";
			
			F4 = F3; F3 = F2 ; F2 = F1 ; F1 = F;
		}
	}
	
	cout<<endl;	
	cout<<"Tong cua "<<n<<" phan tu dau tien cua day thu nhat la "<<sum<<endl;
	cout<<"----------------------------------------"<<endl;
	
	//Day 2
	sum = 0;
	cout<<"Nhap so phan tu cua day so thu hai: ";
	cin>>n;
	cout<<"Day so thu hai: ";
	if (n<=4)
	{
		switch(n){
			case 1:
				cout<<1;
				sum+= 1;
				break;
			case 2:
				cout<<"1, 2";
				sum+= 3;
				break;
			case 3:
				cout<<"1, 2, 3";
				sum+=6;
				break;
			case 4:
				cout<<"1, 2, 3, 4";
				sum+= 10;
				break;
		}
	}
	else{
		sum = 10;
		F1 = 4; F2 = 3; F3 = 2; F4 = 1;
		cout<<"1, 2, 3, 4, ";
		for (int i = 5; i <= n; i++)
		{
			F = F1 + F2 - F3+ F4;
			sum+= F;
			cout<<F<<", ";
			F4 = F3; F3 = F2 ; F2 = F1 ; F1 = F;
		}
	}
	
	
	cout<<endl;	
	cout<<"Tong cua "<<n<<" phan tu dau tien cua day thu hai la "<<sum<<endl;
	cout<<"----------------------------------------"<<endl;

	system("pause");
	return 0;
	
	}
