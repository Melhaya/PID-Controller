## PID Controller

Given a driving simulator which provides the cross track error (CTE) and the velocity (mph), the goal of this project is to develop a PID controller in c++ that successfully drives the vehicle around the track. In order to navigate the car around the track.

## Tuning

tuning the hyperparameters was the most challenging part in my opinion. I have done manual tuning. Manual tuning is hard but, the process of tuning help us better understand every single effect of PID parameters. The following table summerizes the effect of each parameter on the system.


| Parameter  | Rise Time   | Overshoot  | Settling Time   | Steadystate error  |
|---|---|---|---|---|
| Kp  | Decrease  | Increase  | Small change  | Decrease  |
| Ki  | Decrease  | Increase  | Increase  | Decrease  |
| Kd  | Small change  | Decrease  | Decrease  | No change  |

#### Proportional (P): 
This parameter controls the error proportionally. Increasing the proportional gain has the effect of proportionally increasing the control signal for the same level of error. Setting only P control is agressive and has oscillations.

#### Integral (I): 
This parameter controls the accumulating error. Addition of this term reduces the steady state error. If there is a bias in the system, the integrator builds and builds, thereby increasing the control signal and driving the error down. 

#### Derivative (D): 
This parameter controls the rate of change of error. Addition of this term reduces the oscillary effect in  the system. With derivative control, the control signal can become large if the error begins sloping upward, even while the magnitude of the error is still relatively small. This anticipation tends to add damping to the system, thereby decreasing overshoot.

The following approach is a best to tune manually:

* Set all gains to zero.
* Increase the P gain until the response to a disturbance is steady oscillation.
* Increase the D gain until the the oscillations go away (i.e. it's critically damped).
* Repeat steps 2 and 3 until increasing the D gain does not stop the oscillations.
* Set P and D to the last stable values.
* Increase the I gain until it brings you to the setpoint with the number of oscillations desired.


---
