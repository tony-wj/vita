#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);    

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
          leftSpeed = speed;
          rightSpeed = speed;
      }else if(direction == 2){
          leftSpeed = -speed;
          rightSpeed = -speed;
      }else if(direction == 3){
          leftSpeed = -speed;
          rightSpeed = speed;
      }else if(direction == 4){
          leftSpeed = speed;
          rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
        
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeLineFollower linefollower_3(3);
MeLineFollower linefollower_2(2);
MeRGBLed rgbled_7(7, 7==7?2:4);
MeIR ir;
unsigned long time_since_last_reset = 0;
int interval_one = 6500;
int interval_two = 1200;
int interval_three = 2500;
int interval_four = 1400;
int interval_five_one = 600;
int stop_time = 10000;
int interval_five_two = 600;
int interval_six = 1500;
int interval_seven = 4800;
int interval_eight = 2000;
int interval_nine = 9000;
void setup(){
    ir.begin();
}

void loop(){
if(ir.keyPressed(69)){
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_one){
    mode_one();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_two){
    mode_two();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_three){
    mode_one();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_four){
    mode_three();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_five_one){
    mode_one();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<stop_time){
    car_stop();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_five_two){
    mode_one();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_six){
    mode_two();
  } 
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_seven){
    mode_one();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_eight){
    mode_four();
  }
  time_since_last_reset = millis();
  while((millis() - time_since_last_reset)<interval_nine){
    mode_one();
  }
  motor_9.run((9)==M1?-(0):(0));
  motor_10.run((10)==M1?-(0):(0));
}  
}
void mode_one(){
   
      rgbled_7.setColor(0,0,255,0);
      rgbled_7.show();
      if((true&&(0?(linefollower_3.readSensors()&1):!(linefollower_3.readSensors()&1)))){
        motor_9.run((9)==M1?-(255):(255));
        motor_10.run((10)==M1?-(50):(50));
    }else{
        if((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))){
            motor_9.run((9)==M1?-(50):(50));
            motor_10.run((10)==M1?-(255):(255));
        }else{
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                if((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))){
                    motor_9.run((9)==M1?-(255):(255));
                    motor_10.run((10)==M1?-(255):(255));
                }else{
                    motor_9.run((9)==M1?-(100):(100));
                    motor_10.run((10)==M1?-(50):(50));
                }
            }else{
                if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                    motor_9.run((9)==M1?-(50):(50));
                    motor_10.run((10)==M1?-(100):(100));
                }else{
                    move(2,50);
                }
            }
        }
    }
}

void mode_two(){
   
      rgbled_7.setColor(1,0,0,255);
      rgbled_7.show();
      if((true&&(1?(linefollower_3.readSensors()&1):!(linefollower_3.readSensors()&1)))){
        if((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))){
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                move(1,255);
            }else{
                motor_9.run((9)==M1?-(50):(50));
                motor_10.run((10)==M1?-(100):(100));
            }
        }else{
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                motor_9.run((9)==M1?-(100):(100));
                motor_10.run((10)==M1?-(50):(50));
            }else{
                move(2,50);
            }
        }
    }else{
        motor_9.run((9)==M1?-(255):(255));
        motor_10.run((10)==M1?-(50):(50));
    }  
}

void mode_three(){
  
      rgbled_7.setColor(2,255,0,0);
      rgbled_7.show();
      if((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))){
        if((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))){
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                move(1,255);
            }else{
                motor_9.run((9)==M1?-(50):(50));
                motor_10.run((10)==M1?-(100):(100));
            }
        }else{
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                motor_9.run((9)==M1?-(100):(100));
                motor_10.run((10)==M1?-(50):(50));
            }else{
                move(2,50);
            }
        }
    }else{
        motor_9.run((9)==M1?-(50):(50));
        motor_10.run((10)==M1?-(255):(255));
    }
}

void mode_four(){
   
      rgbled_7.setColor(0,0,0,255);
      rgbled_7.show();
        if((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))){
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                move(1,255);
            }else{
                motor_9.run((9)==M1?-(50):(50));
                motor_10.run((10)==M1?-(100):(100));
            }
        }else{
            if((true&&(0?(linefollower_3.readSensors()&2):!(linefollower_3.readSensors()&2)))){
                motor_9.run((9)==M1?-(100):(100));
                motor_10.run((10)==M1?-(50):(50));
            }else{
                move(2,50);
            }
        }
}
void car_stop(){
      rgbled_7.setColor(0,0,0,0);
      rgbled_7.show();
      motor_9.run((9)==M1?-(0):(0));
      motor_10.run((10)==M1?-(0):(0));
}
void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir.loop();
}

