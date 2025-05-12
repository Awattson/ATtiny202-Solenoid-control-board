void setup() {
  // PORTMUXでUSART0をPA6 (TX) / PA7 (RX) に再割り当て
  //PORTMUX.CTRLB |= PORTMUX_USART0_bm;

  // シリアル初期化（TX: PA6, RX: PA7）
  Serial.begin(9600);

  // 通信準備ができるまで待機
  //while (!mySerial);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();  // 受信
    Serial.write(c);         // エコーバック送信
  }
}
