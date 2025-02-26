class KthLargest 
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> maxScores_;
    int k_;

public:
    KthLargest(int k, vector<int>& nums) : k_(k)
    {
        for (int num : nums) {
            add(num);  // Ensure only k elements are in heap
        }
    }
    
    int add(int val) 
    {
        maxScores_.push(val);
        if (maxScores_.size() > k_) {
            maxScores_.pop();  // Remove the smallest element
        }
        return maxScores_.top(); // k-th largest element
    }
};