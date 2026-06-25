class Solution {
public:
    bool binSearch(vector<int>& mx, int si, int ei, int target) {
        if (si > ei) return false;
        int mid = si + (ei-si)/2;
        if (mx[mid] == target) return true;

        if (target < mx[mid]) return binSearch(mx,si,mid-1,target);
        else return binSearch(mx,mid+1,ei,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> mx;
        for (auto &vec : matrix) {
            for (int num : vec) mx.emplace_back(num);
        }
        return binSearch(mx,0,mx.size()-1,target);
    }
};