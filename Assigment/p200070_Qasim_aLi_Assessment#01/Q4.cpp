#include<iostream>
using namespace std;

        // Function to check the character
bool isChar(int c)
{
        return ((c >= 97 && c <= 122)|| 
            (c >= 65 && c <= 99));
            
}
bool isDigit(const char c)
{
        return (c >= '0' && c <= '9');
} 

bool Verfied(string email){
            int count=0;
            int dotcount=0;
            int At =-1;
        if (!isChar(email[0]))
            {
                return 0;
            }

    for (int i = 0;i < email.length(); i++) {
            // If the character is '@'    
        if (email[i] == '@') {
            At = i;
            count=count+1;
            if (count>1 )
            {
                break;
            }
            
        }
        else if (email[i] == '.') {
            dotcount= dotcount+1;
            if (dotcount >= 1)
            {
                return 1;
            }
        
        }
     };
    

};



bool viad(string password){
        // Input a string  for user 
        int flag=0;
if (password.length() > 5 && password.length() < 11 )
{
        //checking if string special character and number 
  for(int i=0; i < password.length();i++)
  {
    if ((password[i]>=48 && password[i]<=57)||
        (password[i]>=65 && password[i]<=90)||
        (password[i]>=97 && password[i]<=122))
        {
          continue;
        }
    else
    { 
        flag =1;
        return 1;
        continue;
    }
        continue;
    if (flag ==0)
      {
        return 0;
      } 
  };
}

return 0;
};



//main function
int main(){

string email;
cout<<"Enter the Email : ";
cin>>email;

string password;
cout<<"Enter a string: ";
cin>>password;

bool check = Verfied(email);

if (check) {
        cout << email << " : "
             << "valid" << endl;
    }
    else {
        cout << email << " : "
             << "invalid" << endl;
    }

bool ans = viad(password);

bool viad(ans);
    if (ans)
    {
        cout << password << " : "
             << "valid" << endl;
    }
    else {
        cout << password << " : "
             << "invalid" << endl;
    }
    
    
  return 0;    
};