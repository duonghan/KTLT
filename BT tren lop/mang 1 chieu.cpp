#include<iostream>
using namespace std;

int main()

{
	int m,n;
	cout<<"Nhap vao so hang cua ma tran ";
	cin>>m;
	cout<<"Nhap vao so cot cua ma tran ";
	cin>>n;
	
	int **ptr ;
	ptr = new int*[m];
	//khoi tao tung cot 
	for(int i=0; i<m; i++){
		ptr[i] = new int[n];                                                                                                                                      
	}
	
	//nhap du lieu
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			cout<<"Nhap phan tu a["<<i<<"]"<<"["<<j<<"]"<<": ";
			cin>>ptr[i][j];
		}
	
	//in ra man hinh
	cout<<"Mang da nhap la"<<endl;	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++){
			cout<<ptr[i][j]<<"   ";	
		}
		cout<<endl;
	}
	
	//giai phong bo nho
		//du lieu khai bao sau thi giai phong truoc
	for(int i=0; i<m;i++){
		delete [] ptr[i];
	}
		//du lieu khai bao truoc thi giai phong sau
	delete [] ptr;
	
	return 0;
}


