

#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *prev;
        node *next;
node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DLL
{
    public:
        node *head;
        int length;

    DLL()
    {
        head=NULL;
        length=0;
    }    
    void insertion(int val, int pos);
    void RemoveDuplicates();
    void print();
    
};


void DLL::insertion(int val, int pos)
{
    if(pos>length+1 || pos< 1)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    node *n=new node(val);
    

    if(pos==1)
    {
        n->next=head;
        if(head!=NULL)
           head->prev=n;
        head=n;

    }

    else
    {
        node *current=head;

        for(int i=1; i<(pos-1); i++)
        {
            current=current->next;
        }

        n->next=current->next;
        n->prev=current;
        if(current->next!=NULL)
            current->next->prev=n;
        current->next=n;
    }

    length++;
}

void DLL::print()
{
    node *p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}


void DLL::RemoveDuplicates()
{
   
    node *temp=head;


    while(temp->next!=NULL) 
    {
        if(temp->data==temp->next->data) 
        {
            if(temp==head) 
            {
                head=temp->next;
                head->prev=temp->prev;
                node *n=temp;
                temp=head;
                delete n;
            }
            else  
            {
                node *n=temp;
                node *p=temp->prev;
                p->next=temp->next;
                if(temp->next!=NULL)
                temp->next->prev=p;

                temp=p->next;
                delete n;
            }
        }
        else 
        {
            temp=temp->next;
        }   
    }
}

int main()
{
    DLL obj1;
    obj1.insertion(1,1);
    obj1.insertion(2,2);
    obj1.insertion(2,3);
    obj1.insertion(3,4);
    obj1.insertion(4,5);
    obj1.insertion(4,6);
    obj1.insertion(5,7);
    obj1.insertion(5,8);
    obj1.insertion(5,9);
    

    cout<<"Before the removing duplicates."<<endl;
    obj1.print();
    cout<<"//=====================//";

    cout<<"After the removing duplicates."<<endl;
    obj1.RemoveDuplicates();
    obj1.print();
    
}


