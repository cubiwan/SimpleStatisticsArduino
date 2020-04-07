# SimpleStatisticsArduino. <a href='https://ko-fi.com/I2I012UF3' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

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
double center(); 
```
Calculate center = (maximun-minimun)/2

```c
double sum();
```
Aproximation to sum of all values added

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
Calculate centroid. [centerX(), centerY()];

```c
double samples(); 
```
Number of samples added

```c
void reset();  
```
Reset values

```c
double meanX();  
```
Mean of variable X

```c
double meanY();  
```
Mean of variable Y

```c
double varX(); 
```
Variance of variable X  

```c
double varY(); 
```
Variance of variable Y  

```c
double stdX();  
```
Standard deviation of variable X  

```c
double stdY();  
```
Standard deviation of variable Y  

```c
double minimumX(); 
```
Minimun value of variable X  

```c
double minimumY(); 
```
Minimun value of variable Y  

```c
double maximumX(); 
```
Maximun value of variable X  

```c
double maximumY(); 
```
Maximun value of variable Y  

```c
double sumX();
```
Aproximation to sum of all values of variable X 

```c
double sumX();
```
Aproximation to sum of all values of variable Y
