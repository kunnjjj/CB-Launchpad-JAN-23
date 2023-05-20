// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool match(stack<char> &ST,char match)
    {
        return (!ST.empty() && ST.top()==match); 
    }

    bool isValid(string s) {
        int n=s.size();
        stack<char> ST;
        for(int i=0;i<=n-1;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                ST.push(s[i]);
                continue;
            }
            if(s[i]==')')
            {
                if(!match(ST,'(')) return false;
                else ST.pop();
            }
            if(s[i]==']')
            {
                if(!match(ST,'[')) return false;
                else ST.pop();
            }
            if(s[i]=='}')
            {
                if(!match(ST,'{')) return false;
                else ST.pop();
            }
        }
        return ST.empty();

    }
};