class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int freq[26] = {0};
        int first_pointer = 0;
        int n = answerKey.size();
        long long  maxConsecutive = 0;
        long long maxfreq = 0;

        for(int second_pointer = 0; second_pointer<n; second_pointer++){
            freq[answerKey[second_pointer] - 'A']++;

            maxfreq = max(maxfreq, (long long)freq[answerKey[second_pointer] - 'A']);
            long long windowlength = second_pointer - first_pointer + 1;

            if(windowlength - maxfreq > k){
                freq[answerKey[first_pointer] - 'A']--;
                first_pointer++;
            }

            windowlength = second_pointer - first_pointer + 1;
            maxConsecutive = max(maxConsecutive, windowlength);
        }
        return maxConsecutive;
    }
};