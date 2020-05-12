#include <Error.h>

Error error = Error();

/*
    X | Y 
    __|__
    0 | 0.5
    1 | 2.5
    2 | 4.5
    3 | 6.5
    4 | 8.5
    5 | 10.5
    6 | 12.5
*/

double y[7] = {0.5,2.5,4.5,6.5,8.5,10.5,12.5};

void setup() {
    Serial.begin(9600);     
}

void loop() {    
    error.add(estimation(0),y[0]);
    error.add(estimation(1),y[1]);
    error.add(estimation(2),y[2]);
    error.add(estimation(3),y[3]);
    error.add(estimation(4),y[4]);
    error.add(estimation(5),y[5]);
    error.add(estimation(6),y[6]);
    error.add(estimation(7),y[7]);

    Serial.print("MSE: ");
    Serial.println(error.MSE());
    Serial.print("RMSE: ");
    Serial.println(error.RMSE());
    Serial.print("MAE: ");
    Serial.println(error.MAE());
    Serial.print("Total: ");
    Serial.println(error.total());
    error.reset();

    delay(5000);
}

int estimation(int x){
    return x+1;    
}
