class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int l = 0;
        int r = 0;
        int minleng = INT_MAX;
        int count = 0;
        int sidx = -1;
        int hash[256] = {0};
        for(int i = 0; i<n; i++){
            hash[t[i]]++;
        }
        while(r<m){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            
            while(count == n){
                if(r-l+1 < minleng){
                    minleng = r-l+1;
                    sidx = l;
                }
                hash[s[l]]++;

                if(hash[s[l]] > 0){
                    count--;
                }
                l++;   
            }
            r++;
        }
        return sidx == -1 ? "" : s.substr(sidx, minleng);
    }
};