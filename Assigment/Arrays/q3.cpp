// this function will find the size of array that will have the common elements
// of the both the arrays


#include<iostream>
using namespace std;

//FUNCTION DECLARATION
int size(int a[], int b[], int s1, int s2);
int *common(int a[], int b[], int s1, int s2);
void NoDuplicate(int *a, int ss);

int main()
{
   int s1=8; // varaible storing size of first array (arr1)
   int s2=4; // varaible storing size of second array (arr2)

   // intializing the arrays
   int arr1[s1]={1,2,3,4,5,6,3,2}; 
   int arr2[s2]={1,3,5,7};

   // callling the function
   int s=size(arr1, arr2,s1, s2);
   int * result=common(arr1, arr2,s1, s2);
   NoDuplicate(result, s);

   return 0;

}

// in a nested loop we will check for the common elements of the array and for each
//common element inc the size
int size(int a[], int b[], int s1, int s2)
{
    int size=0; // declaring and intializing the vaiable will 0. IT is will store
                // the size of the array
    
    for(int i=0; i<s1; i++) //loop that will find the common elements
    {
        for(int j=0; j<s2 ; j++)
        {
            if(a[i]==b[j]) // condtion for  finding common elements
            {
                size ++; //inc the size
            }
        }
    }

    return size; //returning the size
}

// this function will find the common elements in both the arrays 
// in a nested loop we will check whether the element of first array is in the second
// array if it is we will insert it  in a new array
int *common(int a[], int b[], int s1, int s2)
{
    int size=0; //varaible that store the size of new array
    int *p=new int [size]; // making an array at the run time 

    for(int i=0; i<s1; i++) // nested loop for comparing the values
    {
        for(int j=0; j<s2 ; j++)
        {
            if(a[i]==b[j]) // condition for checking the common elements
            {
                p[size]=a[i]; // putting the common element into the array
                ++size; // incr the size

            }
        }
    }

    return p; //  returning the array
}

// this ftn will remove the duplicates from the array
// and display it on the screen
// we will create a new array then we will check whether the element of the array we
// have passed to this function exist in this new array or not if it deos not exist we
// will insert it to the new array .. in the same way we will check for all the elements
void NoDuplicate(int *a ,int s)
{
    int size=0; // variable that will store the size of new array
    int arr[size]; // array that will contain the list with no duplicates

    for(int i=0; i<s; i++)
    {
        int find=0;

        for(int j=0; j<size; j++)
        {
            if(a[i]==arr[j]) // condition to check whether the element exist in the new array
            {
                find=1; 
            }
        }

        if(find==0) 
        {
            arr[size]=a[i];
            size++;
        }
    }

    //displaying the final array array with no duplicates
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
