/*
	statistics2.h -  Basic statistics for Arduino
	Created by Cubiwan 2020
	Released into the public domain.
*/

#ifndef Statistics2_h
#define Statistics2_h

#include "Arduino.h"
#include "Statistics.h"


class Statistics2 {
    public:
        void add(double x, double y);
        double correlation();
        double pearsonCorrelation();
        double spearmanCorrelation(); 
        double covar();
        double calculateLinearRegression(double x);
        void parametersLinearRegression(double values[]);
        void centroid(double values[]);
        double samples();
        void reset();
        double meanX();
        double varX();
        double stdX();
        double minimumX();
        double maximumX();
        double sumX();
        double meanY();
        double varY();
        double stdY();
        double minimumY();
        double maximumY();
        double sumY();
    private:
        Statistics stX = Statistics();
        Statistics stY = Statistics();
        double meanXY = 0;
        double covarXY = 0;
        double n = 0;
};

#endif