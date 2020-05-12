#include <Statistics2.h>

Statistics2 st = Statistics2();

double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    st.add(1,3);
    st.add(2,4);
    st.add(3,5);
    st.add(4,6);
    st.add(5,7);
    st.add(6,8);
    Serial.println("End learn");

    Serial.print("Result: 6 -> ");
    Serial.println(st.calculateLinearRegression(6));

    Serial.print("Result: 7 -> ");
    Serial.println(st.calculateLinearRegression(7));

    Serial.print("Correlation: ");
    Serial.println(st.correlation());

    Serial.print("Covar: ");
    Serial.println(st.covar());

    Serial.println("Centroid");
    st.centroid(values);
    Serial.print("X: ");
    Serial.print(values[0]);
    Serial.print(" Y: ");
    Serial.println(values[1]);

    Serial.println("Reset");
    st.reset();
    
    delay(5000);
}
