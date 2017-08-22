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
	
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;

	cte_ = 0;	
	prev_cte_ = 0;
	diff_cte_ = 0;
	int_cte_ = 0;

	p_error_ = 0;
	i_error_ = 0;
	d_error_ = 0;	
	total_error_ = 0;

	return;
}

void PID::UpdateError(double cte) {
	prev_cte_ = cte_;
	cte_ = cte;
	diff_cte_ = cte_ - prev_cte_;
	int_cte_ += cte_; 

	steering_angle_ = - Kp_ * cte_ - Ki_ * diff_cte_ - Kd_ * int_cte_;

	p_error_ = Kp_ * cte_;
	i_error_ = Ki_ * int_cte_;
	d_error_ = Kd_ * (diff_cte_);

	
}

double PID::TotalError() {

	total_error_ = p_error_ + i_error_ + d_error_;
	return total_error_;
}

