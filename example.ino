Encoder encoder;
void setup()
{
  //void begin(ESP_pfc8574* expanderPtr, uint8_t triggerPinNum, uint8_t PFCPinA, uint8_t PFCPinB, int8_t PFCPinKnob=-1);
  encoder.begin(&expander, D5, 5, 6, 7);//D5 pin on ESP - must be connected to interrupt pin on PFC, 5 & 6 two rotary pins, 7 knob pin - leave -1 if not using
	encoder.onLeft(turnLeft);//void function - will be called when knob turned left
	encoder.onRight(turnRight);
	encoder.onPress(pressEncoder);
}
void loop()
{
	encoder.inLoop();
}
