class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;int index=1;for(int i=0;i<nums.size()-1;i++)if(nums[i]!=nums[i+1])nums[index++]=nums[i+1];return index;
    }
};