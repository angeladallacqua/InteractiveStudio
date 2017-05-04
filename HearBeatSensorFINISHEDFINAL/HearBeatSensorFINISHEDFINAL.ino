int RowOne = 10; 
int RowTwo = 9;
int RowThree = 6;
int RowFour = 5;
int RowFive = 3; 

int PulseSensorPurplePin = A5; 
int Signal;                

int timer; 

int brightness = 0;
int fadeAmount = 5;

void setup() {
  Serial.begin(9600);
  pinMode(RowOne, OUTPUT);
  pinMode(RowTwo, OUTPUT);
  pinMode(RowThree, OUTPUT);
  pinMode(RowFour, OUTPUT);
  pinMode(RowFive, OUTPUT);
              }

void loop() {
    Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value. 
    Serial.println(Signal);// Assign this value to the "Signal" variable.

///////ROW ONE (blue and yellow)
    if(Signal > 300 && Signal < 399){    
    digitalWrite(RowOne ,HIGH);
    delay(100);
         }
    else {
    digitalWrite(RowOne ,LOW);
    Serial.println(RowOne);
          }

///////ROW TWO (pink and purple)
   if (Signal > 400 && Signal < 499){ 
   digitalWrite(RowTwo ,HIGH);
   delay(250);
         }
    else {
    digitalWrite(RowTwo ,LOW);
    Serial.println("Signal");
         }

///////ROW THREE (middle)
    if (Signal > 500 && Signal < 599){
    digitalWrite(RowThree ,HIGH);
   delay(400);
          }
     else {
     digitalWrite(RowThree ,LOW);
          }

///////ROW FOUR (pink and purple)
    if (Signal >600 && Signal < 699){
    digitalWrite(RowFour ,HIGH);
    delay(550);
         }
    else {
    digitalWrite(RowFour ,LOW);
         }

///////ROW FIVE (blue and yellow)
   if (Signal >800 && Signal < 899){
   digitalWrite(RowFive ,HIGH);
   delay(700);
         }
    else {
   digitalWrite(RowFive ,LOW);
          }

/////////////////////////////////// Meditation Heartbeat 
    if (Signal < 150){
    analogWrite(RowOne,brightness);
    analogWrite(RowTwo, brightness);
    analogWrite(RowThree, brightness);
    analogWrite(RowFour, brightness);
    analogWrite(RowFive, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
                  }
                   delay(50);
         }

/////////////////////////////////// Running Heartbeat 
    
     if (Signal > 1000){
    digitalWrite(RowOne,LOW);
    delay(90);
    digitalWrite(RowOne,HIGH);
    
    digitalWrite(RowTwo,LOW);
    delay(90);
    digitalWrite(RowTwo,HIGH);
  
    digitalWrite(RowThree,LOW);
    delay(90);
    digitalWrite(RowThree,HIGH);
  
    digitalWrite(RowFive,LOW);
    delay(90);
    digitalWrite(RowFive,HIGH);
  }
  
          


  } ///the end bracket
