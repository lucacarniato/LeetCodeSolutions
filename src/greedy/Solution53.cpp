class Solution53 {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currentSum= 0;
        int result = -1000000;
        for(int i=0; i <nums.size() ;++i)
        {
            currentSum = currentSum + nums[i];
            result = std::max(result, currentSum);
            currentSum = std::max(currentSum, 0);
        }
        
        return result;
    }
};