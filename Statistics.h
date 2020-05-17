/*
	statistics.h -  Basic statistics for Arduino
	Created by Cubiwan 2020
	Released into the public domain.
*/

#ifndef Statistics_h
#define Statistics_h

#include "Arduino.h"

class Statistics {
    public:
        void add(double value);
        double samples();
        double mean();
        double var();
        double std();
        double minimum();
        double maximum();
        double center();
        double sum(); //aprox.
        double minMaxNormalization(double value);
        double meanNormalization(double value);
        double standardization(double value);
        double rootMeanSquare();
        double geometricMean();
        double harmonicMean();
        double coefficientOfVariation();
        double indexOfDispersion();
        double zeroCrossing();
        double zeroCrossingRate();
        void reset();
    private:
        double meanValue = 0;
        double meanValue2 = 0;
        double meanLnValue = 0;
        double lastValue = 0;
        double varValue = 0;
        double n = 0;
        double minValue = 0;
        double maxValue = 0;
        double zc = 0;
};

#endif
