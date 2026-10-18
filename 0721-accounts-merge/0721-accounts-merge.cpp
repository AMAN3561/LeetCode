class Solution {
public:
    int findparent(vector<int>& parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findparent(parent, parent[node]);
    }
    void Union_set(int u, int v, vector<int>& parent, vector<int>& rank){
        int parA = findparent(parent, u);
        int parB = findparent(parent, v);

        if(parA == parB){
            return;
        }
        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        unordered_map<string, int> mp;

        for(int i = 0; i<n; i++){
            auto& account = accounts[i];
            for(int j = 1; j<account.size(); j++){
                string& mail = account[j];
                auto it = mp.find(mail);
                if(it == mp.end()){
                    mp[mail] = i;
                }
                else{
                    Union_set(i, it->second, parent, rank);
                }
            }
        }
        unordered_map<int, set<string>> pre_ans;
        for(auto it: mp){
            auto accountNo = it.second;
            auto mail = it.first;
            accountNo = findparent(parent, accountNo);
            pre_ans[accountNo].insert(mail);
        }

        vector<vector<string>> ans;
        for(auto it: pre_ans){
            auto accountNo = it.first;
            auto email_str = it.second;
            vector<string> v;
            v.push_back(accounts[accountNo][0]);
            for(auto mail: email_str){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;
    }
};