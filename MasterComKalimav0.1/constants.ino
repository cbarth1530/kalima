const int pinFanLed = 2;

const int pinLedPanBack = 4;

const int pinLedRed= 5;
const int pinLedBlue =6;
const int pinLedGreen = 9;
const int pinLedOrange = 10;
const int pinMotor = 12;
const int pinLedAlarm = 13;

const int analogPin = A3;

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

