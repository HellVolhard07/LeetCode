class Solution { 
private:
    
    bool areSame(vector<int> x, vector<int> y) {
        for(int i = 0 ; i < 26 ; i++) {
            if(x[i] != y[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> count(string s) {
        vector<int> frequency(26);
        for(int i = 0 ; i < s.length() ; i++) {
            frequency[s[i] - 'a']++;
        }
        return frequency;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        int large = s.length();
        int small = p.length();
        if(large < small) {
            return {};
        }
        vector<int> ans;
        vector<int> p_frequency = count(p);
        vector<int> s_frequency = count(s.substr(0, small));
        if(areSame(p_frequency, s_frequency)) {
            ans.push_back(0);
        }
        for(int i = small ; i < large ; i++) {
            s_frequency[s[i - small] - 'a']--;
            s_frequency[s[i] - 'a']++;
            if(areSame(p_frequency, s_frequency)) {
                ans.push_back(i - small + 1);
            }
        }
        return ans;
    }
};