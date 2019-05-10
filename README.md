# Encoder_pfc8574
encoder handle for esp8622(maybe for arduino as well)




Encoder encoder;
void setup()
{
  //void begin(ESP_pfc8574* expanderPtr, uint8_t triggerPinNum, uint8_t PFCPinA, uint8_t PFCPinB, int8_t PFCPinKnob=-1);
  encoder.begin(&expander, D5, 5, 6, 7);//D5 pin on ESP - must be connected to interrupt pin od PFC
	encoder.onLeft(turnLeft);//void function - will be called when knob turned left
	encoder.onRight(turnRight);
	encoder.onPress(pressEncoder);
}
void loop()
{
	encoder.inLoop();
}
