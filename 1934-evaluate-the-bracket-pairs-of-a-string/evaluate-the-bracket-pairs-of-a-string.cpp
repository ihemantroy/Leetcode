class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (auto& k : knowledge) map[k[0]] = k[1];

        string ans, key;
        bool inside = false;

        for (char c : s) {
            if (c == '(') { inside = true; key = ""; }
            else if (c == ')') {
                inside = false;
                ans += map.count(key) ? map[key] : "?";
            }
            else if (inside) key += c;
            else ans += c;
        }
        return ans;
    }
};