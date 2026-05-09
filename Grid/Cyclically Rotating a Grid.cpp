class Solution {
public:

void insert_kro(vector<vector<int>>& grid, deque<int>&dq,int to_rotate, int st_row,int st_col,int end_row,int end_col){

    cout<<"After rotating "<<endl;

    int r=st_row,c=st_col,i=0;

            while(r<end_row){

                grid[r][c]=dq[i];

                cout<<grid[r][c]<<" ";

                r++;
                i++;
            }

            --r;

            ++c;
            while(c<end_col){

                grid[r][c]=dq[i];

                cout<<grid[r][c]<<" ";

                c++;
                i++;
            }

            --c;

            --r;

            while(r>=st_row){

                grid[r][c]=dq[i];

                cout<<grid[r][c]<<" ";

                r--;
                i++;
            }
            ++r;

            --c;

            while(c>=st_col){

                if(c!=st_col)
                grid[r][c]=dq[i];

                if(c!=st_col)
                cout<<grid[r][c]<<" ";

                c--;
                i++;
            }
            ++c;

            cout<<endl;


}
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        

        /*

        Sbse pehle 0 to n-1 wale ke sare cell ko rotate kro

        then 1 to n-2

        while st<end





        sbse pehle deuque me dalo

        then rotate

        then place them 


        */

        int n=grid.size(),m=grid[0].size();

        int st_col=0,end_col=m;

        int st_row=0,end_row=n;

        while((end_row-st_row)>1 and (end_col-st_col)>1){

            int r=st_row,c=st_col;

            deque<int>dq;

            

            while(r<end_row){

                dq.push_back(grid[r][c]);

                cout<<grid[r][c]<<" ";

                r++;
            }

            --r;

            ++c;
            while(c<end_col){

                dq.push_back(grid[r][c]);

                cout<<grid[r][c]<<" ";

                c++;
            }

            --c;

            --r;

            while(r>=st_row){

                dq.push_back(grid[r][c]);

                cout<<grid[r][c]<<" ";

                r--;
            }
            ++r;

            --c;

            while(c>=st_col){

                if(c!=st_col)
                dq.push_back(grid[r][c]);

                if(c!=st_col)
                cout<<grid[r][c]<<" ";

                c--;
            }
            ++c;

            cout<<endl;

            cout<<"Here one iteration done->"<<r<<" "<<c<<endl;



            //######################### ABH ROTATE KRO ###############

            int to_rotate=k%dq.size();

            while(to_rotate--){

                int temp=dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }


            insert_kro(grid,dq,to_rotate,st_row,st_col,end_row,end_col);



            st_row++;
            st_col++;
            end_row--;
            end_col--;

        }

        return grid;
        
    }
};
