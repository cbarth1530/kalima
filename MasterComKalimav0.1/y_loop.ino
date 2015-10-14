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
