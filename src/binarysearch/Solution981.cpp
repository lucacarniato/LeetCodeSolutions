#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap981
{

    std::unordered_map<string, std::vector<int>> ts_;
    std::unordered_map<string, std::vector<string>> val_;

    int search(string& key, int v)
    {
        const auto& ts = ts_[key];
        int l = 0;
        int r = ts.size() - 1;
        int max_ind = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int midv = ts[mid];
            if (midv <= v)
            {
                max_ind = std::max(max_ind, mid);
            }
            if (midv > v)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return max_ind;
    }

public:
    TimeMap981()
    {
    }

    void set(string key, string value, int timestamp)
    {
        ts_[key].push_back(timestamp);
        val_[key].push_back(value);
    }

    string get(string key, int timestamp)
    {
        if (ts_.contains(key))
        {
            const auto index = search(key, timestamp);
            if (index == -1)
            {
                return "";
            }
            return val_[key][index];
        }
        return "";
    }
};
