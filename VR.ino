class Object {
protected:
  String type;
  bool state;

public:
  Object(String objectType) {
    type = objectType;
    state = false;
  }

  virtual void turnOn() {
    state = true;
  }

  virtual void turnOff() {
    state = false;
  }

  bool getState() {
    return state;
  }

  String getType() {
    return type;
  }
};

class Light : public Object {
public:
  Light() : Object("Light") {}

  void turnOn() {
    // Additional code to turn on the light
    state = true;
  }

  void turnOff() {
    // Additional code to turn off the light
    state = false;
  }
};

class Fan : public Object {
public:
  Fan() : Object("Fan") {}

  void turnOn() {
    // Additional code to turn on the fan
    state = true;
  }

  void turnOff() {
    // Additional code to turn off the fan
    state = false;
  }
};

class Door : public Object {
public:
  Door() : Object("Door") {}

  void turnOn() {
    // Additional code to open the door
    state = true;
  }

  void turnOff() {
    // Additional code to close the door
    state = false;
  }
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    // Set pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available()){

  }
  ImplementMessage(Serial.readString());
}

bool ImplementMessage(String m){
  char name = m[0];
  int number = m.substring(2).toInt();
  bool state = m.substring(4).toInt();
  switch(name){
    case 'D':
      digitalWrite(13, state);
      break;
    case 'L':
      analogWrite(3, state ? 50 : 0);
    default:
      return false;
  }
  
  return true;
} 