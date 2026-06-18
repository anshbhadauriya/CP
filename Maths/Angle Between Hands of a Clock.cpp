class Solution {
public:
    double angleClock(int hour, int minutes) {

        //hour to angle realtion nikalo

        //1 hour -> 30 min

        double hour_to_angle=(hour%12)*30;

        cout<<"hour to angle "<<hour_to_angle<<endl;

        //1 min kitna hour bada degi

        //60 min-> 30 degree
        //30 min-> 15 degree
        //15 min-> 7.5 degree
        //so its min/2

        double min_increase_hour=double(minutes)/2;

        cout<<"min_increase_hour "<<min_increase_hour<<endl;

        //min to angle relation 

        //5 min -> 30 degree
        //10 min-> 60 degree
        //so 1 min-> 6 degree

        double min_to_angle=minutes*6;

        cout<<"min_to_angle "<<min_to_angle<<endl;


        //lekin ek case aissa bhi ho skta hai jisme piche wala angle kam ho



        double angle1= abs((hour_to_angle + min_increase_hour) - min_to_angle);

        double angle2=360-angle1;

        return min(angle1,angle2);
        
    }
};
