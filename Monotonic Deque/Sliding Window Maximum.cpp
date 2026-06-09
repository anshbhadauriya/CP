class Solution {
public:

/*
Basically idea is:

deque ke back se bada number aajae too remove all smaller number than curr from back
so dq ke front me hmesha largest number maintain hoga

for example:

deque me 5,4,3 hai 
now new ele is 6 so we will remove all ele which are <6 bcs agr vo log abhi contribute nhi kr rhe
as max ele so future me bhi nhi krege..common sense 

now deque will have 6 only 

aur deque me instead of ele push idx kyuki you have to check ki kahi window se bahar ka ele too
deque me nhi... if dq.front()<h-(k-1) mtlb front wala window se bahar hai so you can remove that

TC is somewhat O(2n) => O(n)

deque me maximum k ele ho skte ek bar me 

so, SC is O(K)

we can use multiset also but that is not very efficient 


*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>maximum;
        for(int i=0;i<nums.size();i++){

            while(!dq.empty() and nums[dq.back()]<=nums[i]) dq.pop_back();

            if(!dq.empty() and dq.front()<=i-k) dq.pop_front();

            dq.push_back(i);

            if(i>=k-1)
            maximum.push_back(nums[dq.front()]);
        }

        return maximum;
    }
};
