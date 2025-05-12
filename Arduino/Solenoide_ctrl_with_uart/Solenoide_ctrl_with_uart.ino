void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_PA1, OUTPUT);
  pinMode(PIN_PA2, OUTPUT);
  pinMode(PIN_PA6, OUTPUT);
  pinMode(PIN_PA7, OUTPUT);

  digitalWrite(PIN_PA1, LOW);
  digitalWrite(PIN_PA2, LOW);
  digitalWrite(PIN_PA6, LOW);
  digitalWrite(PIN_PA7, LOW);
  delay(100);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static bool s0 = false;
  static bool s1 = false;
  /*
  if(Serial.available()){
    
    int buf = Serial.read();
    bool state0 = (buf >> 3) & 0x01;
    bool state1 = (buf >> 2) & 0x01;
    bool state2 = (buf >> 1) & 0x01;
    bool state3 = buf & 0x01;

    digitalWrite(PIN_PA1, state0);
    digitalWrite(PIN_PA2, state1);
    digitalWrite(PIN_PA6, state2);
    digitalWrite(PIN_PA7, state3);
    
    char c = Serial.read();
    switch(c){
      case '1':
        digitalWrite(PIN_PA6, s0);
        s0 = !s0;
        break;
      case '2':
        digitalWrite(PIN_PA7, s1);
        s1 = !s1;
        break;
      
    }

    delay(10);
  }*/
  digitalWrite(PIN_PA6, s0);
  digitalWrite(PIN_PA7, s1);
  delay(1000);
  s0 = !s0;
  s1 = !s1;
}
