/*
 * If you are familiar with C++, you might be surprised that we don't have any includes here.
 *This is because many libraries required by Arduino are linked by default.
 *
 *Additional libraries such as timers, advanced communication protocols, WiFi libs etc. have to be included.
 * We will see how to do that in later examples. 
 */


//This variable is a "boolean"; it can either be true or false / high or low / 1 or 0 / ON or OFF.
//We use it to store the current status of the LED. Initially we keep the LED OFF.
bool mode = 0;


//This variable is an integer containing the delay between LED toggles, in milliseconds.
int interval = 100;


//This function is executed once, when the board is switched on/reset.
//All initializations, such as I/O pins, Serial port, WiFi etc are done here.
void setup(){

  //Initialize the pin connected to the built-in LED as an output pin.
  pinMode(LED_BUILTIN, OUTPUT);
  
}


//This function is executed continuously, till the controller is switched off/reset.
//The main functionality is present here.
/*
 * In this project, we make the LED present on the board blink at fixed intervals.
 * Your job is to change the intervals at which the LED blinks. Easy, right?
 * 
 * If you are feeling adventurous, try creating blinking patterns.
 */
void loop(){

  /*
   * Main logic of the program:
   *  If the LED is ON, switch it OFF.
   *  else switch it ON.
   *  
   *  Notice the ' ~ ' symbol before HIGH and LOW. It is used to invert logic; i.e., LOW becomes HIGH and vice versa.
   *  This is required because NodeMCU inverts logic internally.
   *  So, the final logic would be HIGH->LOW->HIGH
   *  This is different for different boards. For example, in an Arduino Uno board, the command would simply be:
   *    digitalWrite(LED_BUILTIN, HIGH);
   */
  if(mode==0)
    digitalWrite(LED_BUILTIN, ~HIGH);
  else
    digitalWrite(LED_BUILTIN, ~LOW);

  mode = ~mode;

  //Now, the delay
  delay(interval);
  
}

