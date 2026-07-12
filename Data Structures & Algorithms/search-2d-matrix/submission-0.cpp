class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bot = rows-1;
        while(top<=bot){
            int row = top+(bot-top)/2;
            if(target>matrix[row][cols-1]){
                top = row+1;
            }
            else if(target < matrix[row][0]){
                bot = row - 1;
            }
            else{
                break;
            }
        }
        if(top>bot) return false;
        int row = top +(bot-top)/2;
        int left = 0, right = cols-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};
