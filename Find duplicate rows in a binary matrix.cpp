vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
{
    // we can solve it by converting the the ith row into string and a map to check duplicates

    // but lets play with bits in the follwing approach, (ever arrengement of 1 & 0s represent a unique number
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        int convertedNumber = 0;
        for (int j = 0; j < N; j++)
        {
            convertedNumber += (matrix[i][j] << N - 1 - j);
        }
        if (map[convertedNumber] != 0)
            ans.push_back(i);
        else
            map[convertedNumber]++;
    }

    return ans;
}