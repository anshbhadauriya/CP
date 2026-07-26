Q1->
class Solution {
public:
    int sum(int curr){

        int temp=0;

        while(curr>0){
            temp+=curr%10;
            curr=curr/10;
        }

        return temp;
    }
    int largestInteger(int n, int s) {

        int st=9;

        for(int i=1;i<n;i++){
            st=9+st*10;
        }

      

        while(st>=0){

            if(sum(st)==s) return st;

            st--;
        }

        return -1;

        

        
    }
};

Q2->
/*
series1 ,series2

timestamp value

sorted in ascending

agr koi timestamp is not present in series so its val is taken from next available timestamp

soo basically we need to know next greater ele 

but array is in sorted form so we can use binary search

*/
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        unordered_map<int,int>mp1,mp2; //for series1 and series2
        vector<int>time1,ser1,time2,ser2;

        //dono vector se max ele nikalo

        int maximum=INT_MIN,minimum=INT_MAX;
        int max_time_of_series1=0,max_time_of_series2=0;

        set<int>ts;

        for(auto x:series1){
            int ele=x[0];

            time1.push_back(x[0]);
            ser1.push_back(x[1]);

            mp1[x[0]]=x[1];

            if(ele>maximum){
                maximum=ele;
                max_time_of_series1=ele;
            }
           

            ts.insert(x[0]);
            
        }
        for(auto x:series2){
            int ele=x[0];

            time2.push_back(x[0]);
            ser2.push_back(x[1]);

            mp2[x[0]]=x[1];

            if(ele>maximum){
                maximum=ele;
               
            }

             max_time_of_series2=max( max_time_of_series2,ele);


            ts.insert(x[0]);
        }
        
        //cout<<"max time of 2 "<<max_time_of_series2<<endl;
        // sort(ts.begin(),ts.end());
     
        //cout<<maximum<<endl;

        vector<vector<int>>ans;


        for(auto x:ts){
            int i=x;
            //cout<<"time stamp is "<<i<<endl;
            int a,b=0;
            
            if(mp1.count(i)){
                 a=mp1[i];
            }
            else{  //use bs

                if(i>max_time_of_series1){
                    a=0;
                }
                else{
                    int idx=lower_bound(time1.begin(),time1.end(),i)-time1.begin();
                    // cout<<" idx is "<<idx<<"array is s1"<<endl;

                    // cout<<"series of idx "<<ser1[idx]<<endl;
                    a=ser1[idx];
                }
                
            }

            if(mp2.count(i)){
                b=mp2[i];
                //cout<<"here b is "<<b<<endl;
            }
            else{

                if(i>max_time_of_series2){
                    //cout<<"here is b "<<endl;
                    b=0;
                }
                else{
                    int idx=lower_bound(time2.begin(),time2.end(),i)-time2.begin();

                    //cout<<"idx is "<<idx<<endl;
                    b=ser2[idx];
                }
                
            }

            //cout<<"a is "<<a<<" and b is "<<b<<endl;

            ans.push_back({i,a+b});
            
        }
        

        

        

        return ans;
        
    }
};
Q3->

class Solution {
public:
    #define ll long long
    const ll INF = 1e18;

    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        // dist[i][j][parity]
        vector<vector<vector<ll>>>dist(m,vector<vector<ll>>(n,vector<ll>(2,INF)));

        // {cost,x,y,parity}
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;

        // parity = 0 -> odd action
        // parity = 1 -> even action

        dist[0][0][0]=1;
        pq.push({1,0,0,0});

        while(!pq.empty()){

            auto it=pq.top();
            pq.pop();

            ll curD=it[0];
            ll x=it[1];
            ll y=it[2];
            ll p=it[3];

            // cout<<curD<<" "<<x<<" "<<y<<" "<<p<<endl;

            if(curD!=dist[x][y][p]) continue;

            //================ WAIT =================

            // wahi ruk jao
            // penalty lagegi aur parity flip hojaegi

            if(dist[x][y][p^1]>curD+penalty[x][y]){

                dist[x][y][p^1]=curD+penalty[x][y];
                pq.push({dist[x][y][p^1],x,y,p^1});

                // cout<<"wait "<<x<<" "<<y<<endl;
            }

            //================ MOVE =================

            for(int k=0;k<4;k++){

                ll curX=x+dir[k][0];
                ll curY=y+dir[k][1];

                if(curX<0 || curX>=m || curY<0 || curY>=n)
                    continue;

                // destination cell ki entry cost
                ll cost=(curX+1)*(curY+1);

                bool bl=false;

                if(!p){

                    // odd action
                    // sirf right/down free hai

                    if((curX==x+1 && curY==y) ||
                       (curX==x && curY==y+1))
                        bl=true;
                }
                else{

                    // even action
                    // sirf left/up free hai

                    if((curX==x-1 && curY==y) ||
                       (curX==x && curY==y-1))
                        bl=true;
                }

                // agr rule violate hua
                if(!bl)
                    cost+=penalty[x][y];

                if(dist[curX][curY][p^1]>curD+cost){

                    dist[curX][curY][p^1]=curD+cost;
                    pq.push({dist[curX][curY][p^1],curX,curY,p^1});

                    // cout<<curX<<" "<<curY<<" "<<dist[curX][curY][p^1]<<endl;
                }
            }
        }

        return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }
};
