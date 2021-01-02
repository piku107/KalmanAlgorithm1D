#include "Kalman1D.h"

int main()
{
	
	// 1D kalman
	// Simple example numerical problem
	// VARIABLES

	double q = 0.0001;
	double sd = 0.1;

	vector <double> x (10);
	vector <double> z{ 49.95, 49.967,50.1, 50.106, 49.992, 49.819, 49.933, 50.007, 50.023, 49.99 };
	vector <double> p (10);
	vector <double> k (10);
	vector <double> xExp (10);
	vector <double> pExp (10);
	
	double r, xn, pn;

	// INITIALIZATION
	r = sd * sd;
	xExp[0] = 10;
	p[0] = 100 * 100;
	pExp[0] = p[0] + q;

	//Function calls
	for (int i = 0; i < 10; i++)
	{
		//Update
		k[i] = kalmanGain(pExp[i], r);
		x[i] = stateUpdate(xExp[i], z[i], k[i]);
		p[i] = covUpdate(k[i], pExp[i]);

		//Predict
		xExp[i + 1] = stateExtrapolation(x[i]);
		pExp[i + 1] = covExtrapolation(p[i], q);
	}

	for (int j = 0; j < 10; j++)
	{
		cout << "Iteration Number: " << j << endl;
		cout << endl;
		cout << "Z: " << z[j] << endl;
		cout << "Kalman Gain: " << k[j] << endl;
		cout << "State Update: " << x[j] << endl;
		cout << "Covariance Update: " << p[j] << endl;
		cout << "State Extraploation: " << xExp[j] << endl;
		cout << "Covariance Exptrapolation: " << pExp[j] << endl;
		cout << endl;
	}



	return 0;
	/*
	cout << "Hello Piki" << endl;
	cout << "Sum: " << sum(2, 3) << endl;
	cout << "Kalman: " << stateUpdate(1.1, 2.2, 1.3) << endl;

	MatrixXd A(2, 2);
	MatrixXd B = MatrixXd::Constant(3, 3, 1.2);

	//A(0, 0) = 2.2;
	//A(0, 1) = 1.2;
	//A(1, 0) = 3;
	//A(1, 1) = 5.093939920292920332093230239932032932939203929929101939121;

	A = MatrixXd::Random(2, 2);


	cout << "A: " << A << endl;
	cout << "A * A: " << A*A << endl;
	cout << "B: " << B << endl;
	cout << "A + B: " << A + B << endl;
	*/
}