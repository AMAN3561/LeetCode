class Solution {
public:
    void computeLPS(vector<int>& pat, vector<int>& LPS, int m){
        int leng = 0; // length of previous longest prefix and suffix which were equal.
        LPS[0] = 0;
        
        int i = 1;
        while(i < m){
            if(pat[i] == pat[leng]){
                leng++;
                LPS[i] = leng;
                i++;
            }
            else{
                if(leng != 0){
                    leng = LPS[leng - 1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    bool KMP_Search(vector<int> &pat, vector<int> &txt) {
        int n = txt.size();
        int m = pat.size();
        
        vector<int> result;
        
        // LPS array:
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS, m);
        
        int i = 0;
        int j = 0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == m){ // pattern found.
                return true;
                // result.push_back(i - m);
                // j = LPS[j - 1];
            }
            else if(i < n && txt[i] != pat[j]){
                if(j != 0){
                    j = LPS[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return false; // result;
    }
    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2){
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());

        return KMP_Search(vec1, text);
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;
        for(int k = 1; k<= n; k++){
            if(n % k != 0){
                continue;
            }
            bool valid = true;
            for(int start = 0; start<n; start += k){ // check k block size.
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);

                if(!isRotationPossible(vec1, vec2)){
                    valid = false;
                    break;
                }
            }
            if(valid){
                result += k;
            }
        }
        return result;
    }
};