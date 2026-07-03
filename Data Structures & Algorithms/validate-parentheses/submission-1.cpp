class Solution {
public:
    bool isValid(string s) {
        // using stack;
        stack<char> st;
        //using hashmap to store
        unordered_map<char, char> matching= {
            {')','('},
            {'}','{'},
            {']','['}
        };
        // pushing all the opening bracket onto the stack
        for(char c : s){
            if(matching.count(c)){
                if(st.empty()||st.top()!=matching[c]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        // if closing bracket, check if the top of the stack matches
        // if match, pop open bracket
        // else false
        return st.empty();
    }
};
