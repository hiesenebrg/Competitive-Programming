// XOR -> 1 if both digit same, 0 if both digits differnet 
// 5 -> 101
// 4->  100
//5^4 ->001
#include <vector>
using namespace std;

vector<int> findRepeatingAndMissingNumbers(vector<int> nums) {
    int n = nums.size();
    int xor_all = 0;

    // Step 1: XOR all elements and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor_all ^= nums[i];      // XOR array elements
        xor_all ^= (i + 1);      // XOR numbers from 1 to n
    }

    // Step 2: Find rightmost set bit (differs between missing and repeating)
    int rightmost_set_bit = xor_all & ~(xor_all - 1);

    int x = 0, y = 0;

    // Step 3: Divide elements into two groups based on the set bit
    for (int i = 0; i < n; i++) {
        if (nums[i] & rightmost_set_bit)
            x ^= nums[i];
        else
            y ^= nums[i];

        if ((i + 1) & rightmost_set_bit)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    // Step 4: Determine which is missing and which is repeating
    int repeating = 0, missing = 0;
    for (int num : nums) {
        if (num == x) {
            repeating = x;
            missing = y;
            break;
        }
        if (num == y) {
            repeating = y;
            missing = x;
            break;
        }
    }

    return {repeating, missing};
}
