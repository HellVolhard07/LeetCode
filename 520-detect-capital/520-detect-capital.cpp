class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1) {
            return true;
        }
        int lower = 0;
        if(isupper(word[0])) {
            for(int i = 1 ; i < word.length() ; i++) {
                if(islower(word[i])) {
                    lower++;
                }
            }
            if(lower == word.length() - 1 or lower == 0) {
                return true;
            }
        }
        else{
            for(int i = 0 ; i < word.length() ; i++) {
                if(islower(word[i])) {
                    lower++;
                }
            }
            if(lower == word.length()) {
                return true;
            }
        }
        return false;
    }
};