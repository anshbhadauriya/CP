class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<int>degree(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    
                    degree[j]++;
                }
            }
        }
        return degree;
    }
};

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        sort(sides.begin(),sides.end());

        

        int n=sides.size();

        double c=sides[n-1];
        double a=sides[0];
        double b=sides[1];

        if(a+b<=c) return {};

        vector<double>angles(3);

        angles[0]=acos((b*b+c*c-a*a)/(2*b*c));

        angles[1]=acos((a*a+c*c-b*b)/(2*a*c));

        angles[2]=acos((a*a+b*b-c*c)/(2*a*b));

        for(int i=0;i<3;i++){
            angles[i]=angles[i]*180.0/M_PI;

        }

        return angles;


        
    }
};
