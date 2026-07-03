class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> Mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int prefixSum = 0;
        while (curr != nullptr) {
            prefixSum += curr->val;
            if (Mp.count(prefixSum)) {
                ListNode* prev = Mp[prefixSum]->next;
                int sum = prefixSum;
                while (prev != curr) {
                    sum += prev->val;
                    Mp.erase(sum);
                    prev = prev->next;
                }
                Mp[prefixSum]->next = curr->next;
            } else {
                Mp[prefixSum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};






// class Solution {
// public:
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         int prefixsum = 0;
//         unordered_map<int, ListNode*> mp;
//         ListNode* dummynode = new ListNode(0);
//         dummynode->next = head;
//         mp[0] = dummynode;
//         while(head != NULL){
//             prefixsum += head->val;
//             if(mp.find(prefixsum) != mp.end()){
//                 // delete wala operation idhar hoga :
//                 ListNode* start = mp[prefixsum];
//                 ListNode* temp = start;
//                 int psum = prefixsum;
//                 while(temp != head){
//                     temp = temp->next;
//                     psum += temp->val;
//                     if(temp != head) mp.erase(psum);
//                 }
//                 start->next = temp->next;
//             }
//             else{
//                 mp[prefixsum] = head;
//             }
//             head = head->next;
//         }
//         return dummynode->next;
//     }
// };