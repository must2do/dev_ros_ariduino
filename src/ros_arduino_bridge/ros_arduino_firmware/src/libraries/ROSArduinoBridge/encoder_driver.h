/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
  //below can be changed, but should be PORTD pins; 
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A PD2  //pin 2
  #define LEFT_ENC_PIN_B PD3  //pin 3
  
  //below can be changed, but should be PORTC pins
  #define RIGHT_ENC_PIN_A PC4  //pin A4
  #define RIGHT_ENC_PIN_B PC5   //pin A5
#elif defined ARDUINO_MY_COUNTER
int LEFT_A = 21;//中端口是2
int LEFT_B = 20;//中断口是3
int RIGHT_A =19;
int RIGHT_B =18;
void initEncoders();
void leftEncoderEventA();
void leftEncoderEventB();
void rightEncoderEventA();
void rightEncoderEventB();
#endif
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

