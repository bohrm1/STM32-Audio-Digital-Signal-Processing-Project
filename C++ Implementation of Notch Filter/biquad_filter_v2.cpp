#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

// struct to hold filter states and coeffs  
typedef struct 
{
    double a1, a2;
    double b0, b1, b2;
    double z1,z2; 
}biquad_dbl_t;

// filter prototype, accepts one input and produces one output
double biquad_dbl(double xm, biquad_dbl_t* bq)
{
    double ym = bq->b0*xm + bq->z1;
    bq->z1 = bq->b1*xm + bq->a1*ym + bq->z2;
    bq->z2 = bq->b2*xm + bq->a2*ym;
    return ym;
}

int main() 
{
    FILE *fp; 
    fp = fopen("out3.csv", "w");             // writing to out.csv 
    const int f0 = 3000;                    // cosine frequency
    const int Fs = 32000;                   // sampling frequency
    double alpha = 0.90;

    const double PI = 3.14159;  
    const double filter_omega = PI/8;       // notch filter frequency (=3000Hz if Fs = 48000Hz)    
    const int sig_len = 200;                // num samples

    double x[sig_len];                      // input vector
    double y[sig_len];                      // vector to hold filter output

    biquad_dbl_t filter1; 
    filter1.a1 = 2*alpha*cos(filter_omega);               
    filter1.a2 = -1*pow(alpha,2);
    filter1.b0 = 1;
    filter1.b1 = -2 * cos(filter_omega);
    filter1.b2 = 1;

    // computing output sequence
    for (int i=0; i<sig_len-1; i++) 
    {
        x[i] = cos(2*PI*((double)f0/Fs)*i);
        y[i] = biquad_dbl(x[i], &filter1);
        fprintf(fp, "%10.8f,%f\n", x[i], y[i]);
    }
    fclose(fp);
}