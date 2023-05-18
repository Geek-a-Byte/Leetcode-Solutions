class Solution {
public:
    bool isValid(string s) {
        
        stack<char>stk;
        int cnt=0;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[')
            {
                stk.push(i);
            }
            else if(stk.size()>0 and ((i==')' and stk.top()=='(') or (i=='}' and stk.top()=='{') or (i==']' and stk.top()=='[')))
            {
               stk.pop();
            }
            else
            {
                cnt++;
            }
        }
        if(stk.size()==0 and cnt==0)
        {
            return true;
        }
        return false;
    }
};