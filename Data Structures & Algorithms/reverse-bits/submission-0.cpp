class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++) {
            int j = 31 - i;
            int l = n & (1 << i);
            int h = n & (1 << j);
            if (l) {
                n |= (1 << j);
            } else {
                n &= ~(1 << j);
            }

            if (h) {
                n |= (1 << i);
            } else {
                n &= ~(1 << i);
            }
        }
        return n;
    }
};
