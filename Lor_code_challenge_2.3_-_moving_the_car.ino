#include <Servo.h>
Servo servo;

#define motor1Control 5    //right wheel
#define motor2Control 7     // left wheel
#define motor1ControlR 4   //right wheel reverse.
#define motor2ControlR 6   // left wheel reverse
#define motor1Speed 11      //right wheel speed
#define motor2Speed 10      // left wheel speed


//define global variables
int maxSpeed = 255;
int maxSpeed2= 255;
int angle = 0;
int angle0 = 180;
int angle1 = 0;
// this character represents the data received from the app
char remote;


char bluetooth() {
  char message;
  if (Serial.available() > 0) {message = Serial.read();
    return message;}
  else return remote;
}


//class that controls car movement (left,right,forward,backward,stop)
class CarMove {

  public:
    void right() {
      analogWrite(motor1Speed, maxSpeed);
      analogWrite(motor2Speed, maxSpeed2);
      digitalWrite(motor1ControlR, LOW);
      digitalWrite(motor2ControlR, HIGH);
      digitalWrite(motor1Control, HIGH);
      digitalWrite(motor2Control, LOW);
    }

    void left() {
      analogWrite(motor1Speed, maxSpeed);
      analogWrite(motor2Speed, maxSpeed2);
      digitalWrite(motor1ControlR, HIGH);
      digitalWrite(motor2ControlR, LOW);
      digitalWrite(motor1Control, LOW);
      digitalWrite(motor2Control, HIGH);
    }

    void forward() {
      analogWrite(motor1Speed, maxSpeed);
      analogWrite(motor2Speed, maxSpeed2);
      digitalWrite(motor1ControlR, LOW);
      digitalWrite(motor2ControlR, LOW);
      digitalWrite(motor1Control, HIGH);
      digitalWrite(motor2Control, HIGH);
    }/*
    void forward() {
      analogWrite(motor1Speed, maxSpeed);
      analogWrite(motor2Speed, maxSpeed2);
      digitalWrite(motor1ControlR, LOW);
      digitalWrite(motor2ControlR, HIGH);
      digitalWrite(motor1Control, HIGH);
      digitalWrite(motor2Control, LOW);
    }*/

    void backward() {
      analogWrite(motor1Speed, maxSpeed);
      analogWrite(motor2Speed, maxSpeed2);
      digitalWrite(motor1ControlR, HIGH);
      digitalWrite(motor2ControlR, HIGH);
      digitalWrite(motor1Control, LOW);
      digitalWrite(motor2Control, LOW);
      //Serial.println("backward");
    }

    void stop() { 
    //check for previous stage then go opposite direction then stops
      analogWrite(motor2Speed, 255);
      analogWrite(motor1Speed, 255);
      digitalWrite(motor1ControlR, LOW);
      digitalWrite(motor2ControlR, LOW);
      digitalWrite(motor1Control, LOW);
      digitalWrite(motor2Control, LOW);
    }
};


CarMove car;


void setup() {
  pinMode(motor1Control,OUTPUT);   //left motors forward
  pinMode(motor1ControlR,OUTPUT);   //left motors reverse
  pinMode(motor2Control,OUTPUT);   //right motors forward
  pinMode(motor2ControlR,OUTPUT);   //right motors reverse
  pinMode(13,OUTPUT); //bluetooth power ig
  digitalWrite(13,HIGH);
  Serial.begin(9600);   // here we initialize the seriel panel
  servo.attach(9);
  servo.write(0);
  car.stop();
}

void loop(){
  remote= bluetooth();
  car.backward();
  
  /*
  switch (remote){
    case 'f' :
     car.forward();
     Serial.println(remote);
     break;
    case 'b' :
     car.backward();
     Serial.println(remote);
     break;
    case 'r' :
     car.right();
     Serial.println(remote);
     break;
    case 'l': 
     car.left();
     Serial.println(remote);
     break;
    case 's' :
     car.stop();
     Serial.println(remote);
     break;
    case'o' :
     servo.write(angle0);
     break;
    case'c' :
     servo.write(angle1);
     break;
    default:
     car.stop();
     break;
    }*/
  }
