class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 < len2){
            return "";
        }
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;
        int ansidx = -1;
        int ansleng = INT_MAX;
        for(auto it: t){
            tmp[it]++;
        }
        int strt = 0;
        int end = 0;
        int count = 0;
        while(end < len1){
            char ch = s[end];
            // update s in map kyoki smp 's' wali string ki window krne ke liye banaye hai.
            smp[ch]++;

            // possibility hai ye character t string ke aandaar ho ya fir na ho 
            // agar ye character t string mai bhe h, toh isko matched characters k aandar count krna padega.
            if(smp[ch] <= tmp[ch]){
                count++;
            }
            // aab ye bhi ho sakta hia ke count i.e total no of matched characters exactly len2 i.e length of string t ke equal aajaye.
            // iska matlb ek aisi window milgyi hai jisme t ke saare character present h.
            if(count == len2){
                // window which has answer 
                // minimise the window(shrink).
                while(smp[s[strt]] > tmp[s[strt]]){
                    smp[s[strt]]--;
                    strt++;
                }
                int windowleng = end - strt + 1;
                if(windowleng < ansleng){
                    ansleng = windowleng;
                    ansidx = strt;
                } 
            }
            // jaab ek valid answer nhi mila toh haam window ko expand karenge
            end++;
        }
        return ansidx == -1 ? "" : s.substr(ansidx, ansleng);
    }
};