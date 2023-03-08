class ParkingSystem {

    #define CAR_TYPE_BIG    0
    #define CAR_TYPE_MEDIUM 1
    #define CAR_TYPE_SMALL  2
    #define CAR_TYPES_NUM   3

    int mLots[CAR_TYPES_NUM][2] = {0};

public:
    ParkingSystem(int big, int medium, int small) {
        mLots[CAR_TYPE_BIG][1] = big;
        mLots[CAR_TYPE_MEDIUM][1] = medium;
        mLots[CAR_TYPE_SMALL][1] = small;
    }
    
    bool addCar(int carType) {
        carType = carType - 1;
        if (mLots[carType][0] < mLots[carType][1])
        {
            mLots[carType][0]++;
            return true;
        }
        return false;
    }
};