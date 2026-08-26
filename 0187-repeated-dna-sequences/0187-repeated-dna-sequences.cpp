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
        for(auto& [Repeated_DNA, freq] : seqcount){ // using string by reference to avoid copying of string.
            if(freq > 1){
                ans.push_back(Repeated_DNA);
            }
        }
        return ans;
    }
};