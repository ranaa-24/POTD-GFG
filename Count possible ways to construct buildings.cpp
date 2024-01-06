// YT- algoMinds
int mod = 1e9 + 7;
int TotalWays(int N)
{
    // Code here.. // its actually fiboancci.. like for n=1, one side possibilies will be (_*_|B, _B_|*), and square it to combaine the other side
    long n1 = 2; // n=1; ans = 4 (2^2)
    long n2 = 3; // n=2.. ansTechfest and the Queue = 9(3^3);
    if (N == 1)
        return 4;
    if (N == 2)
        return 9;
    //... same way n3 = n1+n2 = 5 = 5^5 = 25(ans);
    long n3;
    for (int i = 3; i <= N; i++)
    {
        n3 = (n1 + n2) % mod;
        n1 = n2;
        n2 = n3;
    }

    return (n3 * n3) % mod;
}