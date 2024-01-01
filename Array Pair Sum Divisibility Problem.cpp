// approach : cpwithcpp
bool canPair(vector<int> nums, int k)
{
    // Code here.
    int n = nums.size();
    if (n % 2 != 0)
        return false;
    unordered_map<int, int> map;
    for (int i : nums)
    {
        int rem = i % k;
        if (map[(k - rem) % k] != 0)
        {
            map[(k - rem) % k]--;
        }
        else
        {
            map[rem]++;
        }
    }

    for (auto it : map)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}