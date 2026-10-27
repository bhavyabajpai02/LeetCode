class Solution {
public:
    string clearStars(string s) {
        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            if (a.first != b.first)
                return a.first > b.first; 
            return a.second < b.second;   
        };

        priority_queue<pair<char, int>,vector<pair<char, int>>,decltype(cmp)> pq(cmp);
        vector<bool> removed(s.size(), false);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                if (!pq.empty()) {
                    removed[pq.top().second] = true;
                    pq.pop();
                }
                removed[i] = true;
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (!removed[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};