#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string.h>

using namespace std;

const int MAX = 1024;
int count,i;//count: kich thuoc day so int

//gop cac so lien tuc va tinh so ki tu da in ra man hinh
void output(int arr[], int top, int bot, int &mark){
	//neu cho ca 2 so lien tuc nhau thi xuat ra, dong thoi tang them 3 ki tu cho moi so
	if(bot-top < 2){
		for(int k = top; k<= bot; k++)
		{
			mark+=3;
			if(mark > 30){//xuong dong va thiet dat lai mark
				cout<<endl;
				mark=3;//chuyen so xuong hang duoi
			}
			cout<<arr[k]<<",";
		}
	}
	else{//sau khi gop thi tang them 7 ki tu(them dau '-')
		mark+=7;
		if(mark > 30){
			cout<<endl;
			mark=7;
		}
		cout<<arr[top]<<"-"<<arr[bot]<<",";
	}

	
}

//hien thi day so ra man hinh
void display(int * arr, int length){
	if(length ==0 ) return;

	int top=0,mark =0;//danh dau chi so phan tu dau va so ki tu da duyet xong
	
	for(i=0; i< length; i++){
	if (i==length -1)
		{
			output(arr,top,i,mark);
			return;
		}
	
		if(arr[i] != arr[top] + i - top){
			output(arr,top,i-1,mark);
			top=i;
		}
		if(arr[i] == arr[top] + i - top) continue;
	}
	
	
}

int changeType(char c){//chuyen ki tu sang so tuong ung
	return (int)c -48;
}

int * strtoDigit(char * str, int length){//chuyen doi day so dang string sang int
	int j=0;
	int * digit = new int[length];
	
	for(i=0; i< length; i++){
		if(str[i] == ','|| str[i]== ' ') continue;
		else{
			digit[j] = changeType(str[i])*100 + changeType(str[i+1])*10 + changeType(str[i+2]);
			j++;
			i+=2;
		}
	}
	count = j;
	return digit;
}

int main(){
	char * str = new char[MAX];
	cout<<"Nhap vao day so: ";
	cin>>str;

	int length = strlen(str);
	int * digit = new int[MAX];
	digit = strtoDigit(str, length);

	cout<<endl<<"------------------------------"<<endl;
	cout<<"Day so khi in tren nhieu dong:"<<endl;
	display(digit,count);

	//giai phong bo nho
	delete[] str;
	delete[] digit;
	return 0;
}
