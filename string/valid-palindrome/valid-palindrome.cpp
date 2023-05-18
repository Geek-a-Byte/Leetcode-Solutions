class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        for(auto i:s)
        {
            if((i>=65 and i<=90) or (i>=97 and i<=122) or (i>='0' and i<='9'))
            {
                char j=tolower(i);
                ss+=j;
            }
        }
        cout<<ss<<endl;
        int n=ss.length();
        int half=n/2;
        int f=0;
        for(int i=0;i<half;i++)
        {
            if(ss[i]!=ss[n-i-1])
            {
               f=1;
               break;
            }
        }
        if(f==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};