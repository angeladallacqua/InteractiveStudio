int RowOne = 13;
int RowTwo = 12;
int RowThree = 11;
int RowFour = 10;
int RowFive = 9;

int PulseSensorPurplePin = A5; 
int Signal;                


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
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);

   
   if(Signal > 400){    
  digitalWrite(RowOne ,HIGH);
  delay(500);
   }
   else {
    digitalWrite(RowOne ,LOW);
   }


   if (Signal > 500){ 
  digitalWrite(RowTwo ,HIGH);
  delay(1000);
   }
else {
  digitalWrite(RowTwo ,LOW);
}


if (Signal > 600){
  digitalWrite(RowThree ,HIGH);
   delay(2000);
}
else {
   digitalWrite(RowThree ,LOW);
}



if (Signal >700){
  digitalWrite(RowFour ,HIGH);
  delay(3000);
}
else {
  digitalWrite(RowFour ,LOW);
}



if (Signal >800){
  digitalWrite(RowFive ,HIGH);
  delay(200);
}
else {
   digitalWrite(RowFive ,LOW);
}
}
