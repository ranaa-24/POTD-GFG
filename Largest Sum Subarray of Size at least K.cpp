long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long curr_ptr = 0;
    long long curr_sum = 0;
    long long maxSum = INT_MIN;
    long long front_ptr = 0;
    long long front_sum = 0;

    // create atleast window size of k
    while (curr_ptr < k)
    {
        curr_sum += a[curr_ptr];
        curr_ptr++;
    }

    maxSum = curr_sum;

    while (curr_ptr < n)
    {
        curr_sum += a[curr_ptr];
        curr_ptr++;

        // get the front, add it in total front sum.
        front_sum += a[front_ptr];
        front_ptr++;

        // if all the front elements become negetive, remove it from the curr sum; (curr_ptr - front_ptr is always <= k )
        if (front_sum < 0)
        {
            curr_sum -= front_sum;
            front_sum = 0;
        }

        maxSum = max(maxSum, curr_sum);
    }

    return maxSum;
}