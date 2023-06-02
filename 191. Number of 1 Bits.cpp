class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int r = n ? 1 : 0;
        while (n &= (n - 1)) ++ r;
        return r;
    }
};