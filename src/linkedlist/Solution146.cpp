#include "../shared/ListNode.hpp"

using namespace std;

class LRUCache
{

    std::unordered_map<int, pair<int, list<int>::iterator>> cache_;
    std::list<int> access_order_;
    int capacity_;

public:
    LRUCache(int capacity) : capacity_(capacity)
    {
    }

    int get(int key)
    {
        if (!cache_.contains(key))
        {
            return -1;
        }
        access_order_.erase(cache_[key].second);
        access_order_.push_back(key);
        cache_[key].second = --access_order_.end();
        return cache_[key].first;
    }

    void put(int key, int value)
    {
        if (cache_.contains(key))
        {
            access_order_.erase(cache_[key].second);
        }

        else if (cache_.size() == capacity_)
        {
            auto lru = access_order_.front();
            access_order_.pop_front();
            cache_.erase(lru);
        }
        access_order_.push_back(key);
        cache_[key] = {value, --access_order_.end()};
    }
};
