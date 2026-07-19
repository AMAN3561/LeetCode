class Solution {
public:
    int maxArea(vector<int>& height) {
        int  minheight = 0;
        int maxarea = 0;
        int i = 0;
        int j = height.size()- 1;
        while(i <= j){
            minheight = min(height[i], height[j]);
            int area = minheight * (j - i);
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