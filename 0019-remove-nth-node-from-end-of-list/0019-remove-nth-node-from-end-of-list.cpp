class Solution {
public:
    void reverseLL(ListNode* &head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        head = prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        reverseLL(head);
        if(n == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            reverseLL(head);
            return head;
        }
        ListNode* prev = head;
        for(int i = 1; i<n-1; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        prev->next = curr->next;
        curr->next = nullptr;
        reverseLL(head);
        return head;
    }
};