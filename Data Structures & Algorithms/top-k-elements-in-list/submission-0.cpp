class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> cnt(2001, 0);
        for (auto x: nums) {
            cnt[x+1000]++;
        }
        auto cmp = [&cnt](int a, int b) {
            return cnt[a] > cnt[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < 2001; i++) {
            if (pq.size() < k) pq.push(i);
            else  {
                int x = pq.top();
                if (cnt[i] > cnt[x]) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }

        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = pq.top() - 1000;
            pq.pop();
        }

        return res;
    }
};
