#include<iostream>
#include<conio.h>

using namespace std;
	typedef struct node{
	
	    int data;
	    struct node * next;
	    struct node *prev;
	}Node;
	
	
	Node * head =new Node();
	
	Node * top = new Node();
	int size;
	
	void InitStack(){
	head->next = head;
	head->prev = head;
	top = head;
	}
	
	bool isEmpty(){
		return size == 0;
	}



	int Peak(){//hien thi phan tu dau, neu stack rong tra ve 0
		if(!isEmpty())
		return top->data;
		return 0;
	}
	
	int Pop(){//lay ra phan tu top
		if(top != head){
			Node * temp = top;
			int item = top->data;
			
			top = top->prev;
			head->prev = top;
			top->next = head;
			
			delete(temp);
			return item;
		}

		return 0;
	}

	void Push(int value){
		if(isEmpty()){//khi danh sach rong( chi gom nut dau gia)
			top->data = value;//khoi tao va gan gia tri cho top
			
			top->next = head;
			top->prev = head;
			
			head->next = top;
			head->prev = top;//thay doi con tro
		}else{
			Node * newNode = new Node();
			newNode->data = value;
			
			top->next = newNode;
			newNode->next = head;
			newNode->prev = top;
			head->prev = newNode;
			
			top = newNode;
			
		}
		size++;
	}
	




int main(){
	int n, temp;
	
	InitStack();
	
	cout<<"Nhap so phan tu cua ngan xep: ";
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cout<<"nhap phan tu can dua vao stack: ";
		cin>>temp;
		Push(temp);

	}

	cout<<"Phan tu top hien tai: "<<Peak()<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"lay phan tu o top: "<<Pop()<<endl;
	cout<<"Phan tu top hien tai: "<<Peak()<<endl;
	cout<<"Danh sach hien tai rong khong? ";
	if(isEmpty()) cout<<"Co"<<endl;
	else cout<<"Khong"<<endl;
	

system("pause");
return 0;
}
