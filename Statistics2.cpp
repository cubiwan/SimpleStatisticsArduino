#include "Arduino.h"
#include "Statistics2.h"

void Statistics2::add(double x, double y){
    n++;

    stX.add(x);
    stY.add(y);

    meanXY = meanXY + (((x*y)-meanXY)/n);
    covarXY = meanXY - (stX.mean()*stY.mean());
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
    double m = covarXY / stX.var();
    double b = stY.mean()-(m*stX.mean());
    return (m*x) + b;
}

double Statistics2::errorLinearRegression(double x, double y){
    return y - calculateLinearRegression(x);
}

void Statistics2::parametersLinearRegression(double values[]){
    values[0] = covarXY / stX.var();
    values[1] = stY.mean()-(values[0]*stX.mean());
}

double Statistics2::samples(){
    return n;
}

double Statistics2::sumXY(){ //aprox.
    return meanXY * n;
}

double Statistics2::centerOfGravity(double values[]){
    values[0] = stX.mean();
    values[1] = stY.mean();
}

double Statistics2::centerOfMassXY(){ //y Mass x distance
    return sumXY()/stY.sum();
}

double Statistics2::centerOfMassYX(){ //x Mass y distance
    return sumXY()/stX.sum();
}

void Statistics2::reset(){
    stX.reset();
    stY.reset();
    meanXY = 0;
    covarXY = 0;
    n = 0;
}
