class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hmap;
        int threshold = nums.size() / 3;
        vector<int> ans;

        for (int num : nums)
        {
            hmap[num]++;
        }

        for (auto &pair : hmap)
        {
            if (pair.second > threshold)
            {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
