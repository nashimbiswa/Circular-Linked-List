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
    cout<<"Node in the list are as follows:\n";
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

int main(int argc, char const *argv[])
{
   Node *head=0;
   createNodes(head);
   display(head);
   return 0;
}
