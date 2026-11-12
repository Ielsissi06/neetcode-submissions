class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, int>> distances;
        
        for (int i = 0; i < points.size(); i++) {
            pair<long long, int> dist;
            dist.first = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dist.second = i;
            distances.push_back(dist);
        }

        sort(distances.begin(), distances.end());
        vector<vector<int>> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(points[distances[i].second]);
        }

        return ret;
    }
};
