
#include "Encoder_pfc8574.h"

void Encoder::begin(ESP_pfc8574* expanderPtr, uint8_t triggerPinNum, uint8_t PFCPinA, uint8_t PFCPinB, int8_t PFCPinKnob=-1)
{
	
	expander=expanderPtr;
	triggerPin=triggerPinNum;
	pfcPinA=PFCPinA;
	pfcPinB=PFCPinB;
	pfcPinKnob=PFCPinKnob;
	pinMode(triggerPinNum,INPUT_PULLUP);
}
void Encoder::onLeft(callback_t onLeft)
{
	cbLeft=onLeft;
}
void Encoder::onRight(callback_t onRight)
{
	cbRight=onRight;
}
void Encoder::onPress(callback_t onPress)
{
	cbPress=onPress;
}
void Encoder::inLoop()
{
	static unsigned long int lastCheck=0,milis;
	milis=millis();
	static uint8_t lastByte=0b11111111;
	if((digitalRead(triggerPin)==LOW) && ((lastCheck+40<milis) || (milis<lastCheck)))
	{
		uint8_t byte=expander->getByte();
		//Serial.print((byte & (1<<7))!=0);
		//Serial.print((lastByte & (1<<7))==0);
		if(((byte & (1<<pfcPinKnob)) != 0) && ((lastByte & (1<<pfcPinKnob))==0) && pfcPinKnob>-1)//knob released
		{
			cbPress();
		}		
		if(((byte & (1<<pfcPinA)) != 0) &&((byte & (1<<pfcPinB))!=0) )
		{
			if(((lastByte & (1<<pfcPinA)) != 0) && ((lastByte & (1<<pfcPinB)) == 0))
			{
				cbLeft();
			}
			else if (((lastByte & (1<<pfcPinA)) == 0) && ((lastByte & (1<<pfcPinB)) != 0))
			{
				cbRight();
			}
			
		}
		lastByte=byte;
		
	}
}
