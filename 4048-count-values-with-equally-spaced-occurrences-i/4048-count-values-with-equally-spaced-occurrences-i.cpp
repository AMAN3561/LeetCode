class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> index(101);
        for(int i = 0; i< nums.size(); i++){
            index[nums[i]].push_back(i);
        }
        int count = 0;
        for(int i = 1; i<=100; i++){
            if(index[i].size() == 3){
                if(index[i][1] - index[i][0] == index[i][2] - index[i][1]){
                    count++;
                }
            }
        }
        return count;
    }
};