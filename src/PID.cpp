#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
	if (steer < -1) {
    	steer = -1;
 	}
 	if (steer > 1) {
    	steer = 1;
  	}
  	return steer;
}

