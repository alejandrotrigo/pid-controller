#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Twiddle() {

}

void PID::Init(double Kp, double Ki, double Kd) {
	
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;


	p_error = 0;
	i_error = 0;
	d_error = 0;	
	total_error = 0;
	
	step = 0;
	dp = {Kp*0.1}, Ki*0.1, Kd*0.1};
	best_error = std::numeric_limits<double>::max();

	return;
}

void PID::UpdateError(double cte) {
	
	d_error = cte - p_error; 
	p_error = cte;
	i_error += cte;

	
}

double PID::TotalError() {

	total_error = Kp*p_error + Ki*i_error + Kd*d_error;
	return total_error;
}

void PID::twiddle() {
	
	if (total_error < best_error) {
		total_error = best_error;
		dp[step] *= 1.1;
	}else{
		
	}
}
