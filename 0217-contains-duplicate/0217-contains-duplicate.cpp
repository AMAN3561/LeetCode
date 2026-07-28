class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // if(nums.size()== 1){
        //         return false;
        //     }
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size()-1; i++){
        //     //int j= i+1;
        //     if(nums[i]== nums[i+1]){
        //         return true;
        //     }
        // }
        // return false;
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            else{
                s.insert(nums[i]);
            }
        }
        return false;
    }
};