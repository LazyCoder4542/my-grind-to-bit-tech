class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (auto &ss: strs) {
            s += to_string(ss.size()) + '#' + ss;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = 0;
        string ss;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '#') {
                i++;
                while (n--) {
                    ss += s[i];
                    i++;
                }
                res.push_back(ss);
                n = 0; ss = "";
                continue;
            }
            n *= 10;
            n += s[i] - '0';
            i++;
        }
        return res;
    }
};
