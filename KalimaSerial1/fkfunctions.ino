fader(){
 void forfadeup(){
   Serial.print("Fading from :");
   Serial.print(brightness);
   Serial.print("To :");
   Serial.println(target);
  for (int brigthnes = 200; target > brightness; brightness++)  
  analogWrite(ledBlue, brightness);
  analogWrite(ledRed, brightness);
  analogWrite(ledOrange, brightness);
  analogWrite(ledGreen, brightness);
  Serial.print(brightness);
  Serial.print("/");
  Serial.println(target);
} 
}

void forfadeup(){
  for (int brigthnes = 200; target > brightness; brightness++)  
  analogWrite(ledBlue, brightness);
  analogWrite(ledRed, brightness);
  analogWrite(ledOrange, brightness);
  analogWrite(ledGreen, brightness);
  //Serial.println(brightness);
}



void runUp() {
  // call the start:
  //start();

// brighntess = x
// target = y
 
  analogWrite(ledBlue, brightness);
  analogWrite(ledRed, brightness);
  analogWrite(ledOrange, brightness);
  analogWrite(ledGreen, brightness);
  //Serial.println(brightness);

  // change the brightness for next time through the loop:
 if (brightness != target){
  brightness = brightness + fadeAmount;
 }
 if (brightness == target){
      brightness = target;
  }

  // reverse the direction of the fading at the ends of the fade:
 
 if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
    
  }
  // wait for 100 milliseconds to see the dimming effect
  delay(timer);
}

void runDown() {
  // call the start:
 // fadeAmount = -fadeAmount ;
 
  analogWrite(ledBlue, brightness);
  analogWrite(ledRed, brightness);
  analogWrite(ledOrange, brightness);
  analogWrite(ledGreen, brightness);
  Serial.println(brightness);

  // change the brightness for next time through the loop:
 if (brightness != target){
  brightness = brightness + fadeAmount;
 }
 if (brightness == target){
      brightness = target;
  }

  // reverse the direction of the fading at the ends of the fade:
 
 if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
    
  }
  // wait for 100 milliseconds to see the dimming effect
  delay(timer);
}
// Change vars
void set(){
  brightness = brightness;
  //if there's any serial data in the buffer, read a byte
  if( Serial.available() > 0 ){
    int inByte = Serial.read();

      //respond only to the values 'r', 'g', 'b', 'o' or '0' through '9'
      if(inByte == 'r')
        currentPin = ledRed;

      if(inByte == 'g')
        currentPin = ledGreen;

      if(inByte == 'b')
        currentPin = ledBlue;
        
      if(inByte == 'o')
        currentPin = ledOrange;

      if(inByte >= '0' && inByte <= '9'){
        //map the incoming byte value to the range of the analogRead() command
        brightness = map(inByte, '0', '9', 0, 255);
        //set the current pin to the current brightness:
        //analogWrite(currentPin, brightness);
        target = brightness;
      }
      Serial.print("New Target : ");
      //Serial.println(currentPin);

      Serial.print("target : ");
      Serial.println(brightness);
      //run()

  }//close serial check

}
