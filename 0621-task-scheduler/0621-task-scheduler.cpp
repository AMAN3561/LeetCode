class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto task : tasks) {
            freq[task]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> maxheap;

        for (auto each : freq) {
            maxheap.push({each.second, each.first});
        }

        int ans = 0;
        while (!maxheap.empty()) {
            int cycle = n + 1;
            vector<pair<int, char>> temp;
            while (cycle > 0 && !maxheap.empty()) {
                auto [freq, task] = maxheap.top();
                maxheap.pop();
                freq--;
                ans++;
                cycle--;

                // pushiing remaning task :
                temp.push_back({freq, task});
            }
            for (auto leftouttask : temp) {
                if(leftouttask.first > 0){
                    maxheap.push(leftouttask);
                }
            }
            if (!maxheap.empty()) {
                ans += cycle;
            }
        }
        return ans;
    }
};