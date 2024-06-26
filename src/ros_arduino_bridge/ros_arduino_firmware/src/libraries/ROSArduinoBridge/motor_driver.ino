/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#ifdef POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined TB6612_MOTOR_DRIVER
  void initMotorController() {
    pinMode(PWMR,OUTPUT);
    pinMode(RIN1,OUTPUT);
    pinMode(RIN2,OUTPUT);
    pinMode(PWML,OUTPUT);
    pinMode(LIN1,OUTPUT);
    pinMode(LIN2,OUTPUT);
    pinMode(STBY,OUTPUT);
    pinMode(LED,OUTPUT);
    digitalWrite(STBY,HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      if(reverse == 0) { //l电机正转
        digitalWrite(LIN1,HIGH);
        digitalWrite(LIN2,LOW); 
      }
      else if (reverse == 1) { //l电机反转
        digitalWrite(LIN1,LOW);
        digitalWrite(LIN2,HIGH); 
        }
      analogWrite(PWML,spd);
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      if(reverse == 0) { //r电机正转       
        digitalWrite(RIN1,HIGH);
        digitalWrite(RIN2,LOW); 
        }
      else if (reverse == 1) { //r电机反转
        digitalWrite(RIN1,LOW);
        digitalWrite(RIN2,HIGH);
        }
      analogWrite(PWMR,spd);
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif
