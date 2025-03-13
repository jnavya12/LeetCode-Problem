class Solution { 
public:     
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {         
        int n = nums.size(), left = 0, right = queries.size();          
        if (!canFormZeroArray(nums, queries, right)) return -1;          
        while (left <= right) {             
            int middle = left + (right - left) / 2;             
            if (canFormZeroArray(nums, queries, middle)) right = middle - 1;
            else left = middle + 1;             
        }          
        return left;     
    }  

private:     
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {         
        int n = nums.size(), sum = 0;         
        vector<int> diff(n + 1);          
        for (int i = 0; i < k; i++) {             
            diff[queries[i][0]] += queries[i][2];             
            diff[queries[i][1] + 1] -= queries[i][2];         
        }          
        for (int i = 0; i < n; i++) {             
            sum += diff[i];             
            if (sum < nums[i]) return false;         
        }         
        return true;     
    } 
};
