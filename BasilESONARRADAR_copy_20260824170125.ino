// including the servo library and initilaizng all of my varables to their locations r, g, b stand for redLed, greenLed, Blueled, Bzr stands for buzzer
// dist = distance (for one way) and dur is just a varible for the calculation of distance
#include <Servo.h>
Servo myservo;
int echo = 7;
int trig = 8;
int bzr = 10;
int r = 4;
int g = 5;
int b = 3;
float dist;
long dur;



void setup() {

  // Configuring the Pins and components && preparing the Servo pin
  myservo.attach(11);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(bzr, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Adding a quick serial to debug
  //Serial.begin(9600);
}

void loop() {
  // Actual logic that checks the 3 levels of distances and sets colours (and sound) to each. since i dont have a passive buzzer i cant use the Tone() function
  // As a quick substitue i will beep if its meduim ditance and hold if its too close
  // three ranges will be >=100 , 99 <= distance >= 50, distance < 50.

  // Starting a quick sweep with the servo (can only do 180 degree)
  // this one go from 0 degrees to 180

  for (int k = 0; k < 180; k++) {
      myservo.write(k);
      delay(5);

    // Ensuring that every state is low and shooting sound to sense distance of stuff
    digitalWrite(bzr, LOW);
    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    dur = pulseIn(echo, HIGH,30000);
    dist = dur * 0.017;

      // 3 idential loop that change colour and buzzing by distance
      if (dist >= 100) {
        digitalWrite(g, HIGH);
        digitalWrite(r, LOW);
        digitalWrite(b, LOW);
        // Serial.println("We are above 99 cm ");
      }

      else if (99 >= dist && dist >= 15) {
        digitalWrite(g, HIGH);
        digitalWrite(r, HIGH);
        digitalWrite(b, LOW);
        // not really as effective as a passive buzzer but will do the job for now;
        digitalWrite(bzr, HIGH);
        delay(10);
        digitalWrite(bzr, LOW);
        //Serial.println("We are  between 15 and 99 cm ");

      }

      else  {
        digitalWrite(g, LOW);
        digitalWrite(r, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(bzr, HIGH);
        delay(1000);
        // dont need the serial print anymore
        // Serial.println("We are below 15! cm ");
      }
    } // this one goes back from 180 to 0
  for (int j = 180; j >= 0; j--) {
        myservo.write(j);
        delay(5);
      // Ensuring that every state is low and shooting sound to sense distance of stuff
    digitalWrite(bzr, LOW);
    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    dur = pulseIn(echo, HIGH, 30000);
    dist = dur * 0.017;
 

        // 3 idential loop that change colour and buzzing by distance
        if (dist >= 100) {
          digitalWrite(g, HIGH);
          digitalWrite(r, LOW);
          digitalWrite(b, LOW);
          delay(10);
          // Serial.println("We are above 99 cm ");
        }

        else if (99 >= dist && dist >= 15) {
          digitalWrite(g, HIGH);
          digitalWrite(r, HIGH);
          digitalWrite(b, LOW);
          // not really as effective as a passive buzzer but will do the job for now;
          digitalWrite(bzr, HIGH);
          delay(10);
          digitalWrite(bzr, LOW);
          //Serial.println("We are  between 15 and 99 cm ");

        }

        else  {
          digitalWrite(g, LOW);
          digitalWrite(r, HIGH);
          digitalWrite(b, LOW);
          digitalWrite(bzr, HIGH);
          delay(1000);
          // dont need the serial print anymore
          // Serial.println("We are below 15! cm ");
        }
    }
}