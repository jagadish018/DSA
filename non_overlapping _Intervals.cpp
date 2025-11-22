class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> p;
        for (auto &it : intervals) {
            p.push_back({it[0], it[1]});
        }

        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int count = 0;
        int lastEnd = p[0].second;

        for (int i = 1; i < p.size(); i++) {
            if (p[i].first < lastEnd) {
              
                count++;
            } else {
            
                lastEnd = p[i].second;
            }
        }

        return count;
    }
};
