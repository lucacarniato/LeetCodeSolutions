class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        std::stack<std::tuple<int, int>> s;
        vector<int> results(temperatures.size(), 0);
        for(int i=0; i < temperatures.size() ;++i)
        {
            int new_temp = temperatures[i];
            if(s.empty())
            {
                s.push({new_temp, i});
                continue;
            }

            while(!s.empty())
            {
                const auto [old_temp, old_i] = s.top();
                if (new_temp <= old_temp) break; 
                results[old_i] = i - old_i;
                s.pop();
            }
            s.push({new_temp, i});
        }

        return results;

        
    }
};