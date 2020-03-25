#include <iostream>

using namespace std;
struct node{
    int data;
    node* next;
};
node* create_list(int data){
    node* head = new node;
    head->data=data;
    head->next=NULL;
    return head;
}
void print_list(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }cout<<endl;
}
node* end_of_list(node* head){
    node* temp =head;
    while(temp->next!=NULL){
        temp=temp->next;
    }return temp;
}
node* append(node* head,int data){
    node* temp=new node;
    temp->data=data;
    if(head->next==NULL){
        temp->next=head->next;
        head->next=temp;
    }
    else{
    node* ptr=end_of_list(head);
    temp->next=ptr->next;
    ptr->next=temp;
    }
    // return head;
}

int main()
{
    node* head=create_list(10);
    append(head,20);
    // cout<<head->data;
    // cout<<head->next->data;
    append(head,30);
    //  append(head,40);
    print_list(head);
    // cout<<head->data;

    return 0;
}
