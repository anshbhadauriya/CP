/*
so basically agr ham 

curr builiding height se just smaller building height dekhe from right side so we can max answer

so agr jo bhi chota ho usse aage badao 

agr l < h so l++
agr l > h so h--
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,h=n-1,maximum=-1;

        while(l<h){

        maximum=max(maximum,min(height[h],height[l])*(h-l));

            if(height[l]>=height[h]){

                h--;
            }
            else{
                l++;
            }

            
        }

        return maximum;
        
    }
};
/*
TC-> O(n)
SC-> O(1)
*/
