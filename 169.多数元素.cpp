class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        for(std::vector<int>::iterator it=nums.begin()+1; it < nums.end(); ++it) {
            if(*it == major) {
                count++;
            } else {
                count--;
                if(count==0) {
                    count=1;
                    major = *it;
                }
            }
        }
        return major;
    }
};
