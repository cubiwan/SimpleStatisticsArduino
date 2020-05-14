# SimpleStatisticsArduino &nbsp;&nbsp;&nbsp;&nbsp;<a href='https://ko-fi.com/I2I012UF3' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

Library to calculate basic statistics in arduino.

### Create

```c
Statistics st = Statistics();
```

*Statistics* is used for a single variable

```c
Statistics2 st = Statistics2();
```

*Statistics2* is used for two variables

```c
Error st = Error();
```

*Error* useful to measure estiamtion error

### Statistics - Methods 

```c
void add(double value); 
```
Add sample to statistics

```c
double samples(); 
```
Number of samples added

```c
double mean();  
```
Mean

```c
double var(); 
```
Variance

```c
double std();  
```
Standard deviation

```c
double minimum(); 
```
Minimun value added

```c
double maximum(); 
```
Maximun value added

```c
double center(); 
```
Calculate center = (maximun-minimun)/2

```c
double sum();
```
Aproximation to sum of all values added

```c
double minMaxNormalization(double value);
```
Normalizate value using minmax normalization 

```c
double meanNormalization(double value);
```
Normalizate value using mean normalization 

```c
double standardization(double value);
```
Standardization of value (Z-score)

```c
double rootMeanSquare();
```
Root mean square  

```c
double coefficientOfVariation();
```
Coefficient of variation  

```c
double indexOfDispersion();
```
Index Of Dispersion  

```c
double zeroCrossing();
```
Zero crossing  

```c
double zeroCrossingRate();
```
Zero crossing Rate = zeroCrossing()/samples() 

```c
void reset();  
```
Reset values.

### Statistics2 - Methods 

```c
void add(double x, double y); 
```
Add samples to statistics

```c
double correlation(); 
```
Calculate correlation coefficient between X and Y (use Pearson's correlation)  

```c
double pearsonCorrelation();
```
Calculate Pearson's correlation coefficient between X and Y  

```c
double spearmanCorrelation(); 
```
Calculate Spearman's correlation coefficient between X and Y (aproximation using Pearson, valid with more of 20 samples)

```c
double covar();
```
Calculate covariance

```c
double calculateLinearRegression(double x);
```
Calculate linear regression. Estimates y value from parameter x

```c
void parametersLinearRegression(double values[]);
```
Return parameters m and b. y = m*x +b 
values[0] = m;
values[1] = b;

```c
void centroid(double values[]);
```
Calculate centroid.  
values[0] = stX.center();  
values[1] = stY.center();  

```c
void centerOfGravity(double values[]);
```
Calculate center of gravity  
values[0] = stX.mean();  
values[1] = stY.mean();  

```c
void centerOfMassXY();
```
Calculate center of mass. Use Y as mass and X as distance  
sumXY()/stY.sum();  

```c
void centerOfMassXY();
```
Calculate center of mass. Use X as mass and Y as distance  
sumXY()/stX.sum();  

```c
void sumXY();
```
Aproximation of summation X*Y  

```c
double samples(); 
```
Number of samples added

```c
void reset();  
```
Reset values

```c
Statistics stX;  
```
Statistics object for X values  

```c
Statistics sty;  
```
Statistics object for Y values  

### Error - Methods

```c
void add(int ey, int y);  
```
Learns one example.
* ey: value of estimated Y
* y: value of Y  

Return abs(ey-y)
<br>

```c
double RMSE();  
```
Return Root mean squared error  
<br>

```c
double MSE();  
```
Return Mean squared error  
<br>

```c
double MAE();  
```
Return Mean absolute error   
<br>

```c
double total();  
```
Return aprox. to sum of all error  
<br>

```c
void reset();  
```
Reset values. Delete all values  
<br>

```c
void samples();
```
Return number of samples used
