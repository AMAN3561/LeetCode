class Solution {
public:
    int compress(vector<char>& s) {
        int idx = 0;
        int count = 1;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                count++;
            } else {
                s[idx++] = prev;
                if (count > 1) {
                    int start = idx;
                    while (count) {
                        s[idx++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(s.begin() + start, s.begin() + idx);
                }
                prev = s[i];
                count = 1;
            }
        }
        s[idx++] = prev;
        if (count > 1) {
            int start = idx;
            while (count) {
                s[idx++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(s.begin() + start, s.begin() + idx);
        }
        return idx;
    }
};