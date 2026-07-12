class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (auto i : nums) {
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end(),
             [](const string& a, const string& b) { return a + b > b + a; });
        string res = "";
        if (s[0] == "0")
            return "0";
        for (auto i : s) {
            res += i;
        }
        return res;
    }
};