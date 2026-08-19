// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         string ans = "";
//         for(int i = 0; i<strs[0].size(); i++){
//             char ch = strs[0][i];
//             bool match = true;
//             // for comapring ch with rest of the strings :
//             for(int j = 1; j<n; j++){
//                 // not match :
//                 if(strs[j].size() <= i || ch != strs[j][i]){
//                     match = false;
//                     break;
//                 }
//             }
//             if(match == false){
//                 break;
//             }
//             else{
//                 ans.push_back(ch);
//             }
//         }
//         return ans;
//     }
// };
class TrieNode{
public:
    char data; 
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    int childcount;

    TrieNode(int val){
        this->data = val;
        isTerminal = false;
        childcount = 0;
    }
};

class Solution {
public: // solving the ques using Tries.

    void insertWord(TrieNode* root, string str){
        if(str.length() == 0){
            root->isTerminal = true;
            return;
        }
        char ch = str[0];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end()){
            // present :
            child = root->children[ch];
        }
        else{
            // absent :
            child = new TrieNode(ch);
            root->children[ch] = child;

            root->childcount++;
        }
        insertWord(child, str.substr(1));
    }
    string findLCP(TrieNode* root, string word){
        string ans = "";
        if(root->isTerminal){
            return ans;
        }
        for(int i = 0; i<word.length(); i++){
            char ch = word[i];

            // aage mai sirf tabhi move karunga jaab childcount 1 hoga :
            if(root->childcount == 1){
                ans.push_back(ch);
                root = root->children[ch];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        // insert all the nodes inside the trie

        for(int i = 0; i<strs.size(); i++){
            string str = strs[i];
            insertWord(root, str);
        }
        string ans = findLCP(root, strs[0]);
        return ans;
    }
};