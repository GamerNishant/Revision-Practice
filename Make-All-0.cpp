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

        bool row[n] = {false};
        bool col[m] = {false};


        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j <m; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }


        for(int i = 0;i<n; i++)
        {
            if(row[i])
            {
                for(int j = 0; j<m; j++)
                {
                    mat[i][j] = 0;
                }
            }
        }

        for(int j = 0;j<m; j++)
        {
            if(col[j])
            {
                for(int i = 0; i<n; i++)
                {
                    mat[i][j] = 0;
                }
            }
        }


        for(int i = 0; i<n; i++){
        for(int j = 0; j<m ;j++)
        cout << mat[i][j] << ' ';
        cout << endl;
        }
    }
    return 0;
}