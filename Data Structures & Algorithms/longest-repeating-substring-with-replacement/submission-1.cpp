class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_map<char,int> freq;
    int l = 0, r = 0, maxlen = 0,maxfreq=0; 

    while(r<s.size()) 
         {freq[s[r]]++;
          maxfreq = max(maxfreq, freq[s[r]]);

          if ((r - l + 1) - maxfreq > k) 
             { freq[s[l]]--; 
               l++;}
        
         maxlen = max(maxlen, r - l + 1);
         r++;
         }
    return maxlen;  
    }
};
