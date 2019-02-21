#include<ESP8266WiFi.h>
#include<WiFiClient.h>

WiFiClient client;

//The port we shall connect to. This depends on your server script.
const int port=8000;


//This is your host name. You can use you server's IP address here.
const char* host = "192.168.43.253";

//REST API GET Request parameters
String url="/url?";

//The response sent by the server will be stored here.
String response = "";


//Removes the HTTP Response headers from the received response.
void removeHeader(String &input){
  int index = input.lastIndexOf("\r\n\r\n");
  input = input.substring(index);
}

String addHeader(String h, String u){
  return ("GET " + u + " HTTP/1.1\r\n"
          + "Host: " + h + "\r\n\r\n");
}

void setup() {
  Serial.begin(9600);
  WiFi.begin("POCO PHONE","12354678");
  delay(1000);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
  Serial.println(WiFi.localIP());
  delay(100);
}

// the loop function runs over and over again forever
void loop() {

  char *vals = new char[2];
  Serial.print("Enter two 1-digit numbers, separated by comma (eg. '5,6')");
  while(!Serial.available());

  Serial.readBytes(vals, 3);
  String turl = url+"val1="+vals[0]+"&val2="+vals[2];
  
  while(!client.connect(host, port)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");



  
  client.print(addHeader(host, turl));
  
  while(!client.available());

  
  response = client.readString();
  removeHeader(response);

  Serial.println(response+"\n\nRestarting in 5 sec...");
  delay(5000);

  Serial.flush();
  
}
