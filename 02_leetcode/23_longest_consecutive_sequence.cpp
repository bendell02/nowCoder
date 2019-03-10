class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if (length <= 0) {
            return 0;
        }

        vector<int> consecutiveFlags(length, 1);
        int longest = consecutiveFlags[0];
        for(int i=1; i<length; i++) {
            if (nums[i] == (nums[i-1]+1)) {
                consecutiveFlags[i] = consecutiveFlags[i-1] + 1;
            }
            else if (nums[i] == nums[i-1]) {
                consecutiveFlags[i] = consecutiveFlags[i-1];
            }
            longest = std::max(longest, consecutiveFlags[i]);
        }

        return longest;
    }
};