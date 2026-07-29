/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Info{ // no need of this 
//     public:
//         int data;
//         int rowindex;

//         Info(int LLvalue, int rowvalue){
//             this->data = LLvalue;
//             this->rindex = rowvalue;
//         }
// }
class Compare {
public:
    bool operator()(ListNode* LLvalue, ListNode* rowvalue) {
        return LLvalue->val > rowvalue->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* headNode = nullptr;
        ListNode* tailNode = nullptr;
        // process the first k elements :
        // haar list ka phle element pq mai insert krna hai.
        int totalrows = lists.size();
        for(int row = 0; row < totalrows; row++){
            ListNode* temp = lists[row];
            if(temp != nullptr){
                // if it is aa valid node :
                pq.push(temp);
            }
        }

        // main logic :
        while(!pq.empty()){
            // front nikalo :
            ListNode* front = pq.top();
            pq.pop();
            // answer main insert karo :
            if(headNode == nullptr && tailNode == nullptr){
                headNode = front;
                tailNode = front;
            }
            else{
                // it means its not the first node :
                tailNode->next = front;
                tailNode = front;
            }
            if(tailNode->next != nullptr){
                pq.push(tailNode->next);
            }
        }
        return headNode;
    }
};