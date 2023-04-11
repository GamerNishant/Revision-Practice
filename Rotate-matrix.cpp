#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int mat[n][m];
        for(int i = 0;i <n; i++)
        for(int j = 0; j< m; j++)
        cin>> mat[i][j];

        // taking transpose

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(i < j)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }


        for(int i = 0; i<n; i++)
        {
            reverse(mat[i], mat[i]+m);
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}