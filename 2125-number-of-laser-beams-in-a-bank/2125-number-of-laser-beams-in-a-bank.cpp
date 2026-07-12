class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int previousDevicecount = 0;
        int result = 0;
        for(int i = 0; i<n; i++){
            int currentDeviceCount = 0;
            for(char &ch : bank[i]){
                if(ch == '1'){
                    currentDeviceCount++;
                }
            }
            result += (currentDeviceCount * previousDevicecount);
            if(currentDeviceCount != 0){
                previousDevicecount = currentDeviceCount;
            }
        }
        return result;
    }
};