class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int f=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            return false;
        }
        return true;
    }
};