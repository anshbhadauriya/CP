class ParkingSystem {
public:
int Big,Medium,Small;
    ParkingSystem(int big, int medium, int small) {

        Big=big,Medium=medium,Small=small;

    }
    
    bool addCar(int carType) {

        if(carType==1){
            if(Big){
                Big--;
                return true;
            }
            else return false;
        }
        else if(carType==2){
            if(Medium){
                Medium--;
                return true;
            }
            else return false;
        }
        else{
            if(Small){
                Small--;
                return true;
            }
            else return false;
        }
    }
};
