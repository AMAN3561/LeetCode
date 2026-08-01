class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int MaxScore = 0;
        while(pq.size() > 1){
            int pile1 = pq.top();
            pq.pop();
            int pile2 = pq.top();
            pq.pop();
            pile1--;
            pile2--;
            MaxScore++;
            if(pile1 > 0){
                pq.push(pile1);
            }
            if(pile2 > 0){
                pq.push(pile2);
            }
        }
        return MaxScore;
    }
};