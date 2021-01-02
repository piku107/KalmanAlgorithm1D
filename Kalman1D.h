#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

// STEP 1 UPDATE
// Kalman Gain calculation
double kalmanGain(double p, double r)
{
	double K = p / (p + r);
	return K;
}

// Estimating the current state
double stateUpdate(double x, double z, double K)
{
	double xn = x + K * (z - x);
	return xn;
}

// Update the current estimate uncertainty
double covUpdate(double K, double p)
{
	double pn = (1 - K) * p;
	return pn;
}


// STEP 2 PREDICT
// predict the next state
double stateExtrapolation(double xn)
{
	double xnext = xn;
	return xnext;
}

// Extrapolated estimate uncertainty
double covExtrapolation(double pn, double q)
{
	double pnext = pn + q;
	return pnext;
}


