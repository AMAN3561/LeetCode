class Info{
    public:
        int data;
        int rindex;
        int cindex;
        Info(int a, int b, int c){
            this->data = a;
            this->rindex = b;
            this->cindex = c;
        }
};
class compare{
    public:
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;
        // process the first k elements 
        int totalrows = nums.size();
        int totalcols = nums[0].size();

        for(int row = 0; row<totalrows; row++){
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ans_strt = mini;
        int ans_end = maxi;

        // main logic: 
        while(!pq.empty()){
            // front element nikalo :
            Info* front = pq.top();
            pq.pop();

            int frontdata = front->data;
            int front_rindex = front->rindex;
            int front_cindex = front->cindex;

            mini = frontdata;
            // ans update :

            if((maxi - mini) < (ans_end - ans_strt)){
                ans_strt = mini;
                ans_end = maxi;
            }
            // aage element hai toh insert karo 
            int currTotalcols = nums[front_rindex].size();
            if(front_cindex + 1 < currTotalcols){
                int element = nums[front_rindex][front_cindex + 1];

                Info* temp = new Info(element, front_rindex, front_cindex + 1);
                maxi = max(maxi, element);
                pq.push(temp);
            }
            else{
                break;
            }
        }
        ans.push_back(ans_strt);
        ans.push_back(ans_end);
        return ans;
    }
};