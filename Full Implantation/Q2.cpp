// same number in both array , with same loction 



#include<iostream>
using namespace std;
int pow(int,int);
int factorial(int);
void Question_1(){
    int sameL=0;
    int rept=0;
    int a[6]={2,45,5,7,4,53};
    int b[6]={52,7,5,6,4,45};
    int *ptr1=a;
    int *ptr2=b;


    for(int i=0;i<6;i++){
        //cout<<a[i]<<" : "<<b[i]<<endl;
        if(*ptr1==*ptr2){
            sameL+=1;
        }
        ptr1+=1;
        ptr2+=1;

    }
    ptr1=a;
    for(int i=0;i<6;i++){
        ptr2=b;
        for(int j=0;j<6;j++){
            if(*ptr1==*ptr2){
                //cout<<"Hjkl";
                rept+=1;
                break;
            }
            ptr2=ptr2+1;
        }
        ptr1+=1;
    }
    cout<<"Same Locations are : "<<sameL<<endl<<"Same numbers are : "<<rept;
}

int main(){
    Question_1();
   // Question3();
    }
