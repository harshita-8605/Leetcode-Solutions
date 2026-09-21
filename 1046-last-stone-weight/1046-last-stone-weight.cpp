class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        int ans = 0;

        while(pq.size() >=0){
            if(pq.empty()){
                return 0;
            }
            int stone1 = pq.top(); // y
            pq.pop();
            if(pq.empty()){
                return stone1;
            }
            int stone2 = pq.top(); // x
            pq.pop();
            if(stone1 != stone2){
                pq.push(stone1 - stone2);
            }
        }
        return ans;

    }
};