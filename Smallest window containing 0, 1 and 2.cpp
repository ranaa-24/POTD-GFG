int smallestSubstring(string S)
{
    // Code here
    int zero = -1;
    int one = -1;
    int two = -1;
    int ans = INT_MAX;
    int windowSize = INT_MAX;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '0')
            zero = i;
        if (S[i] == '1')
            one = i;
        if (S[i] == '2')
            two = i;

        if (zero != -1 && one != -1 && two != -1)
        { // window size = maxIndex - minIndex among 3 + 1
            int maxIdx = max({zero, one, two});
            int minIdx = min({zero, one, two});
            windowSize = maxIdx - minIdx + 1;
        }

        ans = min(ans, windowSize);
    }

    return ans == INT_MAX ? -1 : ans; // if window never founded return -1
}