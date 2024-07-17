using namespace std;

class Solution287
{
public:
    int findDuplicate(vector<int>& nums)
    {
        // get the max element and count the bits
        int max_bits = 17;
        int n = nums.size() - 1;
        int duplicate = 0;
        for (int i = 0; i < max_bits; ++i)
        {
            int mask = 1 << i;

            int nums_base = 0;
            for (int j = 0; j <= n; ++j)
            {
                if (j & mask)
                {
                    nums_base++;
                }
            }

            int nums_count = 0;
            for (const auto& v : nums)
            {
                if (v & mask)
                {
                    nums_count++;
                }
            }

            if (nums_count > nums_base)
            {
                duplicate |= mask;
            }
        }
        return duplicate;
    }
};

class Solution287Second 
{
public:
    
    int findDuplicate(vector<int>& nums) 
    {
        std::vector<bool> isFound(nums.size() - 1, false);
        for(int i=0; i<nums.size() ;++i)
        {
            const auto val = nums[i];
            if(isFound[val])
            {
                return val;
            }
            isFound[val] = true;

        }
        return -1;

        
    }
        
};
