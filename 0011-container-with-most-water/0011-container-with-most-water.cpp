class Solution {
public:
    int maxArea(vector<int>& height) {
        long long minheight = 0;
        long long maxarea = 0;
        int i = 0;
        int j = height.size()- 1;
        while(i <= j){
            minheight = min(height[i], height[j]);
            long long area = minheight * (j - i);
            maxarea = max(maxarea, area);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
            
        }
        return maxarea;
    }
};