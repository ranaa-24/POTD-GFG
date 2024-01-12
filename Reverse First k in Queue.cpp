queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    // tc - O(N) Sc - O(k)
    int n = q.size() - k;
    // reverse first k no. of elements
    stack<int> s;
    while (k--)
    {
        s.push(q.front());
        q.pop();
    }

    // 4 5     stack- 1 2 3
    // pop fronm the stack and put in queue again

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // 1 2 3 4 5 --> 4 5 | 3 2 1 --> 5 | 3 2 1 4  -> | 3 2 1 4 5

    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}