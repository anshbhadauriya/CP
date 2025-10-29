class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size=nums1.size()+nums2.size();
        int idx2=total_size/2;
        int idx1=idx2-1;

        int i=0,j=0,count=-1;
        int answer1,answer2;
        bool first_found=false,second_found=false;

        while(i<nums1.size() and j<nums2.size()){
            ++count;
            if(nums1[i]<=nums2[j]){
                if(count==idx1){
                    answer1=nums1[i];
                    first_found=true;
                }
                if(count==idx2){
                    answer2=nums1[i];
                    second_found=true;
                    break;
                }
                i++;
            }

            else if(nums1[i]>nums2[j]){
                if(count==idx1){
                    answer1=nums2[j];
                    first_found=true;
                }
                if(count==idx2){
                    answer2=nums2[j];
                    second_found=true;
                    break;
                }
                j++;
            }
            
        }

        while(!second_found and i<nums1.size()){
            ++count;
             if(count==idx1){
                    answer1=nums1[i];
                    first_found=true;
                }
                if(count==idx2){
                    answer2=nums1[i];
                    second_found=true;
                    break;
                }
                i++;
        }

        while(!second_found and j<nums2.size()){
            ++count;
             if(count==idx1){
                answer1=nums2[j];
                first_found=true;
                }
                if(count==idx2){
                    answer2=nums2[j];
                    second_found=true;
                    break;
                }
                j++;
        }

            if(total_size%2==0){
                double x=(answer1+answer2)/2.0;
                return x;
            }
            
            double x=double(answer2);
                return x;
            
        
        


    }
};
