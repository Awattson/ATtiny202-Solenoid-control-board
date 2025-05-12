void setup() {
  // LEDピンを出力に設定
  pinMode(PIN_PA6, OUTPUT);
  pinMode(PIN_PA7, OUTPUT);

  // 初期状態でLEDを消灯
  digitalWrite(PIN_PA6, LOW);
  digitalWrite(PIN_PA7, LOW);

  // UART初期化（PA0をRXとして使用）
  Serial.begin(9600);  // TXは不要なら未接続でもOK
}

void loop() {
  static bool led6 = false;
  static bool led7 = false;

  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '1':
        led6 = !led6;
        digitalWrite(PIN_PA6, led6);
        break;
      case '2':
        led7 = !led7;
        digitalWrite(PIN_PA7, led7);
        break;
    }
  }

  delay(10); // 軽いデバウンス（不要なら削除可）
}
