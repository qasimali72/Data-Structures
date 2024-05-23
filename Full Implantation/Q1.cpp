#include<iostream>
using namespace std;
/*
//
//  X - (X^3 / 2!) + (X^5 / 4!) - (X^7 / 6!) + (X^9 / 8!) - (X^11 / 10!) + ..................
//
*/
void Question3(){
    int x,n;
    double den,num,sum=0.0;
    cout<<"Enter the value of X : ";
    cin>>x;
    cout<<"Enter the value of N : ";
    cin>>n;
    if(n==1)  {cout<<x<<endl; return;}
    int chk=0;
    for(int i=1;i<=n;i++){
        num=pow(x,2*i-1);
        den=factorial(2*i-2);
        if(chk%2==0){
            sum=sum+ (num/den);
        }
        else if(chk%2==1){
            sum=sum-(num/den);
        }
        chk+=1;
    }
    cout<<"Required value is : "<<sum;

}
int pow(int x,int n){
    int sum=x;
    for(int i=1;i<n;i++){
        sum*=x;
    }
    return sum;
}
int factorial(int x){
    int res=1;
    for(int i=1;i<=x;i++){
        res*=i;
    }
    return res;
}
int main(){
    //Question_1();
    Question3();
    }
