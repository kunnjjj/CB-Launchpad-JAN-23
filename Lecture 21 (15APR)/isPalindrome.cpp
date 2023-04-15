#include<iostream>
using namespace std;

bool is_palindrome(string &s,int i,int j) 
{
    if(i>=j) return true;
    // return true if string s[i].......s[j] is palindrome or not
    // else return false;

    // if(s[i]==s[j])  // M1
    // {
    //     return is_palindrome(s,i+1,j-1);
    // }
    // else return false;
    if(s[i]==s[j] && is_palindrome(s,i+1,j-1))  // BACHA NO. 1
    {
       return true;
    }
    else return false;

    // if(is_palindrome(s,i+1,j-1) && s[i]==s[j])  // BACHA NO. 2  
    // {
    //     return true;
    // }
    // else return false;
}

// 1. BOTH GIVE DIFFERENT RESULT B1 is correct
// 2. BOTH GIVE DIFFERENT RESULT B2 is correct
// 3. BOTH GIVE SAME RESULT BACCHA 1 IS MORE EFFICIENT THAN BACHA 2 (CORRECT OPTION SEE NOTES)
// 4. BOTH GIVE SAME RESULT BACCHA 2 IS MORE EFFICIENT THAN BACHA 1

int main()
{
    
    


    return 0;
}