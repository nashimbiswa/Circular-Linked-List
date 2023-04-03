#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int var;
    Node * next;
    Node(int x)
    {
        var=x;
        next=nullptr;
    }
};

void createNodes(Node *&head)
{
    Node*temp=head;
    int choice=1;
    while (choice==1)
    {   
        int data;
        cout<<"Enter the data in the list:\n";
        cin>>data;
        Node *newnode=new Node(data);
        if(head==nullptr)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    cout<<"Enter your choice 1 to continue 0 to discontinue:\n";
    cin>>choice;
    }
    temp->next=head;
}

void display(Node *head)
{
    Node *temp=head; 
    while(temp->next!=head)
    {
        cout<<temp->var;
        cout<<" ";
        temp=temp->next;
    }
    //for last remaining one node data 
    cout<<temp->var;
}

//Inserting a new node in the beginning of a list.
void inertAtBeginning(Node *&head,int data)
{
    Node* newnode=new Node(data);
    if(head==nullptr)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        // newnode->next=head;
        // head=newnode;
        Node* temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }   
}

void insertAtEnd(Node *&head,int data)
{
    Node* newnode=new Node(data);
    Node *temp=head;
    if(head==0)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }

}

void deleteHeadOfTheList(Node *&head)
{
    if(head->next==head)
    {
        Node*temp=head;
        delete(head);
        head=0;
        return;
    }
    Node*temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    Node* free=head;
    delete(free);
    head=temp->next;
}

int lengthOfNode(Node *head)
{
    Node* temp=head;
    int i=0;
    while (temp->next!=head)
    {
        temp=temp->next;
        ++i;
    }
    return (i+1);
    
}
void deleteKthNode(Node *&head,int position)
{
    if(!head) return;
    if(position>lengthOfNode(head))
        return;
    if(position==1)
    {
        deleteHeadOfTheList(head);
        return;
    }
    Node *temp=head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        ++i;
    }
    Node *remove=temp->next;
    temp->next=temp->next->next;
    delete(remove);

}
int main(int argc, char const *argv[])
{
   Node *head=0;
   createNodes(head);
   display(head);
//    int data;
//    cout<<"\nEnter data in the first node:\n";
//    cin>>data;
//    inertAtBeginning(head,data);
    // cout<<"\nEnter data in the End node:\n";
    // cin>>data;
    // insertAtEnd(head,data);
    int position;
    cout<<"\nEnter a position to delete:\n";
    cin>>position;
    deleteKthNode(head,position);
    cout<<"\nUpdated list is:\n";
    display(head);
    return 0;
}
