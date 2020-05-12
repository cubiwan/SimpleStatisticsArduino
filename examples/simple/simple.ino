#include <Statistics.h>

Statistics st = Statistics();

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

    Serial.print("Center: ");
    Serial.println(st.center());

    Serial.print("Sum: ");
    Serial.println(st.sum());

    Serial.print("Root Mean Square: ");
    Serial.println(st.rootMeanSquare());

    Serial.print("Coefficient Of Variation: ");
    Serial.println(st.coefficientOfVariation());
    
    Serial.print("Index Of Dispersion: ");
    Serial.println(st.indexOfDispersion());

    Serial.print("Zero Crossing: ");
    Serial.println(st.zeroCrossing());

    Serial.print("Zero Crossing Rate: ");
    Serial.println(st.zeroCrossingRate());

    Serial.print("Min Max Normalization (5): ");
    Serial.println(st.minMaxNormalization(5));

    Serial.print("Mean Normalization (5): ");
    Serial.println(st.meanNormalization(5));

    Serial.print("Standardization (5): ");
    Serial.println(st.standardization(5));

    Serial.println("Reset ");
    st.reset();

    Serial.print("Samples: ");      
    Serial.println(st.samples()); 

    delay(5000);
}
