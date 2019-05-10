# Encoder_pfc8574
encoder handle for esp8622(maybe for arduino as well)


Example provided. Do not change detecting method on ESP do attachInterrupt in source code if you use I2C OLED, makes issues.
If you do not finish one movement (4 steps) and turn back knob then it will detect oposite side movement. This doesn't happen if you use encoder normally so no need to make library perfect.
