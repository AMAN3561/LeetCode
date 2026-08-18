class TrieNode{
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val){
        this->data = val;
        isTerminal = false;
    }
};
void insertWord(TrieNode* root, string word){
    // base case :
    // aagar saare character trie mai insert kr chuka hu toh, vo ek terminal node hai :
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    // 1 case hamne solve kiya :
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present :-> move to that child.
        child = root->children[ch];
    }
    else{
        // absent :
        child = new TrieNode(ch);
        // link :
        root->children[ch] = child;
    }
    // baaki recursion sambhalega :
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    // base case :
    if(word.length() == 0){
        // matlb ke last char pr hai hmm
        // if(root->isTerminal == true){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return root->isTerminal;
    }

    // 1 case hmm solve karenge :
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present: 
        child = root->children[ch];
    }
    else{
        // absent :
        return false;
    }
    // recursion :
    bool recursionKaAns = searchWord(child, word.substr(1));
    return recursionKaAns;
}
bool searchPrefix(TrieNode* root, string word){
    // base case :
    if(word.length() == 0){
        return true;
    }

    // 1 case hmm solve karenge :
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present: 
        child = root->children[ch];
    }
    else{
        // absent :
        return false;
    }
    // recursion :
    bool recursionKaAns = searchPrefix(child, word.substr(1));
    return recursionKaAns;
}

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertWord(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool startsWith(string prefix) {
        // search() jesa hee code aaega without the check for isTerminal:
        return searchPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */