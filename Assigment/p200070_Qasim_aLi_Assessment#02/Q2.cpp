#include<iostream> 
using namespace std; 
struct node
{ 
    int data; 
    node* left; 
    node* right;
};
class binarytree{ 
    public: 
        node* root; 
        binarytree()
{
    root=NULL; node* 
    left=NULL; node* 
    right=NULL;
}
bool insert(int key)
{
    node* newnode=new node; 
    newnode->data=key; 
    newnode->left=NULL; 
    newnode->right=NULL; 
    if(root==NULL)
        {
            root=newnode;
        }
    else
    {
    node* temp=root; 
    while(temp)
    {
        if(key<temp->data)
        {
            if(temp->left!=NULL)
            {
                temp=temp->left;
            }
            else
            {
                temp->left=newnode;
                return true;
            }
        }
    else if (key>temp->data)
        {
            if (temp->right!=NULL)
        {
    temp=temp->right;
    }
    else
        {
            temp->right=newnode;
            return true;
        }
    }
    else
        {
            cout<<"duplicate value in tree "; 
            return false;
        } 
    } 

}

}
void display(node* root)
{
    if(root!=NULL)
    { 
        display(root->left); 
        cout<<root->data<<" -> "; 
        display(root->right);
}
}
void search(node* root,int key)
{
    if(root==NULL) 
    cout<<"empty!!"; 
    if(key==root->data)
    {
        cout<<"found";
    }
else if(key<root->data)
    {
        search(root->left,key);
    }
else if(key>root->data)
    {
        search(root->right,key);
    }
else
    cout<<"Not found";
}



bool ancestor(node* root,int key)
    {
        node* temp=root; 
        if(key==temp->data)
    {
    return temp->data;
}
    else if(key<temp->data)
{
    temp=temp->left; 
    ancestor(root->left,key); 
    cout<<root->data<<" -> "; 
    return true;
}
else
    {
        temp=temp->right; 
        ancestor(root->right,key); 
        cout<<root->data<<" -> "; 
        return true;
    } 
}
};
int main()
{
    binarytree b;
    b.insert(5);
    b.insert(4);
    b.insert(3);
    b.insert(7);
    b.insert(10);
    b.insert(20);
    b.display(b.root); 
    cout<<endl<<"Searching node of 10::";
    b.search(b.root,10); 
    cout<<endl; 
    cout<<"Ancester of 20 is:: ";
    b.ancestor(b.root,20); 
    cout<<endl; 
    cout<<"Ancestor of 3 is:: ";
    b.ancestor(b.root,3); 
    return 0;
}