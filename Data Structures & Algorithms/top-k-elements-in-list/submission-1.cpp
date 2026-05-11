class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> cnt(2001, 0);
        vector<vector<int>> bucket(10001);
        for (auto x: nums) {
            cnt[x+1000]++;
        }
        for (int i = 0; i < 2001; i++) {
            bucket[cnt[i]].push_back(i-1000);
        }
        vector<int> res(k);
        int i = 0;
        for (int j = 10000; j >= 1; j--) {
            for (auto x: bucket[j]) {
                res[i] = x;
                i++;
                if (i == k) break;
            }
            if (i == k) break;
        }
        return res;
    }
};
