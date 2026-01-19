vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) prefix[i][j]=mat[i][j];

                else if(i==0 and j>0) prefix[i][j]=prefix[i][j-1]+mat[i][j];

                else if(j==0 and i>0) prefix[i][j]=prefix[i-1][j]+mat[i][j];

                else prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+mat[i][j];

                cout<<prefix[i][j]<<" ";
                
            }
            cout<<endl;
        }
