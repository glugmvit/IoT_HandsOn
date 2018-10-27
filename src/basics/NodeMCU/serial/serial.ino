
/*
 * We are still sticking to default arduino libraries here.
 * So, no includes required :)
 */

/*
 * The Serial Port is plays a major role in Arduino, and in all embedded systems in general.
 * There are several types of Serial Communication. For example, we have:
 *    UART
 *    USART
 *    SPI
 *    I2C
 *    USB 
 *    
 * In most cases, we will be using UART, since it is the most basic and very easy to use.
 * Arduino provides a rich set of libraries for this purpose, all under an object called "Serial"
 * 
 * This is often used for displaying data on the Arduino Serial Monitor (Tools > Serial Monitor)
 */


 //Initialize UART communications
 void setup(){

    Serial.begin(9600);         //9600 is the number of bits transferred per second. It is also known as BAUD rate.
    Serial.print("Hello World");
    
 }


//Nothing to loop here!
void loop(){
  
}

