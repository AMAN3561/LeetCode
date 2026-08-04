class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        // pushing the elements in the maxheap.
        for(auto stone : stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if(x != y){
                maxheap.push(x - y);
            }
        }
        if(maxheap.size() != 0){
            return maxheap.top();
        }
        else{
            return 0;
        }
    }
};