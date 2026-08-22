class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int k, int v){
                this->key = k;
                this->val = v;
                prev = next = nullptr;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;
    void addNode(Node* newNode){
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        Node* oldprev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldprev->next = oldNext;
        oldNext->prev = oldprev;

    }
    
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* ansNode = mp[key];
        int ans = ansNode->val;

        mp.erase(key);
        deleteNode(ansNode);
        
        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
        }
        if(mp.size() == limit){
            // delete LRU data :
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */