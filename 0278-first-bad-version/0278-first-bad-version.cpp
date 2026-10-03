// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int bad_version = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            
            bool result = isBadVersion(mid);
            if(result){
                bad_version = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return bad_version;
    }
};