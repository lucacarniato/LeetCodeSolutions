

class MergeSort
{
    void merge(std::vector<int>& v, int l, int m, int r)
    {
        int size_left = m - l + 1;
        int size_right = r - m;
        std::vector<int> vl(size_left);
        std::vector<int> vr(size_right);
        for (int i = 0; i < size_left; ++i)
        {
            vl[i] = v[l + i];
        }
        for (int i = 0; i < size_right; ++i)
        {
            vr[i] = v[m + 1 + i];
        }

        int left_index = 0;
        int right_index = 0;
        int k = l;
        while (left_index < size_left && right_index < size_right)
        {
            if (vl[left_index] <= vr[right_index])
            {
                v[k] = vl[left_index];
                left_index++;
            }
            else
            {
                v[k] = vr[right_index];
                right_index++;
            }
            k++;
        }

        while (left_index < size_left)
        {
            v[k] = vl[left_index];
            left_index++;
            k++;
        }

        while (right_index < size_right)
        {
            v[k] = vr[right_index];
            right_index++;
            k++;
        }
    }
    void sort(std::vector<int>& v, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            sort(v, l, m);
            sort(v, m + 1, r);
            merge(v, l, m, r);
        }
    }

public:
    void sort(std::vector<int>& v)
    {
        sort(v, 0, v.size() - 1);
    }
};
