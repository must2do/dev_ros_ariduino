/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef TB6612_MOTOR_DRIVER
  #define PWMR  3
  #define RIN1  9
  #define RIN2  8
  #define STBY  10
  #define PWML  5
  #define LIN1  6
  #define LIN2  7
  #define LED   13
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
