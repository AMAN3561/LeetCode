class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;
        for(int i = 0; i < k; i++){
            lsum = lsum + cardPoints[i];
        }
        maxsum = lsum;

        int rindex = n-1;

        for(int i = k-1; i >= 0; i--){
            lsum = lsum - cardPoints[i]; // subracting the lsum.
            rsum = rsum + cardPoints[rindex]; // adding rsum.
            rindex = rindex - 1; // reducing the size of rindex.
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
    }
}; 



// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n= cardPoints.size();
//         int lsum=0;
//         int rsum=0;
//         int maxsum=0;
//         for(int i=0;i<k; i++){
//             lsum= lsum + cardPoints[i];
//         }
//         maxsum= lsum;

//         int rindex=n-1;
        
//         for(int i=k-1; i>=0; i--){
//             lsum= lsum-cardPoints[i];
//             rsum= rsum +cardPoints[rindex];
//             rindex= rindex-1;
//             maxsum=max(maxsum,lsum+rsum);
//         }
//         return maxsum;
//     }
// }; 