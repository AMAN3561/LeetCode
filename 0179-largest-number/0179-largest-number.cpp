class Solution {
    class compare{
    public:
        bool operator()(int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        sort(nums.begin(), nums.end(), compare());
        for(int i = 0; i<nums.size(); i++){
            s += to_string(nums[i]);
        }
        if(nums[0] == 0){
            return "0";
        }
        return s;
    }
};