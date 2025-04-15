If one side of the crawler stops due to a motor fault or gear jam, the robot will experience unbalanced motion, where only one of the track will continue to move. This uneven movement will cause the robot to either rotate towards the stationary side, or will experience lack of power to continue motion.

This would cause the center of mass of robot to shift sideways which would disrupt robot's stability. Uneven traction from the tracks would eventually result in a fall due to lack of balance. If enough power is supplied to the motor drivers, the robot will rotate about the stationary side and would eventually be stuck between the stairs or fall off, making it unable to follow its climbing path. The robot has a high risk of tipping over backwards in this situation, unless it aligns with the stairs and is able to fit into the stair gap.

Motor or mechanical faults can be identified by combining real-time control monitoring with sensor feedback. 
A motor encoder provides feedback about the rotation of motor shaft. If the encoder gives zero RPM while still being powered, this indicates mechanical fault and corrective measures can be implemented to avoid damage.
The IMU sensor continuously tracks the robot's orientation. In the case of mechanical failure, the robot might go beyond the specified threshold which can be detected with the help of IMU sensor.

One of Safety strategies that can be implemented to prevent robot from tipping can be to halt its motion if motor encoder detects 0 RPM for any of the motors. This way the robot would not veer off its course, and would smoothly slide down the stairs without any major damage. 
If the IMU sensor readings denote unbalanced orientation, the robot can initiate certain corrective actions like accelerate or decelerate the robot to maintain balance.
