class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    int i=s1.size(),j=s2.size();
    vector<int> freq1(26, 0), freq2(26, 0);

    for(char c:s1)
    {freq1[c-'a']++;}
    int l=0;
    for(int k=0;k<j;k++)
       { freq2[s2[k]-'a']++;
         if(k-l+1>i)
          {freq2[s2[l]-'a']--;
          l++;}
        if(freq1==freq2)
        return true;    
       }
    return false;
    }
};