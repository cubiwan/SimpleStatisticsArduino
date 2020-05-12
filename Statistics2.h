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
        Statistics stX = Statistics();
        Statistics stY = Statistics();
        void add(double x, double y);
        double correlation();
        double pearsonCorrelation();
        double spearmanCorrelation(); 
        double covar();
        double calculateLinearRegression(double x);
        double errorLinearRegression(double x, double y);
        void parametersLinearRegression(double values[]);
        void centroid(double values[]);
        double centerOfGravity(double values[]);
        double centerOfMassXY(); //y Mass x distance
        double centerOfMassYX(); //x Mass y distance
        double sumXY(); //aprox
        double samples();
        void reset();
    private:
        double meanXY = 0;
        double covarXY = 0;
        double n = 0;
};

#endif
