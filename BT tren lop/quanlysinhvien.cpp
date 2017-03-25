#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string.h>
#include<iomanip>

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

void displaySV(sinhvien sv){
    cout<<setfill(' ');
    cout<<"|";
    cout<<setw(10)<<left<<sv.masv;
    cout<<"|";
    cout<<setw(12)<<left<<sv.malop;
    cout<<"|";
    cout<<setw(30)<<left<<sv.ho;
    cout<<"|";
    cout<<setw(30)<<left<<sv.ten;
    cout<<"|";
    cout<<setw(9)<<right<<sv.diemk1;
    cout<<"|";
    cout<<setw(9)<<right<<sv.diemk2;
    cout<<"|"<<endl;
    cout<<setfill('-');
    cout<<"+"<<setw(11)<<"+"<<setw(13)<<"+"<<setw(31)<<"+"<<setw(31)<<"+"<<setw(10)<<"+"<<setw(10)<<"+"<<endl;
}

void displayTitle(){
    cout<<setfill('-');
    cout<<"+"<<setw(11)<<"+"<<setw(13)<<"+"<<setw(31)<<"+"<<setw(31)<<"+"<<setw(10)<<"+"<<setw(10)<<"+"<<endl;
    cout<<setfill(' ');
    cout<<"|";
    cout<<setw(10)<<left<<"Ma SV";
    cout<<"|";
    cout<<setw(12)<<left<<"Ma lop";
    cout<<"|";
    cout<<setw(30)<<left<<"Ho";
    cout<<"|";
    cout<<setw(30)<<left<<"Ten";
    cout<<"|";
    cout<<setw(9)<<right<<"Diem ky 1";
    cout<<"|";
    cout<<setw(9)<<right<<"Diem ky 2";
    cout<<"|"<<endl;
    cout<<setfill('-');
    cout<<"+"<<setw(11)<<"+"<<setw(13)<<"+"<<setw(31)<<"+"<<setw(31)<<"+"<<setw(10)<<"+"<<setw(10)<<"+"<<endl;
}

void displayList(Node *head){
    displayTitle();
    Node * currentNode = head->next;
    while(currentNode != head){
        displaySV(currentNode->data);
        currentNode = currentNode->next;
    }
}

//chen vao danh sach
void InsertNode(Node * head, sinhvien sv){
    Node *newNode, *currentNode;
    newNode = new Node();
    newNode->data = sv;
    currentNode = head->next;
    while(currentNode != head) {
        if(strcmp(currentNode->data.ten,sv.ten) == -1){
            currentNode = currentNode->next;
        }else break;
    }

    newNode->next = currentNode;
    newNode->prev = currentNode->prev;

    currentNode->prev = newNode;
    (newNode->prev)->next = newNode;
    
}

//Tim kiem ket qua theo ten
int find_Name(Node * head, char * name){//Tra ve vi tri dau tien cua ten sv trong ds lop
    Node * currentNode = head->next;
    int currentIndex = 1;
    while(currentNode != head && strcmp(currentNode->data.ten,name) != 0){
        currentNode = currentNode->next;
        currentIndex++;
    }
    return currentIndex;
    

}

//hien thi du lieu 1 lop theo ten
void diplay_Class(Node * head, char * lop){

    Node * currentNode = head->next;
    int currentIndex = 1;
    
    while(currentNode != head) {
        if (!strcmp(currentNode->data.malop,lop))
        {   
            displaySV(currentNode->data);
            currentIndex++;
        }
        currentNode = currentNode->next;
    }
}

//Sap xep sinh vien theo diem trung binh

float getAvg(sinhvien sv){
    return (sv.diemk1 + sv.diemk2)/2;
}

void sortNode(Node * head){//sao chep danh sach ra 1 mang roi thuc hien sap xep noi bot tren mang
    sinhvien * dssv = new sinhvien[1000];
    int i = 0;
    Node * currentNode;
    for (currentNode = head->next; currentNode!= head; currentNode = currentNode->next)
    {
        dssv[i] = currentNode->data;
        i++;
    }
    int length = i;
    for (i = 0; i < length - 1; i++)
        for (int j = i+1; j < length; j++)
        {
            if(getAvg(dssv[i])<getAvg(dssv[j])){
                sinhvien temp = dssv[i];
                dssv[i] = dssv[j];
                dssv[j] = temp;
            }
        }

    for (i = 0; i<length; i++)
    {
        displaySV(dssv[i]);
    }
    cout<<endl;
}

int main(){

    //khai bao danh sach
    Node * head =new Node();
    head->next = head;
    head->prev = head;

    sinhvien sv;
    char ch;
    char * sv_name = new char();
    char * malop = new char();

    cout<<"Cau1. Nhap danh sach sinh vien:"<<endl<<endl;
    do{
        cout<<"Nhap MSSV: ";
        cin>>sv.masv;
        cout<<"Nhap ma lop:";
        cin>>sv.malop;
        cout<<"Nhap Ho: ";
        cin>>sv.ho;
        cout<<"Nhap ten: ";
        cin>>sv.ten;
        cout<<"Diem ky 1: ";
        cin>>sv.diemk1;
        cout<<"Diem ky 2: ";
        cin>>sv.diemk2;
        InsertNode(head, sv);
        cout<<"Tiep tuc nhap thong tin sinh vien (C/K)! :";
        cin>>ch;
    }while(ch != 'k' && ch != 'K');

    cout<<"danh sach cac sinh vien :"<<endl;//hien thi danh sach sinh vien sau khi nhap
    displayList(head);

    cout<<endl<<endl<<"Cau 2:hien thi du lieu 1 lop theo thu tu ten"<<endl;
    fflush(stdin);
    cout<<"Nhap ma lop :";
    cin>>malop;
    cout<<"Ket qua:"<<endl;
    displayTitle();
    diplay_Class(head, malop);

    cout<<endl<<endl<<"Cau 3: tim kiem ket qua theo ten"<<endl;
    cout<<"Tim kiem"<<endl;
    fflush(stdin);
    cout<<"Nhap ten sinh vien: ";
    cin>>sv_name;
    if(find_Name(head,sv_name)) cout<<"Vi tri sinh vien: "<<find_Name(head,sv_name)<<endl;
    else cout<<"khong co sinh vien nay!"<<endl;

    cout<<endl<<endl<<"Cau 4:Sap xep theo diem trung binh"<<endl;
    displayTitle();
    sortNode(head);

    delete(head);
    system("pause");
    return 0;
}

