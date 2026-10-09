/*
so agr ek bar (  aarha too doo bar )) aana chaiye
agr kabhi ) > (  so mtlb hame count badana padega
*/
class Solution {
    public int minInsertions(String s) {

        int i=0,count=0,ans=0;

        while(i<s.length()){

            if(s.charAt(i)=='('){ count++; i++; }

            else{
                if(count>0) count--;
                else ans++;

                if(i+1<s.length() && s.charAt(i+1)==')') i+=2;

                else{
                    ans++;
                    i++;
                }
            }
        }

        return ans+count*2;
    }
}
