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
    value *= value; // value ^ 2
    meanValue2 = meanValue2 + ((value-meanValue2)/n);    
    
    varValue = meanValue2 - (meanValue*meanValue);
    lastValue = value;

    if(lastValue > 0 && value < 0){
        zc++;
    } else if(lastValue < 0 && value > 0){
        zc++;
    }
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

double Statistics::minMaxNormalization(double value){ 
    return (value - minValue) / (maxValue - minValue);        
}

double Statistics::meanNormalization(double value){ 
    return (value - meanValue) / (maxValue - minValue);        
}

double Statistics::standardization(double value){ //Z-score Normalization
    return (value - meanValue) / std();        
}

double Statistics::rootMeanSquare(){
    return sqrt(meanValue2);
}

double Statistics::coefficientOfVariation(){
    return std()/meanValue;
}

double Statistics::indexOfDispersion(){
    return varValue/meanValue;
}

double Statistics::zeroCrossing(){
    return zc;
}

double Statistics::zeroCrossingRate(){
    return zc/n;
}

void Statistics::reset(){
    meanValue = 0;
    meanValue2 = 0;
    varValue = 0;
    n = 0;
    minValue = 0;
    maxValue = 0;
}
