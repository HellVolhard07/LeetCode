inline int sum (int n) {
    return ((n * n) + n) / 2;
}
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> songs;
        for(int i = 0 ; i < time.size() ; i++) {
            time[i] = time[i] % 60;
            songs[time[i]]++;
        }
        int ans = 0;
        for(auto i = songs.begin() ; i != songs.end() ; i++) {
            int element = 60 - i->first;
            element %= 60;
            if(element == i->first or element == 0) {
                ans += sum(i->second - 1);
            }
            else {
                if(songs.count(element) > 0) {
                    ans += i->second * songs[element];
                    songs[element] = 0;
                }
            }
        }
        return ans;
    }
};