class Solution {
public:
    vector<string> ans;
    int m, n;
    // step 1:
    // node struct for trie:
    struct trieNode{
        bool end_of_word;
        string word;
        trieNode* children[26];
    };
    // step 2:
    // get trie Node :
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->end_of_word = false;
        newNode->word = "";
        for(int i = 0; i<26; i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }
    // step 3:
    void insert(trieNode* root, string& word){
        trieNode* Crawler = root;
        // check for each character of word :
        for(int i = 0; i<word.length(); i++){
            char ch = word[i];

            if(Crawler->children[ch - 'a'] == nullptr){
                Crawler->children[ch - 'a'] = getNode();
            }
            Crawler = Crawler->children[ch - 'a'];
        }
        Crawler->end_of_word = true;
        Crawler->word = word;
    }
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0, -1}};
    // step 5:
    void find_Words(vector<vector<char>>& board, int i, int j, trieNode* root){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return; 
        }
        if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr){
            return;
        } 
        root = root->children[board[i][j] - 'a'];
        if(root->end_of_word == true){
            ans.push_back(root->word);
            root->end_of_word = false;
        }
        char temp = board[i][j];
        board[i][j] = '$'; // marking visited.

        // left, right, up, down.
        for(vector<int>&dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            find_Words(board, new_i, new_j, root);
        }
        board[i][j] = temp; // marking unvisited.
    }
    // step 4:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        // create root:
        trieNode* root = getNode();

        // insert words in trie :
        for(string& word : words){
            insert(root, word);
        }

        // traverse in the grid(just once) and find alll the words in the trie if present :
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                char ch = board[i][j];

                if(root->children[ch - 'a'] != nullptr){
                    find_Words(board, i, j, root);
                }
            }
        }
        return ans;
    }
};