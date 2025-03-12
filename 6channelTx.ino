 //NISHANT RANA ROVER 6 CHANNEL TRANSMITTER 
 //29-08-2023 
 #include <SPI.h>
 #include <RF24.h>
 #include <nRF24L01.h>                    // include RF24 libraries
 #define leftButton 4
 #define rightButton 2
 RF24 radio(9, 10);                      // CE, CSN
 const uint64_t pipe = 0xE8E8F0F0E1LL;   // set channel
 // const byte address[6] = "00001";     // also sets channel
    int l1Pin = A0;                       // integer for joystick, x axis, analog pin A0
   int l2Pin = A1;                       // integer for joystick, y axis, analog pin A5
   int r1Pin= A2;
   int r2Pin = A3;
   int left_switch;               
   int right_switch; 
   int data[8];                         // forming datagroup, 8 bits is enough for car 
   
  //////////////////////////////////////////////////////////////////////////////
   
  void setup() {
   
   Serial.begin(9600);                  // start serial monitor for debugging
    pinMode(leftButton, INPUT_PULLUP);
   pinMode(rightButton,INPUT_PULLUP);
 
   radio.begin();                       // start radio
   radio.openWritingPipe(pipe);         // this is the controller
   radio.setPALevel(RF24_PA_HIGH);      // High power
   radio.setDataRate(RF24_250KBPS);     // data rate 250 kb/s
   radio.stopListening();               // stops listening to transmit
 
   }
 
  /////////////////////////////////////////////////////////////////////////////
 
  void loop() {                     
 
   l1Pin = analogRead(A0);                     // read x pin from joystick 
   l2Pin = analogRead(A1);                    //  read y pin from joystick 
   r1Pin = analogRead(A2);
   r2Pin =  analogRead(A3);
   left_switch=digitalRead(4);
   right_switch=digitalRead(2);
   data[0] = l1Pin;                 // defines xPin which is A0 as data
   data[1] = l2Pin;                // defines yPin which is A1 as data
   data[2] = r1Pin;
   data[3] = r2Pin;
   data[4] = left_switch;
   data[5] = right_switch;
   radio.write(&data, sizeof(data));          // write 8 bits of data to receiver
                                              // no mapping required for transmitter                       
 
  
   Serial.print("l1:");          // text for debugging 
   Serial.print(data[0]);    // prints data  notice this value is print line
   Serial.print("l2:");        //print the values with to plot or view
   Serial.print(data[1]);     // prints the next piece of data 
   Serial.print("\t");
   Serial.print("r1:");
   Serial.print(data[2]);
   Serial.print("r2:");
   Serial.print(data[3]);
   Serial.print(" switch1:");
   Serial.print(data[4]);
   Serial.print(" switch2:");
   Serial.print(data[5]);
   Serial.println();
 }
