class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return 0;
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for (auto x: cnt) {
            if (x != 0) return 0;
        }
        return 1;
    }
};
