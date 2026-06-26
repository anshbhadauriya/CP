/*
First do brute force 

make vector and do whatever they are asking

worked!

hella annoying ques
dont have energy to optimize this shi
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* temp=head;

        vector<int>nums;

        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }

        int group=1;
        int i=0,n=nums.size();

        // cout<<"size is "<<n<<endl;

        while(i<n){

            //  cout<<"curr ele is "<<nums[i]<<endl;
            //  cout<<"curr idx is "<<i<<endl;
            //  cout<<"curr group size  is "<<group<<endl;

            if(group%2==0){

                if(i+group-1<n){
                reverse(nums.begin()+i,nums.begin()+i+group);

                }
                else{
                    
                    if((n-i)%2==0){
                        // cout<<"i here is "<<i<<endl;
                    reverse(nums.begin()+i,nums.end());
                    }
                }
    
            } 

            else{

        
                if(i+group-1>=n and (n-i)%2==0){
                // cout<<"problem here or what "<<endl;

                // cout<<"so here group size is "<<group<<endl;
                reverse(nums.begin()+i,nums.end());
                }
            }

            i+=group;
            group++;
        }

        temp=head;


        for(int i=0;i<n;i++){
            temp->val=nums[i];
            temp=temp->next;
        }

        return head;


    }
};

/*
TC-> is O(n)

Sc-> O(n)
*/
