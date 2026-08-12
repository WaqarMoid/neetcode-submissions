class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> result;
    
    unordered_map<string, vector<string>> mp;

    for (string s : strs) 
    {
        string key = s;
        sort(key.begin(), key.end()); // Sorting gives the canonical key
        mp[key].push_back(s);         // Group original string under its key
    }

    for (auto& pair : mp) 
    {
        result.push_back(pair.second);
    }
    
    return result;
    }
};
