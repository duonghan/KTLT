#include<iostream>
#include<conio.h>

using namespace std;
    typedef struct node{
    
        int data;
        struct node * next;
        struct node *prev;
    }Node;
    
    int size;
    Node * head = new Node();
    Node * front = new Node();
    Node * rear = new Node();
    
    void InitQueue(){//khoi tao hang doi
        size = 0;
        head->next = head;
        head->prev = head;
        front = rear = head;
    }
    
    bool isEmpty(){//kiem tra hang doi rong
        return size == 0;
    }



    int getFront(){//hien thi front
        if(!isEmpty())
        return front->data;
        
        return 0;
    }
    
    int getRear(){//hien thi rear
        if(!isEmpty())
        return rear->data;
        return 0;
    }
    
    int deQueue(){//xoa ra phan tu front
        if(!isEmpty()){
            Node * temp = front;
            int item = front->data;
            
            front = front->next;
            head->next = front;
            front->prev = head;
            
            delete(temp);
            return item;
        }

        return 0;
    }

    void enQueue(int value){//them phan tu vao cuoi hang doi (rear)

        if(isEmpty()){//khi danh sach rong( chi gom nut dau gia)
            rear->data = value;

            rear->next = head;
            rear->prev = head;
            
            head->next = rear;
            head->prev = rear;//thay doi con tro
            front = rear;

        }else{
            Node * newNode = new Node();
            newNode->data = value;
            
            rear->next = newNode;
            newNode->next = head;
            newNode->prev = rear;
            head->prev = newNode;
            
            rear = newNode;
            
        }
        size++;
    }

int main(){
    int n, temp;
    InitQueue();
    
    cout<<"Nhap so phan tu cua hang doi: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"nhap phan tu can dua vao hang doi: ";
        cin>>temp;
        enQueue(temp);

    }

    cout<<"Phan tu front : "<<getFront()<<endl;
    cout<<"Phan tu rear : "<<getRear()<<endl;
    cout<<"Xoa phan tu o dau queue mang gia tri "<<deQueue()<<endl;
    cout<<"Phan tu front hien tai: "<<getFront()<<endl;
    cout<<"Them phan tu vao cuoi queue: ";
    cin>>temp;
    enQueue(temp);
    cout<<"Phan tu rear hien tai: "<<getRear()<<endl;
    
	system("pause");
	return 0;
}
