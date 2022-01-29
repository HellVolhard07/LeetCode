class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;
        for(int i = 0 ; i < heights.size() ; i++) {
            int startIndex = i;
            while(!stack.empty() and stack.top().second > heights[i]) {
                int index = stack.top().first;
                int height = stack.top().second;
                stack.pop();
                maxArea = max(maxArea, height * (i - index));
                startIndex = index;
            }
            stack.push(make_pair(startIndex, heights[i]));
        }
        while(!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * ((int)heights.size() - index));
            stack.pop();
        }
        return maxArea;
    }
};