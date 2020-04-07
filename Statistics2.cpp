#include "Arduino.h"
#include "Statistics2.h"

void Statistics2::add(double x, double y){
    n++;

    stX.add(x);
    stY.add(y);

    meanXY = meanXY + (((x*y)-meanXY)/n);
    covarXY = meanXY - (meanX()*meanY());
}

double Statistics2::correlation() {
    double stdXstdY = stX.std()*stY.std();
    double correlation;

    if(stdXstdY == 0){
        correlation = 1;
    } else {
        correlation = covarXY / stdXstdY;
    }
    return correlation;
}

double Statistics2::pearsonCorrelation() {
    return correlation();
}

double Statistics2::spearmanCorrelation() {  //aprox using Pearson valid with more of 20 samples
    double p = correlation();
    return p/sqrt((1-p*p)/(n-2));
}

double Statistics2::covar(){
    return covarXY;
}

void Statistics2::centroid(double values[]){
    values[0] = stX.center();
    values[1] = stY.center();
}


double Statistics2::calculateLinearRegression(double x) {
    double m = covarXY / varX();
    double b = meanY()-(m*meanX());

    return (m*x) + b;
}

void Statistics2::parametersLinearRegression(double values[]){
    values[0] = covarXY / varX();
    values[1] = meanY()-(m*meanX());
}

double Statistics2::samples(){
    return n;
}

void Statistics2::reset(){
    stX.reset();
    stY.reset();
    meanXY = 0;
    covarXY = 0;
    n = 0;
}

//X
double Statistics2::meanX(){
    return stX.mean();
}

double Statistics2::varX(){
    return stX.var();
}

double Statistics2::stdX(){
    return sqrt(stX.var());
}

double Statistics2::minimumX(){
    return stX.minimum();
}

double Statistics2::maximumX(){
    return stX.maximum();
}

double Statistics2::sumX(){
    return stX.sum();
}

//Y
double Statistics2::meanY(){
    return stY.mean();
}

double Statistics2::varY(){
    return stY.var();
}

double Statistics2::stdY(){
    return sqrt(stY.var());
}

double Statistics2::minimumY(){
    return stY.minimum();
}

double Statistics2::maximumY(){
    return stY.maximum();
}

double Statistics2::sumY(){ //aprox.
    return stY.sum();
}