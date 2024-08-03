#include <string>

using namespace std;

class Solution139
{
    struct TrieNode
    {
        explicit TrieNode()
        {
            childrens_.resize(alphabetSize);
            for (auto i = 0; i < alphabetSize; ++i)
            {
                childrens_[i] = nullptr;
            }
        }

        std::vector<TrieNode*> childrens_;
        bool isWordEnd_ = false;

        static void insert(TrieNode* root, const std::string& key)
        {
            auto p = root;

            for (int i = 0; i < key.size(); ++i)
            {
                const int index = key[i] - 'a';
                if (p->childrens_[index] == nullptr)
                {
                    p->childrens_[index] = new TrieNode();
                }

                p = p->childrens_[index];
            }

            p->isWordEnd_ = true;
        }
    };

    bool searchWord(const TrieNode* root, const std::string& s, int index)
    {

        if (failed_[index])
        {
            return false;
        }
        if (index >= s.size())
        {
            return true;
        }

        auto p1 = root;
        for (auto i = index; i < s.size(); ++i)
        {
            const int ind = s[i] - 'a';

            if (p1->childrens_[ind] == nullptr)
            {
                return false;
            }

            p1 = p1->childrens_[ind];
            if (p1->isWordEnd_)
            {
                auto const res = searchWord(root, s, i + 1);
                if (res)
                {
                    return true;
                }
                failed_[i + 1] = true;
            }
        }

        return false;
    }

    std::vector<bool> failed_;
    static int constexpr alphabetSize{26};

public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto root = new TrieNode();

        // Construct trie
        for (int i = 0; i < wordDict.size(); i++)
        {
            root->insert(root, wordDict[i]);
        }

        //
        failed_.resize(s.size() + 1, false);
        auto const res = searchWord(root, s, 0);
        return res;
    }
};
