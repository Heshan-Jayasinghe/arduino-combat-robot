int CH4;
int CH2;
int RXpins[]={2,3,4,5}; //[1,2,3,4]
int RXval[]={0,0,0,0};
void setup() {
  Serial.begin(115200);
  for(int x=0;x<4;x++){
    pinMode(RXpins[x],INPUT);
  }
  for(int m=6;m<12;m++){
    pinMode(m,OUTPUT);
  }

}

void loop() {
  RXval[1]=map(pulseIn(RXpins[1],HIGH),1200,1800,255,-255);//CH2
  RXval[3]=map(pulseIn(RXpins[3],HIGH),990,1990,-255,255);//CH4
 // Serial.println(RXval[1]);delay(500);
  if(RXval[1]>-10 && RXval[1]<2){
  CH2=1;
}
if(RXval[3]>9 && RXval[1]<16){
   CH4=1;
}
if(CH2==1 && CH4==1){
    analogWrite(10,0);
    analogWrite(11,0);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
}

 if(RXval[1]<-100 && CH4==1 ){
    //Serial.print("goforward");
    analogWrite(10,250);
    analogWrite(11,250);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
  }
  else if 
  (RXval[1]>1100){
    //Serial.print("OFF");
    analogWrite(10,0);
    analogWrite(11,0);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  else if(RXval[1]>100 && CH4==1){
    //Serial.println("goBack");
    analogWrite(10,250);
    analogWrite(11,250);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(9,HIGH);
  }

  if(RXval[3]<-700){
   //Serial.print("Stop");
    analogWrite(10,0);
    analogWrite(11,0);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }else if(RXval[3]<-115 && CH2==1){
    //Serial.println("turnLeft");
    analogWrite(10,250);
    analogWrite(11,250);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }else if(RXval[3]>150 && CH2==1){
    //Serial.println("turnRight");
    analogWrite(10,250);
    analogWrite(11,250);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
  }
}
