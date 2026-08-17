class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Step 1: Find potential candidates
        for(int val : nums) {

            if(count1 == 0 && val != candidate2) {
                candidate1 = val;
                count1++;
            }
            else if(count2 == 0 && val != candidate1) {
                candidate2 = val;
                count2++;
            }
            else if(val == candidate1) {
                count1++;
            }
            else if(val == candidate2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for(int val : nums) {
            if(val == candidate1) {
                count1++;
            }
            else if(val == candidate2) {
                count2++;
            }
        }

        // Step 3: Store valid answers
        vector<int> ans;

        if(count1 > n / 3) {
            ans.push_back(candidate1);
        }

        if(count2 > n / 3) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};