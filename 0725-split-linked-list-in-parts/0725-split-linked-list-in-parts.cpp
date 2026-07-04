class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0; // total no of nodes 
        ListNode* curr = head;
        while(curr){
            length++;
            curr = curr->next;
        }
        // determine size of each part 
        int partSize = length/k;
        int extranodes = length % k; // divide part by part 
        vector<ListNode*> ans(k, nullptr);
        curr = head;
        for(int i = 0; i < k && (curr != NULL); i++){
            ans[i] = curr;
            int currentPartSize = partSize + (extranodes > 0 ? 1 : 0);
            extranodes--;
            for(int j = 0; j < currentPartSize -1; j++)
                curr = curr->next;
            ListNode* nextPartHead = curr->next;
            curr->next = nullptr;
            curr = nextPartHead;
        }
        return ans;
    }
};