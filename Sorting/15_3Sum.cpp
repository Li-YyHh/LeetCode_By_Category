class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            int n = nums.size();
            
            if (n < 3) return result;
    
            // 1. 快速排序，构建单调性
            sort(nums.begin(), nums.end());
    
            // 2. 遍历固定第一个数
            for (int i = 0; i < n - 2; ++i) {
                // 剪枝：如果最小的数已经大于0，不可能凑成0
                if (nums[i] > 0) break; 
                
                // 去重逻辑1：跳过第一个数的重复项
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                
                // 3. 定义双指针，在剩余区间内相向而行
                int left = i + 1;
                int right = n - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    
                    if (sum < 0) {
                        left++; // 和太小，左指针右移放大
                    } else if (sum > 0) {
                        right--; // 和太大，右指针左移缩小
                    } else {
                        // 找到有效解
                        result.push_back({nums[i], nums[left], nums[right]});
                        
                        // 去重逻辑2：跳过左指针的连续重复项
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 去重逻辑3：跳过右指针的连续重复项
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        // 找到一个解后，双指针同时向内收缩，继续寻找下一组
                        left++;
                        right--;
                    }
                }
            }
            return result;
        }
    };