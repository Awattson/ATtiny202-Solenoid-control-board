void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);

  pinMode(PIN_PA1, OUTPUT);
  pinMode(PIN_PA2, OUTPUT);
  pinMode(PIN_PA3, OUTPUT);
  delay(500);
  
  digitalWrite(PIN_PA1, LOW);
  digitalWrite(PIN_PA2, LOW);
  digitalWrite(PIN_PA3, LOW);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char data = Serial.read();

    switch(data){
      case '0':
        digitalWrite(PIN_PA1, LOW);
        digitalWrite(PIN_PA3, LOW);
        digitalWrite(PIN_PA2, LOW);
        break;
        
      case '1':
        digitalWrite(PIN_PA1, HIGH);
        digitalWrite(PIN_PA3, LOW);
        digitalWrite(PIN_PA2, LOW);
        break;

      case '2':
        digitalWrite(PIN_PA1, LOW);
        digitalWrite(PIN_PA3, HIGH);
        digitalWrite(PIN_PA2, LOW);
        break;

      case '3':
        digitalWrite(PIN_PA1, HIGH);
        digitalWrite(PIN_PA3, HIGH);
        digitalWrite(PIN_PA2, LOW);
        break;

      case '4':
        digitalWrite(PIN_PA1, LOW);
        digitalWrite(PIN_PA3, LOW);
        digitalWrite(PIN_PA2, HIGH);
        break;

      case '5':
        digitalWrite(PIN_PA1, HIGH);
        digitalWrite(PIN_PA3, LOW);
        digitalWrite(PIN_PA2, HIGH);
        break;

      case '6':
        digitalWrite(PIN_PA1, LOW);
        digitalWrite(PIN_PA3, HIGH);
        digitalWrite(PIN_PA2, HIGH);
        break;

      case '7':
        digitalWrite(PIN_PA1, HIGH);
        digitalWrite(PIN_PA3, HIGH);
        digitalWrite(PIN_PA2, HIGH);
        break;

      default:
        //digitalWrite(PIN_PA1, LOW);
        //digitalWrite(PIN_PA2, LOW);
        //digitalWrite(PIN_PA3, LOW);
        break;
    }
    delay(10);
  }
}
