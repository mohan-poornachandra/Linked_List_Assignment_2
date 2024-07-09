#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val=0){
            this->val = val;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        int size;
        LinkedList(){
            head = NULL;
            tail =NULL;
            size=0;
        }
        void insertAtTail(int val){
            Node* temp = new Node(val);
            if(size>0){
                tail->next = temp;
                tail = temp;
            }
            else{
                head = temp;
                tail = temp;
            }
            size++;
        }
        void insertAtHead(int val){
            Node* temp = new Node(val);
            if(size>0){
                temp ->next = head;
                head = temp;
            }
            else{
                head = temp;
                tail = temp;
            }            
            size++;
        }
        void insertAt(int idx, int val){
            if(idx<0||idx>size) cout<<"Invalid"<<endl;
            else if(idx ==0||size==0 ) insertAtHead(val);
            else if(idx == size) insertAtTail(val); //size is not yet updated, so idx==size!
            else{
                Node* temp = new Node(val);//Just have to link this with (idx)th Node and link temp with (idx+1)th Node
                int count = 1;
                Node* t = new Node(0);
                t = head;
                while(count<idx){
                    t = t->next;
                    count++;
                }
                temp->next = t->next;
                t->next = temp;
                size++;
            }

        }
        int getElement(int idx){
            if(idx<0||idx>=size) {
                cout<<"Invalid"<<endl;
                return -99999;
            }
            else if(idx==0) return head->val;
            else if(idx == size-1) return tail->val;
            else{
                Node* temp = new Node(0);
                temp = head;
                int count =0;
                while(count<idx){
                    temp = temp->next;
                    count++;
                }
                return temp->val;
            }
        }
        void deleteAtHead(){
            if(size==0){ cout<<"List already empty!" <<endl; return;}
            else if(size==1) head = tail= NULL;
            else{
                head = head->next;
            }
            size--;
        }
        void deleteAtTail(){
            if(size==0){ cout<<"List already empty!" <<endl; return; }
            else if(size==1) head = tail = NULL;
            else{
                Node* temp = new Node(0);
                temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                temp->next = NULL;
                tail = temp;
            }
            size--;
        }
        void deleteAt(int idx){
            if(size==0) cout<<"List already empty!" <<endl;
            else if(size==1) head = tail = NULL;
            else{
                if(idx ==0) deleteAtHead();
                else if(idx == size-1) deleteAtTail();
                else{
                    Node* temp = new Node(0);
                    temp = head;
                    int count =1;
                    while(count<idx){
                        temp = temp->next;
                        count++;
                    }
                    temp->next = temp->next->next;
                    size--;
                }
            }
        }
        void display(){
            Node* temp = new Node(0);
            temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp  = temp->next;
            }
            cout<<endl;
        }
        
};
int main(){
    LinkedList ll;
    int n;
    int ele;
    cout<<"Enter no. of elements: "; cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        ll.insertAtTail(ele);
    }
    int Val;
    cout<<"Enter val which has to be deleted: "; cin>>Val;
    ll.display();
    Node* temp = ll.head;
    while(temp){
        if(temp->next->val == Val){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    ll.display();
}