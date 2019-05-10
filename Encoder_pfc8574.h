#ifndef Encoder_pfc8574_h_
#define Encoder_pfc8574_h_
#include <functional>
#include <G_expander.h>
typedef std::function<void()> callback_t;



class Encoder
{
	public:
	void begin(ESP_pfc8574* expanderPtr, uint8_t triggerPinNum, uint8_t PFCPinA, uint8_t PFCPinB, int8_t PFCPinKnob);
	void onLeft(callback_t onLeft);
	void onRight(callback_t onRight);
	void onPress(callback_t onPress);
	void inLoop();
	private:
	ESP_pfc8574* expander;
	uint8_t triggerPin;
	uint8_t pfcPinA;
	uint8_t pfcPinB;
	int8_t pfcPinKnob;
	callback_t cbLeft;
	callback_t cbRight;
	callback_t cbPress;
};






























#endif
