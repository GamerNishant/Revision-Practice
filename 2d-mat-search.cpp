#include <bits/stdc++.h>

using namespace std;

// staircase binary search
// this is not log(m*n)
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mat[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        int target;
        cin >> target;

        int i = 0;
        int j = m - 1;
        bool flag = false;
        while (i < n and j >= 0)
        {
            if (mat[i][j] == target)
            {
                flag = true;
                break;
            }
            else if (mat[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}