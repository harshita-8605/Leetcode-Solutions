class Solution {
public:
    double distance(int x, int y){
        int powerSum = pow(x,2) + pow(y,2);
        return sqrt(powerSum);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, int>> pq;

        for(int i=0; i<points.size(); i++){
            double dist = distance(points[i][0], points[i][1]);
            pq.push({dist, i});
        }

        while(pq.size()>k){
                pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};