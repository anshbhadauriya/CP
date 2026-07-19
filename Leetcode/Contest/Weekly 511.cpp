/*

11
32
24
43
22

so ek  move me ham +2 +1 kr rhe yaa fir -1 +2 
( 2,  1)
( 2, -1)
(-2,  1)
(-2, -1)
( 1,  2)
( 1, -2)
(-1,  2)
(-1, -2)

odd moves hoge too alg color hoga 
even moves hoge too same color

*/ 

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {


        int dist=abs(start[0]-target[0])+abs(start[1]-target[1]);

        return dist%2==0;
       
        
    }
};

Q2->

  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int left=solve(root->left);
        int right=solve(root->right);

        if(root->val>=left and root->val>=right){
            // cout<<"i am "<<root->val<<endl;
            // cout<<"my left is "<<left<<" and my right is "<<right<<endl;
            count++;
        }
        
        return max({left,right,root->val});

        
        
    }
    int countDominantNodes(TreeNode* root) {
         solve(root);
        return count;
    }
};

Q3->

  /*

s 
strs

str[i] ki length == s ki length

strs[i] = 0,1,?

each ? -> 0,1

choose any subsequence from s  (sub)

sort sub increasing order

replace choses sub in s with sorted sub

return true if its poss to convert


observations:

freq of 1 and 0 in both string should be equal

all 1's in strs[i] should be after all 1's in s
that means agr kabhi koi 1 strs[i] me pehle aajae s se too its impossible

do track of prefix 1 jo ki bataega ki curr idx se pehle kya one hai hamare paas

aur agr ? mark aae too koshish kro usse zero banane ki 
agr zero nhi bana skte too treat it as 1

*/

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int target_one=0,target_zero=0;
        vector<int>pref;
        for(auto x:s){
            if(x=='1') target_one++;
            else target_zero++;
            pref.push_back(target_one);
        }
        

            int first_occ_of_one_in_s=-1;

            
            for(int i=0;i<s.size();i++){
                if(s[i]=='1'){ first_occ_of_one_in_s=i; break; }
            }

        vector<bool>ans;

        for(auto curr:strs){
          // cout<<"curr i idhr tak aagya successfully "<<curr<<endl;
            if(curr.size()!=s.size()){ ans.push_back(false); continue; }
            
            int curr_zero=0,curr_one=0,to_fill=0;
            
            for(int i=0;i<curr.size();i++){

                if(curr[i]=='1') curr_one++;
                else if(curr[i]=='0') curr_zero++;
                else to_fill++;
                
            }

            //yaa too zeros+fill == target zero hoo yaa too ones+fill==target one ho
            if(curr_zero<target_zero and curr_one<target_one){
                //cout<<"ok"<<endl;
            }
            else if(curr_zero+to_fill!=target_zero and curr_one+to_fill!=target_one){
                // cout<<"here is the fault"<<endl;
                ans.push_back(false);
                continue;
            }

            //curr ke first occ of 1 ki positon> s ke last one ki position

            int remaining_one=target_one-curr_one,remaining_zero=target_zero-curr_zero;
        // cout<<target_zero<<endl;
        //     cout<<curr_zero<<endl;
        //     cout<<"remaining one is "<<remaining_one<<endl;
        //     cout<<"remaining zero is "<<remaining_zero<<endl;
        //     cout<<endl;


        

            bool flag=false;
        int minus=0;

            //cout<<"remaining zero hai "<<remaining_zero<<" remaining one hai "<<remaining_one<<endl;
        for(int i=0;i<curr.size();i++){
//cout<<curr[i]<<" ";
            if(curr[i]=='?'){
                if(remaining_zero>0){
                    //cout<<" here ";
                    remaining_zero--;
                    continue;
                }
                else{
                    curr[i]='1';
                    //cout<<" curr[i] changed to 1 ";
                }
            }

            


            if(curr[i]=='1'){
                if(pref[i]-minus>0){ minus++; continue;}
                
                else{
                    
                    ans.push_back(false);
                    flag=true;
                    break;
                }
                
            }
            

            
        }
            //cout<<endl;
            if(flag) continue;

            ans.push_back(true);
            
        }

        return ans;
        
    }
};
