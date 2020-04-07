#include <Statistics.h>

Statistics st = Statistics();
double values[3];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start data");
    st.add(1);
    st.add(2);
    st.add(3);
    st.add(4);
    st.add(5);
    st.add(6);
    Serial.println("End data");

    Serial.print("Mean ");
    Serial.println(st.mean());

    Serial.print("Var ");
    Serial.println(st.var());

    Serial.print("Std ");
    Serial.println(st.std());

    Serial.print("Min: ");
    Serial.println(st.minimum());

    Serial.print("Max: ");
    Serial.println(st.maximum());


    Serial.println("Reset ");
    st.reset();

    Serial.print("Samples: ");      
    Serial.println(st.samples()); 

    delay(5000);
}
