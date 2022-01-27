class node {
    public:
    node* left;
    node* right;
};

void insert(int x, node* head) {
    node* current = head;
    for(int i = 30 ; i >= 0 ; i--) {
        int value = (x >> i) & 1;
        if(value == 0) {
            if(!current->left) {
                current->left = new node();
            }
            current = current->left;
        }
        else {
            if(!current->right) {
                current->right = new node();
            }
            current = current->right;
        }
    }
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        node* head = new node();
        for(int i = 0 ; i < nums.size() ; i++) {
            insert(nums[i], head);
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            int currentXor = 0;
            int m = pow(2, 30);
            node* current = head;
            for(int j = 30 ; j >= 0 ; j--) {
                int value = (nums[i] >> j) & 1;
                if(value == 0) {
                    if(current->right) {
                        currentXor += m;
                        current = current->right;
                    }
                    else{
                        current = current->left;
                    }
                }
                else{
                    if(current->left) {
                        currentXor += m;
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
                m /= 2;
            }
            ans = max(ans, currentXor);
        }
        return ans;
    }
};