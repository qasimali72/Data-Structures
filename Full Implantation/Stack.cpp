#include <iostream>

using namespace std;

struct node{

    int info;
    node* next;
};

class Stack{
    private:
        node *top, *temp;
        int limit = 0, count = 0, key = 0;

    public:
        Stack();
        void Push();
        void Pop();
        void Top();
        void Print();
        // ~Stack();
};

Stack::Stack(){
    top = temp = NULL;
    cout << "Please Enter Limit Of Stack: ";
    cin >> limit;
}

void Stack::Push(){
    if (count != limit){
        temp = new node;
        cout << "Enter Data: ";
        cin >> temp->info;
        temp->next = top;
        top = temp;
        count++;
    }
    else
        cout << "Stack Overflow!\n";
}

void Stack::Pop(){
    if (count == 0)
        cout << "Stack Underflow!\n";
    else{
        temp = top;
        top = top->next;
        delete temp;
        temp = NULL;
        count--;
        cout << "Done\n";
    }
}

void Stack::Top(){
    cout << "Top Element is: " << top->info << endl;
}

void Stack::Print(){
    temp = top;
    if (temp == NULL)
        cout << "Stack Underflow!\n";
    else{
        while (temp != NULL ){
            if (temp->next != NULL)
                cout << temp->info << "->";
            else
                cout << temp->info;
            temp = temp->next;
        }
        cout << endl;
    }

}

int main(){
    Stack st;
    st.Push();
    st.Push();
    st.Push();
    st.Push();
    st.Push();
    st.Pop();
    st.Pop();
    st.Print();
    st.Top();
}
