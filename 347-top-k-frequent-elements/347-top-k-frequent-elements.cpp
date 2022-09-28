class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto i = mp.begin() ; i != mp.end() ; i++) {
            pq.push({i->second, i->first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};

/*
mp
1->3
2->2
3->1

pq
3, 1
2, 2

*/