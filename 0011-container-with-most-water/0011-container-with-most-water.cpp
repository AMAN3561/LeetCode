class Solution {
public:
    int maxArea(vector<int>& height) {
        long long minheight = 0;
        long long width = 0;
        long long maxarea = 0;
        int i = 0;
        long long area = 0;
        int j = height.size()- 1;
        while(i <= j){
            minheight = min(height[i], height[j]);
            width = j - i;
            area = minheight * width;
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