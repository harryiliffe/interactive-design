#define ttp229 (0xAF>>1)

uint16_t data_out = 0;
uint16_t data1, data2;

bool readWire(int buttonNum, bool *buttonState) {
  Wire.requestFrom(ttp229, 2, true);
  while (Wire.available())
  {
    data1 = Wire.read();
    data2 = Wire.read();
    data_out = (data1 << 8) | data2;
    for (int i = 0; i < buttonNum; i++) {
      buttonState[i] = bitRead(data_out, i);
      Serial.print(buttonState[i]);
    }
    Serial.println();
  }
  return buttonState;
}
