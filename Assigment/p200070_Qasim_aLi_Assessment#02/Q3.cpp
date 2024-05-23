#include <iostream>
#include <string.h>



using namespace std;

    char** solutions;
    int n_solution=0;
 
    void staircase(int n, char *results);
    char* stringAdd(char* begin, char* end);
    void addSolution(char* solution);
 
    void staircase(int n, char *results)
    {   
        char *str1,*str2;
        if (n == 1)
        {   
            str1 = stringAdd(results, ",1");
            addSolution(str1);
            free((void*)str1);
            return;
        }
        else if (n == 0)
        {   
            addSolution(results);
            return;
        }
 
        str1 = stringAdd(results, ",1");
        str2 = stringAdd(results, ",2");
        staircase(n-1, str1);
        staircase(n-2, str2);  
        free((void*)str1);
        free((void*)str2); 
    }
 
    char* stringAdd(char* begin, char* end)
    {   
        char* str;
        str = (char*) malloc(sizeof(char) * (strlen(begin)+ strlen(end) + 1));
        if (str == NULL) exit(1);
        str = strcpy(str, begin);
        str = strcat(str, end);
        return str;
    }
 
    void addSolution(char* solution)
    {   
        //char *second= new char("hello");      dynamic allocation
          char str = (char) malloc(sizeof(char) * strlen(solution) + 1);

        if (str == NULL) exit(1);
        n_solution++;
        solutions = (char*) realloc(solutions, sizeof(char) * n_solution);
        if (solutions == NULL)
        {
            free(solutions);
            exit(1);
        }
        str = strcpy(str, solution);
        solutions[n_solution-1] = str;
        return;
    }
 
 
int main(int argc, char* argv[])
    {   
         int N;
    cout<<"Enter the number do you want to find a =";
    cin>>N;
        int i;
        solutions =solutions= new char*;
        if (solutions == NULL) exit(1);
        staircase(N,"");
        
        for(i=0; i< n_solution; i++ )
        {   
            cout << "\n" << solutions[i]+1;
            free((void*)solutions[i]);
        }    
        cout<<"\n";
        free(solutions);
        
        return 0;
    }