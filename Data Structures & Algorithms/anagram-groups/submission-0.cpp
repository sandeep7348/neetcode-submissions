class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string value=strs[i];
            vector<int> count(26,0);
            for(int j=0;j<value.length();j++)
            {
                count[value[j]-'a']++;
            }
            string ans="";
            for(int k=0;k<26;k++)
            {
                 ans += to_string(count[k]) + "#";
            }
            m[ans].push_back(value);
        }
        vector<vector<string>> finalValue;
        for(auto x:m)
        {
            finalValue.push_back(x.second);
        }
        return finalValue;
    }
};
