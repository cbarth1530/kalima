#include <Wire.h>
#define DS3231_I2C_ADDRESS 0x68
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
const int analogPin = A3;
const int fanRelay = 2;              //relais ventilo MUST BE ON

void setup()
{
  pinMode(fanRelay, OUTPUT);
  digitalWrite(fanRelay, HIGH);
  Wire.begin();
  Serial.begin(9600);
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  setDS3231time(30, 32, 19, 5, 9, 5, 15);
}
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte  dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
void readDS3231time(byte *second,
                    byte *minute,
                    byte *hour,
                    byte *dayOfWeek,
                    byte *dayOfMonth,
                    byte *month,
                    byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

void clearAndHome() 
{ 
Serial.write(27); 
Serial.print("[2J"); // clear screen 
Serial.write(27); // ESC 
Serial.print("[H"); // cursor to home 
} 
//YYYY-MM-DD HH:MM:SS
void displayTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
  // send it to the serial monitor

  Serial.print(year, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(dayOfMonth, DEC);
  Serial.print(" ");
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute < 10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second < 10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  //Serial.print(" ");

}
void loop()
{
   if ( Serial.available() > 0 ) {
    int inByte = Serial.read();
    if (inByte == 'x') {
  displayTime(); // display the real-time clock data on the Serial Monitor,
  int analogValue = analogRead(analogPin); //Co2
  Serial.print(" \t"); //tab
  Serial.print(analogValue);
  Serial.print(" \t"); //tab
  Serial.print("28"); //temo
  Serial.print(" \t"); //tab
  Serial.print("78"); //humidity
  Serial.print(" \t"); //tab
  Serial.print("4.8"); //Ph
  Serial.print(" \t"); //tab
  Serial.println("Bloom"); //Ph
  Serial.flush();
  //clearAndHome();
    }
 
  delay(1000); // every second
}
}



