class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0; 
        
        for (int i = n - 2; i >= 0; --i) {
            while (nums[i] > nums[i + 1]) {
     
                int divisor = 1;
                for (int j = 2; j * j <= nums[i]; ++j) {
                    if (nums[i] % j == 0) {
                        divisor = max(divisor, max(j, nums[i] / j));
                    }
                }

                if (divisor == 1) return -1;  
                
                nums[i] /= divisor; 
                operations++;

                if (nums[i] <= nums[i + 1]) break;
            }
        }

        return operations;
    }
};
