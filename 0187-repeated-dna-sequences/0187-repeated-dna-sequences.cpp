class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seqcount;
        vector<string> ans;

        if(s.size() < 10) return {};

        for(int i = 0; i<= s.size() - 10; i++){
            auto current_sub_string = s.substr(i, 10);
            seqcount[current_sub_string]++;
        }
        // iterate over the map :
        for(auto [substr, freq] : seqcount){
            if(freq > 1){
                ans.push_back(substr);
            }
        }
        return ans;
    }
};