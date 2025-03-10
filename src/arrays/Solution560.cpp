#include <unordered_map>
#include <vector>

using namespace std;

class Solution560
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int sum = 0;
        unordered_map<int, int> ps;
        int result = 0;
        for (const auto& v : nums)
        {
            sum += v;
            if (sum == k)
            {
                result += 1;
            }
            result += ps[sum - k];
            ps[sum]++;
        }

        return result;
    }
};



class Solution560Second
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        // 1. do prefix sum
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // 2. use two pointer approach
        vector<int> nSubArray(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[0] == k)
            {
                nSubArray[i] = 1;
            }
        }

        for (int i = 1; i < prefixSum.size(); ++i)
        {
            if (prefixSum[i] == k)
            {
                nSubArray[i] = nSubArray[i - 1] + 1;
            }
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    const auto v = prefixSum[i] - prefixSum[j];
                    if (v == k)
                    {
                        nSubArray[i] = nSubArray[i -1] + 1;
                        break;
                    }
                }
            }
        }

        return nSubArray.back();
    }
};


class SolutionSecond {
public:
    int subarraySum(vector<int>& nums, int k) 
    {

        std::unordered_map<int,int> m;
        m[0] = 1;
        int current_sum = 0;
        int result = 0;
        for(int i=0; i < nums.size();++i)
        {
            current_sum += nums[i];
            int diff = current_sum - k;
            result +=  m[diff] ;
            m[current_sum] = 1 + m[current_sum];
        }
        return result;
        
    }
};
