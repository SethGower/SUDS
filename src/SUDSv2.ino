/*
 * Project SUDSv2
 * Description:
 * Author:
 * Date:
 */

#include <HttpClient.h>
HttpClient http;

http_header_t headers[] = {
  {"Content-Type", "application/json"},
  {"Accept", "*/*"},
  {NULL, NULL}
};

http_request_t request;
http_response_t response;



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

  request.hostname = "127.0.0.1";
  request.port = 5000;
  request.path = "/post";
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  //Serial.printlnf("Brightness: %d, Left: %d, Right: %d", brightness, digitalRead(leftInput), digitalRead(rightInput));

  if (mostRecentLeft != digitalRead(leftInput)) {
    int high = 1, low = 0;
    switch (digitalRead(leftInput)) {
      case HIGH:
        request.body = "{\"left\":\"1}";
        http.post(request, response, headers);

        Serial.print("Application>\tResponse status: ");
        Serial.println(response.status);

        Serial.print("Application>\tHTTP Response Body: ");
        Serial.println(response.body);
        break;
      case LOW:
        request.body = "{\"left\":\"0}";
        http.post(request, response, headers);

        Serial.print("Application>\tResponse status: ");
        Serial.println(response.status);

        Serial.print("Application>\tHTTP Response Body: ");
        Serial.println(response.body);
        break;
    }
    mostRecentLeft = digitalRead(leftInput);
  }

  if (mostRecentRight != digitalRead(rightInput)) {
    Particle.publish("Right Change", digitalRead(rightInput));
    mostRecentRight = digitalRead(rightInput);
  }

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
