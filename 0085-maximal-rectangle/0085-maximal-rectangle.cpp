class Solution {
public:
    // next vaale vector mai index ko store krenge value ko nhi 
    void nextsmallerelement(vector<int>& heights, vector<int>& nextans){
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        for(int i = n-1; i >= 0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            // aagar yaha taak paucha hu toh iska matlb 
            // ke ya toh koi chota number stack top pr h.
            // ya fir -1 stack top pr h 
            nextans.push_back(st.top());
            // current number ko toh stack mai push krna hee hai.
            st.push(i);
        }
    }

    void prevsmallerelement(vector<int>& heights, vector<int>& prevans){
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        for(int i = 0; i < n; i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            // aagar yaha taak paucha hu toh iska matlb 
            // ke ya toh koi chota number stack top pr h.
            // ya fir -1 stack top pr h 
            prevans.push_back(st.top());
            // current number ko toh stack mai push krna hee hai.
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextans;
        vector<int> prevans;
        nextsmallerelement(heights, nextans);
        reverse(nextans.begin(), nextans.end());
        // yeah main step hai width niklne ke liye :
        for(int i = 0; i < nextans.size(); i++){
            if(nextans[i] == -1){
                nextans[i] = nextans.size();
            }
        }
        prevsmallerelement(heights, prevans);

        int maxarea = INT_MIN;
        for(int i = 0; i<nextans.size(); i++){
            int width = nextans[i] - prevans[i] - 1;
            int height = heights[i];
            int currarea = width * height;
            maxarea = max(maxarea, currarea);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            vector<int> t;
            for(int j = 0; j<m; j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for(int i = 1; i< n; i++){
            for(int j = 0; j<m; j++){
                // let's update row with previous values.
                if(v[i][j]){
                    v[i][j]  += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};