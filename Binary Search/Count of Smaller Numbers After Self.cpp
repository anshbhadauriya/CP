class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //kisi sorted array me agr pta krna ho ki konsa element kitne elements se bada hai too use lower_bound


        //inution:-

        //piche se traverse kro nums me 
        //ek sorted array maintain kro jisse pta chal pae ki current element se kitne element chote hai
        //ussi sorted array par lower_bound use kre pta krlo ki kitne element curr element se chote hai

        //jo bhi idx lower_bound de iska mtlb utne hi element curr se chote hai

        //vo idx result me daldo aur curr element ko sorted me usski postion me (idx position)

        int n=nums.size();

        vector<int>sorted;
        vector<int>result(n);

        for(int i=n-1;i>=0;i--){

            int curr=nums[i];

            int idx=lower_bound(sorted.begin(),sorted.end(),curr)-sorted.begin();

            result[i]=idx;

            sorted.insert(sorted.begin()+idx,curr);
        }

        return result;
    }
};
