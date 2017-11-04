/*
 * Project SUDSv2
 * Description:
 * Author:
 * Date:
 */

//prototypes
int adjustBrightness(String command);

//Pins
  //Output
int led = D1;
  //Input
int leftInput = D3;
int rightInput = D2;

//variables
int brightness = 100;

int mostRecentRight;
int mostRecentLeft;

// setup() runs once, when the device is first turned on.
void setup() {
  Particle.function("brightness", adjustBrightness);

  Serial.begin(9600);
  Serial.println("Hello Serial!");

  pinMode(led, OUTPUT);
  pinMode(leftInput, INPUT);
  pinMode(rightInput, INPUT);

  analogWrite(led, brightness);

  mostRecentLeft = digitalRead(leftInput);
  mostRecentRight = digitalRead(rightInput);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  Serial.printlnf("Brightness: %d, Left: %d, Right: %d", brightness, digitalRead(leftInput), digitalRead(rightInput));

  /*if (mostRecentLeft != digitalRead(leftInput)) {
    //Particle.publish("Left Change", digitalRead(leftInput));
    Serial.printf("Left Change: %d, ", digitalRead(leftInput));
    mostRecentLeft = digitalRead(leftInput);
    Serial.printlnf("New Left is: %d", digitalRead(leftInput));
  }

  if (mostRecentRight != digitalRead(rightInput)) {
    //Particle.publish("Right Change", digitalRead(rightInput));
    mostRecentRight = digitalRead(rightInput);
  }*/

  delay(500);
}

int adjustBrightness(String command){
  Serial.println(command);
  if (brightness == command.toInt()) {
    return 0;
  }else{
    brightness = command.toInt();
    analogWrite(led, brightness);
    return 1;
  }
}
