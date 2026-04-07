//bottom left-> 0,0
//top right-> width-1,height-1
//N E S W
//initially at 0,0 facing E
//every time one step forward
//if out of bond 90 degree turn

//track-> i,j,direction 
//robot hmesha boundary pr hi chlega it will never go in center


class Robot {
public:
int w,h,i=0,j=0,curr=0;
vector<pair<pair<int,int>,char>>nums;  //{{i,j},direction}
bool moved=false;
    Robot(int width, int height) {
        w=width,h=height;

        if(w==1 and h==1){
            nums.push_back({{0,0},'E'});
            return;
        }
        

        //pehle East wale dalo
        int i=0;
        for(i=0;i<w;i++){
            nums.push_back({{0,i},'E'});
            cout<<'('<<0 <<i <<'E'<<')';
        }


        //North
        
        for(i=1;i<h;i++){
            nums.push_back({{i,w-1},'N'});
            cout<<'('<<i <<w-1 <<'N'<<')';
        }


        //West

        for(i=w-2;i>=0;i--){
            nums.push_back({{h-1,i},'W'});
           cout<<'('<<h-1 <<i <<'W'<<')';
        }


        //South

        for(i=h-2;i>=1;i--){
            nums.push_back({{i,0},'S'});
            cout<<'('<<i <<0 <<'S'<<')';
        }
    }
    
    void step(int num) {
       int perimeter=nums.size();
        curr=(curr+num%perimeter)%perimeter;

        // curr=(curr+to_move)%nums.size();

        moved=true;

        //move forward nums step
        
    }
    
    vector<int> getPos() {

          return {nums[curr].first.second, nums[curr].first.first};
        //return current cell
    }
    
    string getDir() {

        if(curr==0 and moved and nums.size()>1) return "South";

        char d=nums[curr].second;
        if(d=='E') return "East";
        if(d=='W') return "West";
        if(d=='N') return "North";
        return "South";
        //return curr direction
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
