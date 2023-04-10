#include<iostream>
using namespace std;


void incOrder(int i) // i se lekar 10 tak counting karni hai
{
    if(i==10)
    {
        cout<<i<<endl;
        return ;
    }

    cout<<i<<" ";
    incOrder(i+1);
}

void decOrder(int i) // 10 se lekar i tak dec order mein numbers print karna
{   
    if(i==10)
    {
        cout<<i<<" ";
        return ;
    }
    decOrder(i+1);
    cout<<i<<" ";
}


int fact(int N) // this function return factorial of N
{
    if(N==0)
    {
        return 1;
    }
    int smallerSubproblem=fact(N-1);
    return N*smallerSubproblem;
}

int sum(int N) // this function gives me sum of N....1
{   
    if(N==1)
    {
        return 1;
    }
    int chotiProblem=sum(N-1);
    return N + chotiProblem;
}

int power(int a,int b) // this function return a^b
{
    if(b==0)
    {
        return 1;
    }
    int smallerSub=power(a,b-1);
    return a*smallerSub;
}

int fib(int N) // give me nth fibonacci number
{
    // if(N==0) return 0;
    // if(N==1) return 1;
    if(N==0 || N==1) return N;

    int smallerSub1=fib(N-1);
    int smallerSub2=fib(N-2);
    return smallerSub1 + smallerSub2;
}


int fastPower(int a,int b) // return a^b
{
    if(b==0) return 1;

    // eg a=3, b=14
    int smallerSubproblem=fastPower(a,b/2);  // (3^7)= 


    if(b%2==0) // b is even
    {
        return smallerSubproblem * smallerSubproblem;
    }
    else
    {   
        // b is odd
        return a* smallerSubproblem * smallerSubproblem;
    }
}

// bool is_sorted(int *A,int i,int n) //
// {

// }

int main()
{
    cout<<power(5,4)<<endl;

    return 0;
}
