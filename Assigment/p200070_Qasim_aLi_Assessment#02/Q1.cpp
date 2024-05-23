#include<iostream>
using namespace std;
struct node
{
    string data;
    node* next;
    int date;
    int priority;
};
class queue
{
private:
    struct node *front,*rear=0;
    struct node *curr=0;
    public:
    bool isempty()
{
    if(front==0 || rear==0)
        return true;
    else
        return false;
}
void enqueue()
{
    struct node* newnode=new node;
    cout << "Write a message ";
    getline(cin,newnode->data);
    cout << "Write priority ";
    cin >> newnode->priority;
    cout << "Write a date ";
    cin >> newnode->date;
    newnode->next = NULL;
    cin.ignore();
if(isempty())
    {
        curr=rear=front=newnode;
    }
while(curr!=NULL)
{
    if(curr->date > newnode->date || curr->priority>newnode->priority)
{
    curr->next=newnode;
    rear=curr;
    return ;
}
    if(curr->date<newnode->date || curr->priority<newnode->priority)
    {
            newnode->next=curr;
            front=newnode;
            return ;
    }
    curr=curr->next;
    }
}
void display()
    {
        struct node* temp;
        temp=front;
        while(temp!=0)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
        cout<<endl;
    }
};
int main()
{
queue q;
q.enqueue();
q.enqueue();
q.display();
return 0;
}