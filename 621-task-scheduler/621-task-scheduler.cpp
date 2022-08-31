class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for(auto i : tasks) {
            mp[i-'A']++;
        }
        sort(mp.begin(), mp.end());
        /*
        A _ _ A _ _ A
        */
        int maxTask = mp[25] - 1;
        int slots = maxTask * n;
        /*
        A B _ A B _ A B
        */
        for(int i = 24 ; i >= 0 ; i--) {
            slots -= min(mp[i], maxTask);
        }
        return slots > 0 ? tasks.size() + slots : tasks.size();
    }
};