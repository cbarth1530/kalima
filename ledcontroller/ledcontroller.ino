const int greenPin = 5;
const int bluePin = 6;
const int redPin = 9;
const int orangePin = 10;

int currentPin = 0; //current pin to be faded
int brightness = 0; //current brightness level

void setup(){
  Serial.begin(9600);

  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(orangePin, OUTPUT);
}

void loop(){
  //if there's any serial data in the buffer, read a byte
  if( Serial.available() > 0 ){
    int inByte = Serial.read();

      //respond only to the values 'r', 'g', 'b', 'o' or '0' through '9'
      if(inByte == 'r')
        currentPin = redPin;

      if(inByte == 'g')
        currentPin = greenPin;

      if(inByte == 'b')
        currentPin = bluePin;
        
      if(inByte == 'o')
        currentPin = orangePin;

      if(inByte >= '0' && inByte <= '9'){
        //map the incoming byte value to the range of the analogRead() command
        brightness = map(inByte, '0', '9', 0, 255);
        //set the current pin to the current brightness:
        analogWrite(currentPin, brightness);
      }
      Serial.print("Current Pin : ");
      Serial.println(currentPin);

      Serial.print("Brightness : ");
      Serial.println(brightness);

  }//close serial check

}
