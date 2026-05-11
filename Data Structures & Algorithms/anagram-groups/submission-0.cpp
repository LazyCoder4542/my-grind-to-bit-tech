class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        auto fn = [](string &s) -> string {
            vector<int> cnt(26, 0);
            for (int i = 0; i < s.size(); i++) {
                cnt[s[i]-'a']++;
            }
            string t;
            for (auto x: cnt) {
                for (int i = 0; i < 3; i++) {
                    t += '0' + (x % 10);
                    x /= 10;
                }
            }
            return t;
        };
        for (auto &s: strs) {
            mp[fn(s)].push_back(s);
        }
        for (auto &kv: mp) {
            res.push_back(kv.second);
        }
        return res;
    }
};
