void setup(){
    Serial.begin(9600);
    pinMode(A2, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

int ldr_btn=2;
int laser_btn=4;
int s1=7,s2=8,s3=12;
int buzzer=13;
int led=A2;
int ldr=A5;
int ldr_val=0;
char input;
bool pin_ldr_btn=false;
bool pin_laser_btn=false;
bool pin_s1=false;
bool pin_s2=false;
bool pin_s3=false;
bool pin_buzzer=false;
bool pin_led=false;
bool pin_ldr=false;

void loop(){
  input = Serial.read();
  if(input == '1'){
    if (pin_s1==false){
      digitalWrite(s1, HIGH);
      pin_s1=true;
    }
  }
  else if(input == '2'){
    if (pin_s2==false){
      digitalWrite(s2, HIGH);
      pin_s2=true;
    }
  }
  else if(input == '3'){
    if (pin_s3==false){
      digitalWrite(s3, HIGH);
      pin_s3=true;
    }
  }
  else if(input == '4'){
    if (pin_s1==false){
      digitalWrite(s1, HIGH);
      pin_s1=true;
    }
    if (pin_s2==false){
      digitalWrite(s2, HIGH);
      pin_s2=true;
    }
    if (pin_s3==false){
      digitalWrite(s3, HIGH);
      pin_s3=true;
    }
  }
  else if(input == '5'){
    if (pin_s1==true){
      digitalWrite(s1, LOW);
      pin_s1=false;
    }
    if (pin_s2==true){
      digitalWrite(s2, LOW);
      pin_s2=false;
    }
    if (pin_s3==true){
      digitalWrite(s3, LOW);
      pin_s3=false;
    }
  }
  else if(input == 'a'){
    if (pin_s1==true){
      digitalWrite(s1, LOW);
      pin_s1=false;
    }
  }
  else if(input == 'b'){
    if (pin_s2==true){
      digitalWrite(s2, LOW);
      pin_s2=false;
    }
  }
  else if(input == 'c'){
    if (pin_s3==true){
      digitalWrite(s3, LOW);
      pin_s3=false;
    }
  }
  else if(input == 'd'){
    if (pin_led==true && pin_buzzer==true){
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      pin_led=false;
      pin_buzzer=false;
    }
  }
  else if(input == 'x'){
    digitalWrite(ldr_btn, HIGH);
    digitalWrite(laser_btn, HIGH);
    pin_ldr_btn=true;
    pin_laser_btn=true;
    delay(2000);
    while(Serial.read() != '0'){
      ldr_val=analogRead(ldr);
      if (ldr_val<400){
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        pin_led=true;
        pin_buzzer=true;
        break;
      }
    }
    digitalWrite(ldr_btn, LOW);
    digitalWrite(laser_btn, LOW);
    pin_ldr_btn=false;
    pin_laser_btn=false;    
  }
  else if(input == 'y'){
    digitalWrite(ldr_btn, HIGH);
    digitalWrite(laser_btn, HIGH);
    pin_ldr_btn=true;
    pin_laser_btn=true;
    delay(2000);
    while(Serial.read() != '0'){
      ldr_val=analogRead(ldr);
      if (ldr_val<400){
        digitalWrite(s1, HIGH);
        digitalWrite(s2, HIGH);
        digitalWrite(s3, HIGH);
        pin_s1=true;
        pin_s2=true;
        pin_s3=true;
        break;
      }
    }
    digitalWrite(ldr_btn, LOW);
    digitalWrite(laser_btn, LOW);
    pin_ldr_btn=false;
    pin_laser_btn=false;    
  }
  else if(input == 'z'){
    digitalWrite(ldr_btn, HIGH);
    digitalWrite(laser_btn, HIGH);
    pin_ldr_btn=true;
    pin_laser_btn=true;
    delay(2000);
    while(Serial.read() != '0'){
      ldr_val=analogRead(ldr);
      if (ldr_val<400){
        digitalWrite(s1, LOW);
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        pin_s1=false;
        pin_s2=false;
        pin_s3=false;
        break;
      }
    }
    digitalWrite(ldr_btn, LOW);
    digitalWrite(laser_btn, LOW);
    pin_ldr_btn=false;
    pin_laser_btn=false;    
  }
}
