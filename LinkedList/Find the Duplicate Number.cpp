class Solution {
public:

/*
not a intuitive problem

you cant solve optimal version if you dont remember the appraoch

imagine it as linked list

har ele ko next pointer maano
for example if 3,2,0,1  so  3->1->2->0
abh agr duplicate hoge isme so it will cause a cycle
and uk ki ham linkedlist me cycle slow and fast pointer se detect krte hai

slow = nums[slow];
fast = nums[nums[fast]];

abh slow and fast kahi na kahi meet kr chuke hai not exactly at duplicate

now we do: slow=nums[0]

so abh fast aur slow dono ko ek ek step aage badao so when they meet at a point that point is duplicate ele 

this is a mathematical proof

this problem is similar to https://leetcode.com/problems/linked-list-cycle-ii/

Time: O(n)
Space: O(1)
*/
    int findDuplicate(vector<int>& nums) {

        int slow=nums.front();
        int fast=nums.front();

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }
        while(slow!=fast);

        slow=nums.front();

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
        
    }
};
