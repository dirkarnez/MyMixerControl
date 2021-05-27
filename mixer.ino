int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal = 0;
int lastVal1 = 0;
int lastVal2 = 0;
int lastVal3 = 0;
int lastVal4 = 0;
int lastVal5 = 0;
int lastVal6 = 0;

int buttonTen = 2;
boolean state_buttonTen = false;
boolean newstate_buttonTen = false;

void setup()
{
  pinMode(buttonTen, INPUT_PULLUP);
  Serial.begin(9600);       // Set the speed of the midi port to the same as we will be using in the Hairless Midi software
}

void loop()
{ int vul = 0;
  val = analogRead(0) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal - 1) || (val > lastVal + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 4, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal = val;
  }

  val = analogRead(1) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal1 - 1) || (val > lastVal1 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 6, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal1 = val;
  }


  val = analogRead(2) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal2 - 1) || (val > lastVal2 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 9, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal2 = val;
  }

  val = analogRead(3) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal3 - 1) || (val > lastVal3 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 7, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal3 = val;
  }



  val = analogRead(4) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal4 - 1) || (val > lastVal4 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 5, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal4 = val;
  }


  val = analogRead(5) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal5 - 1) || (val > lastVal5 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 8, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal5 = val;
  }

  val = analogRead(6) / 8; // Divide by 8 to get range of 0-127 for midi
  if ((val < lastVal6 - 1) || (val > lastVal6 + 1)) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  { vul = map(val, 0, 127, 127, 0);
    MidiMessage(176, 10, vul);       // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
    lastVal6 = val;
  }

  delay(25);


  if (digitalRead(buttonTen) == HIGH) {
    newstate_buttonTen = false;
  } else {
    newstate_buttonTen = true;
  }

  if (state_buttonTen != newstate_buttonTen) {
    if (digitalRead(buttonTen) == HIGH) { // check button state
      MidiMessage(176, 11, 0);
      state_buttonTen = false;
    } else {
      MidiMessage(176, 11, 1);
      state_buttonTen = true;
    }
  }
}





void MidiMessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
