#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(){
       data=0;
       next=NULL;
    }
 };
class LinkList{
protected:  node *inOf(int index);
public: node *head,*last;
    int size;
    LinkList(){
        head=NULL;
        last=NULL;
        size=0;
    }
    int find(int value);
    
    int get(int index);
    void add(int value,int index);
    void remove(int index);
    void delAll();
    int sizeLink();
    LinkList apend(LinkList linklist);
    LinkList reverse();
    LinkList clone();
    void sort(int index);
    
};
int main(){
    LinkList snode;
    snode.add(3,0);
    snode.add(2,-1);
    cout<<snode.get(0)+snode.get(1);
}
int LinkList::get(int index){
    node*heads=head;
    int i=0;
    while(heads!=NULL){
        if(i==index)return heads->data;
        i++;
        heads=heads->next;
    }
    return 0;
}
int LinkList:: find(int value){
    int i=0;
    node*heads=head;
    while(NULL!=heads){
        if(heads->data!=value){heads=heads->next;(i)++;}
        return i;
    }
    return -1;
};
node* LinkList:: inOf(int index){
    
    if(index<0||index>=size) return NULL;
    int i=0;
  node * heads=head;
    while(i!=index)
    { i++;
        heads=heads->next;
        
    }
    return heads;

}
void LinkList::add(int value, int index){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=value;
    if((index==0||index==-1)&&head==NULL){
        head=temp;last=temp;
    }
    else if(index==0){
        temp->next=head;
        head=temp;
    }
    else if(index==-1){
        last->next=temp;
        last=temp;
    }
    else if(index<size&&index>0){
       node *nodei =inOf(index-1);
        temp->next=nodei->next;
        nodei->next=temp;
    }
    else{
        cout<<"error!"<<endl;
        exit(0);
    }
    
    size++;
}
void LinkList::remove(int index){
    if(index==0){
        node *h=head->next;
        delete (head);
        head=h;
        delete (h);
    }
    else if (index==-1){
        node *h=inOf(size-2);
        delete (last);
        h->next=NULL;
        last=h;
    }
    else {
        node* temp=inOf(index-1);
        if(temp==NULL)return;
        temp->next=(temp->next)->next;
        delete temp->next;
    }
    size--;
}
LinkList LinkList::clone(){
    LinkList snodeC;
    
    node*heads=head;
    while(heads!=NULL){
        snodeC.add(heads->data,-1);
        heads=heads->next;
    }
    return snodeC;
}
LinkList LinkList:: apend(LinkList linklist){
    LinkList snodeA;
    snodeA=clone();
    node*heads=linklist.head;
    while(heads!=NULL){
        snodeA.add(heads->data,-1);
        heads=heads->next;
    }
    return snodeA;
}
void LinkList:: delAll(){
    while(head!=NULL){
        remove(0);
    }
}
int LinkList::sizeLink(){
    return size;
}
LinkList LinkList::reverse(){
    LinkList snodeR;
    node*heads=head;
    while(heads!=NULL){
        snodeR.add(heads->data,0);
        heads=heads->next;
    }
return snodeR;
}
void LinkList::sort(int index){
    int *arr=(int *)malloc(size*sizeof(int));
    int h=0;
    node* heads=head;
    while(heads!=NULL){
        arr[h]=heads->data;
        h++;
        heads=heads->next;
    }
    if(index==1){
        for(int i=0;i<size-1;i++){
            for(int j=i;j>0;j--){
                if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
            }
        }
    }else{
        for(int i=0;i<size-1;i++){
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j+1])swap(arr[j],arr[j+1]);
            }
            
        }
        
    }
    
            delAll();
            for(int i=size-1;i>=0;i--){
                add(arr[i],0);
            }
            delete arr;
    
}
