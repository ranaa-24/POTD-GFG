// YT - Binary Search Playlist - Striver - Book allocations s
class Solution
{
    int sumAll(int arr[], int n)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];
        }
        return s;
    }

    int maxElement(int arr[], int n)
    {
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int countSubArrays(int arr[], int n, int capacity)
    {
        int subArrays = 1;
        long canHold = 0;
        for (int i = 0; i < n; i++)
        {
            if (canHold + arr[i] <= capacity)
            {
                canHold += arr[i];
            }
            else
            {
                subArrays++;
                canHold = arr[i];
            }
        }
        return subArrays;
    }

public:
    int splitArray(int arr[], int n, int k)
    {
        // code here
        if (n < k)
            return -1;
        // using binary search for getting perferct splitted arrar
        int low = maxElement(arr, n);
        int high = sumAll(arr, n);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int subArrays = countSubArrays(arr, n, mid);

            if (subArrays > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};