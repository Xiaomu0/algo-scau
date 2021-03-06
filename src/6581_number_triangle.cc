#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int k_max = 100;
int c[k_max][k_max];
int d[k_max][k_max];
int n;

int solve(const int &a, const int &b)
{
    if (d[a][b] != -1) return d[a][b];
    else
    {
        if (a == n - 1) return c[a][b];
        else
        {
            int left = solve(a + 1, b);
            int right = solve(a + 1, b + 1);
            return d[a][b] = c[a][b] + max(left, right);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &c[i][j]);
            d[i][j] = -1;
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}
