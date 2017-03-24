#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

typedef struct {
  int masv;
  char malop[12];
  char ho[30];
  char ten[30];
  float diemk1;
  float diemk2;
} sinhvien;

typedef struct node{
	sinhvien data;
	struct node * next;
	struct node * prev;
} Node;

//Cac ham voi danh sach lien ket
//khoi tao

//nhap du lieu

Node * InsertNode(Node * head, int index, sinhvien sv){
	if(index < 0) return NULL;
	int currentIndex = 1;
	Node *currentNode = head;
	while(currentNode && index > currentIndex){
		currentNode = currentNode->next;
		currentIndex++;
	}
	if(index > 0 && currentNode == NULL)  return NULL;
	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->data = sv;
	if(index == 0){
		newNode->next = head;
		head = newNode;
		newNode->prev = head;
	}
	else{
		newNode->next = currentNode->next;
		newNode->prev = currentNode;
		currentNode->next->prev = newNode;
		currentNode->next = newNode;
	}
	
	return newNode;
}

void displayNode(Node *node){
	cout<<"--------------------------"<<endl;
	cout<<"Ma SV: "<<node->data.masv<<endl;
	cout<<"Ma lop: "<<node->data.malop<<endl;
	cout<<"Ho: "<<node->data.ho<<endl;
	cout<<"Ten: "<<node->data.ten<<endl;
	cout<<"Diem ky 1: "<<node->data.diemk1<<endl;
	cout<<"Diem ky 2: "<<node->data.diemk2<<endl;
	cout<<"--------------------------"<<endl;
}

void displayList(Node *head){
	Node * currentNode = head;
	while(currentNode){
		displayNode(currentNode);
	}
}

//Tim kiem ket qua

int FindNode(Node * head, char name[]){
	Node *currentNode = head;
	int currentIndex = 1;
	while(currentNode && currentNode->data.ten != name){
		currentNode = currentNode->next;
		currentIndex++;
	}
	if (currentNode) return currentIndex;
	else return 0;

}

float getPoint(Node * node){
	return (float)(node->data.diemk1 + node->data.diemk2)/2;
}

//Sap xep sinh vien theo diem trung binh
void arrangeNode(Node * head){
	Node *currentNode = head;


}

int main(){
	Node * head;
	
	system("pause");
	return 0;
}

