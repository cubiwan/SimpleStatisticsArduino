/*
	statistics.cpp -  Basic statistics for Arduino
	Created by Cubiwan 2020
	Released into the public domain.
*/

#include "Arduino.h"
#include "Statistics.h"

void Statistics::add(double value){
    if(n == 0){
        minValue = value;
        maxValue = value;
    } else {
        if(minValue > value){
            minValue = value;
        }
        if(maxValue < value){
            maxValue = value;
        }
    }
    
    n++;
    meanValue = meanValue + ((value-meanValue)/n);
    meanValue2 = meanValue2 + (((value*value)-meanValue2)/n);    
    varValue = meanValue2 - (meanValue*meanValue);
}

double Statistics::samples(){
    return n;
}

double Statistics::mean(){
    return meanValue;
}

double Statistics::var(){
    return varValue;
}

double Statistics::std(){
    return sqrt(varValue);
}

double Statistics::minimum(){
    return minValue;
}

double Statistics::maximum(){
    return maxValue;
}

double Statistics::center(){
    return (maxValue+minValue)/2;
}

double Statistics::sum(){ //aprox.
    return meanValue*n;
}

void Statistics::reset(){
    meanValue = 0;
    meanValue2 = 0;
    varValue = 0;
    n = 0;
    minValue = 0;
    maxValue = 0;
}

