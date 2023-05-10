unordered_map<char,int>used;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        used.clear();
        mp.clear();
        int j=0;
        for(auto i:s)
        {
            if(used[t[j]]==0){
                mp[i]=t[j];
                used[t[j]]=1;
            }
            j++;
        }
        string w="";
        int k=0;
        for(auto i:s)
        {
            if(used[t[k]]==1) w+=mp[i];
            k++;
        }
        cout<<w<<" "<<t<<endl;
        if(w==t) return true;
        else return false;
    }
};