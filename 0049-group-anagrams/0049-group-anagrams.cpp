class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string> > ans;

        for(int i = 0; i< strs.size(); i++){
            string st = strs[i];
            string temp = st;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(st);
        }

        for(auto i : mp){
            // is representing a record inside map mp

            ans.push_back(i.second);
        }
        return ans;
    }
};