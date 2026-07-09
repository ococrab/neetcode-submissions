class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        for(int i = 0; i<n; i++){
            int curr = temperatures[i];
            while(!st.empty() && curr > st.top().first){
                auto[prevTemp, prevIdx] = st.top();
                st.pop();
                res[prevIdx] = i - prevIdx;
            }
            st.push({curr, i});
        }
        return res;
    }
};
