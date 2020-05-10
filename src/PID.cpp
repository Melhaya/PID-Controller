#include "PID.h"
#include <algorithm>

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors)
   */
  
  // PID coefficients
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  // Errors initialized
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  //previous CTE
  prev_cte = 0.0;

  //Sum of all observed CTEs
  sum_cte = 0.0;

  // Initial error values for comparison with the cte
  minError = std::numeric_limits<double>::max();
  maxError = std::numeric_limits<double>::min();

}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */

    // Proportional error.
    p_error = cte;

    // Integral error.
    i_error += cte;

    // Diferential error.
    d_error = cte - prev_cte;
    prev_cte = cte;

    sum_cte+=cte;

    if ( cte > maxError ) {
      maxError = cte;
    }
    if ( cte < minError ) {
      minError = cte;
    }
  
  }

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */


  return p_error * Kp + i_error * Ki + d_error * Kd;
}
