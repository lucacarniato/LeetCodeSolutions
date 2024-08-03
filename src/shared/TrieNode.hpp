#pragma once
struct TrieNode
{
    TrieNode()
    {
        childrens_.resize(alphabetSize);
        for (auto i = 0; i < alphabetSize; ++i)
        {
            childrens_[i] = nullptr;
        }
    }

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

    std::vector<TrieNode*> childrens_;
    bool isWordEnd_ = false;
    static int constexpr alphabetSize{26};
};
