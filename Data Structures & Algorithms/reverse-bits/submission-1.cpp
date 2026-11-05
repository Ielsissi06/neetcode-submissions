class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t bit;

        for (int i = 0; i < 32; i++) {
            bit = (n >> i) & 1;
            ret += (bit << (31 - i));
        }

        return ret;
    }
};
