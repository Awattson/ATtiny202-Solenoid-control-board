#define lednumber_max 24

byte rcBuf;
byte aData[lednumber_max][3];
byte ledE = lednumber_max - 1;
byte ledS = 0;
byte r,g,b;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);

  pinMode(A7, INPUT);
  delayMicroseconds(500);

  for (byte i=0; i<=ledE; i++){
    aData[i][0]=0;
    aData[i][1]=0;
    aData[i][2]=0;
  }
  sendData();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  getOnebyte(); ledS=rcBuf;
  getOnebyte(); ledE=rcBuf;
  getOnebyte(); r=rcBuf;
  getOnebyte(); g=rcBuf;
  getOnebyte(); b=rcBuf;

  for(byte i=ledS; i<=ledE; i++){
    aData[i][0]=g;
    aData[i][1]=r;
    aData[i][2]=b;
  }

  sendData();
}

void getOnebyte(){
  rcBuf = 0;
  while(digitalRead(A7)==1){}
  delayMicroseconds(156);
  for(byte i=0; i<8; i++){
    if(digitalRead(A7)==1){
      rcBuf=bitSet(rcBuf, i);
    }
    delayMicroseconds(102);
  }
  delayMicroseconds(52);
}

void sendData(){
  noInterrupts();
  for(byte numLed=0; numLed<=ledE; numLed++){
    for(byte rgbLed=0; rgbLed<3; rgbLed++){
      byte a = aData[numLed][rgbLed];
      for(byte i=0; i<8; i++){
        byte hl=a & 0x80;
        if(hl>0){
          PORTA.OUT=PORTA.OUT | B00000010;
          PORTA.OUT=PORTA.OUT | B00000010;
          PORTA.OUT=PORTA.OUT | B00000010;
          PORTA.OUT=PORTA.OUT & B11111101;
        }
        else{
          VPORTA.OUT=VPORTA.OUT | B00000010;
          VPORTA.OUT=VPORTA.OUT | B00000010;
          VPORTA.OUT=VPORTA.OUT | B00000010;
          VPORTA.OUT=VPORTA.OUT | B00000010;
          VPORTA.OUT=VPORTA.OUT | B00000010;
          VPORTA.OUT=VPORTA.OUT & B11111101;
          PORTA.OUT=PORTA.OUT & B11111101;
        }
        a=a*2;
      }
    }
  }
  interrupts();
}
