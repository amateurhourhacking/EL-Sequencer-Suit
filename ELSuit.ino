#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int ranNum;
int ranDel;

void setup()
{
  Serial.begin(9600); //run serial at 4800 to view info
  irrecv.enableIRIn(); // Start the receiver
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo, 
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);     
  pinMode(13, OUTPUT); 
}

void loop() {
  
  int x,status;
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC); //issue is with hex and its not being
    irrecv.resume(); // Receive the next value
  }
 
  switch(results.value){

//Red Power
  case 2126716663:
  digitalWrite(2, LOW);  // channel A  
  digitalWrite(3, LOW);  // channel B   
  digitalWrite(4, LOW);  // channel C
  digitalWrite(5, LOW);  // channel D    
  digitalWrite(6, LOW);  // channel E
  digitalWrite(7, LOW);  // channel F
  digitalWrite(8, LOW);  // channel G
  digitalWrite(9, LOW);  // channel H
  break;
  
//Source
  case 3238126971:
  digitalWrite(2, HIGH);  // channel A  
  digitalWrite(3, HIGH);  // channel B   
  digitalWrite(4, HIGH);  // channel C
  digitalWrite(5, HIGH);  // channel D    
  digitalWrite(6, HIGH);  // channel E
  digitalWrite(7, HIGH);  // channel F
  digitalWrite(8, HIGH);  // channel G
  digitalWrite(9, HIGH);  // channel H
  break;
  
  
//Green Sound OFF
   case 1535358491:
   for (x=2; x<=9; x++)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

    digitalWrite(10, status);   // blink both status LEDs
    digitalWrite(13, status);
    status = !status; 
  }
     
break;
  
    
//Record
    case 3998141691:
    
    //Generate random number between 8 and 10
    ranNum=random(1,11);
    // Generate random delay time
    ranDel=random(1,20);
    //Turn on the LED
    digitalWrite(ranNum, HIGH);
    delay(ranDel);
    //Turn off the LED
    digitalWrite(ranNum, LOW);  
    break;
    
//CH+
    case 44444: 

  break;
  

//Time Shift
  case 3333:

  break;
  

//VOL-
  case 2222:

  break;
  
//FULL Screen
  case 1111:

  break;
  
//VOL+
  case 55:

  break;
  
//0 
  case 0:

  break;
 
//Ch- 
  case 1234:

  break;
  
//RECALL 
  case 4321:

  break;
 
 
//1
  case 3855596927:
  digitalWrite(1, HIGH);
  break;
  
//2
  case 2721879231:
  digitalWrite(2, HIGH);
  break;

//3
  case 3877748955:
  digitalWrite(3, HIGH);
  break;  
  
//4
  case 4039382595:
  digitalWrite(4, HIGH);
  break;   
  
//5
  case 2538093563:
  digitalWrite(5, HIGH);
  break;  
  
//6
  case 2259740311:
  digitalWrite(6, HIGH);
  break;    
  
//7
  case 2666828831:
  digitalWrite(7, HIGH);
  break;  
  
//8
  case 2747854299:
  digitalWrite(8, HIGH);
  break;

//9
  case 1541889663:
  digitalWrite(9, HIGH);
  break;
  }  
} 
 
 
 
 
 
 
 
 
 
 
