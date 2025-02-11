// connect motor controller pins to Arduino digital pins
// motor one

int enA = 10;
int in1 = 9;  
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;  //4th pin of driver
int in4 = 6;  //3rd pin of driver
const int ir2 = A1;
const int ir1 = A0;
const int irt = A2;
const int irb = A6;
int ir =13;
int light = analogRead(A3);
int soil = analogRead(A4);
const int light_sms;
const int soil_sms;
int light_station = 1;
char command; 
char cmd;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3,  OUTPUT);
  pinMode(4,  OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);  
  int soil = 400;
  int light_station = 1;

digitalWrite(3,1);
digitalWrite(4,0);
}
void loop(){
   int i = analogRead(ir1);
   int j = analogRead(ir2);
   int t = analogRead(irt);
   int b = analogRead(irb);
   int light = analogRead(A3);
   int control = digitalRead(11);
   digitalWrite(13, LOW);
   int line_B = digitalRead(3);
   int value_B = digitalRead(4);

   if(Serial.available() > 0){ 
    command = Serial.read(); 
    breaks(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();  
      delay(500);
      breaks();

      break;
    case 'B':  
       back();
       delay(500);
      breaks();

      break;
    case 'L':  
      left();
      delay(500);
      breaks();
      
      break;
    case 'R':
      right();
      delay(500);
      breaks();
      
      break;

      case 'S':
      breaks();
            digitalWrite(13,LOW);

      
      break;

      case 'M': //connect
      breaks();
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      
      break;

      case 'N': //disconnect
      digitalWrite(3,1);
      digitalWrite(4,0);
      break;

      case 'W':
      digitalWrite(13,HIGH);
      
      break;

      case 'C':
      digitalWrite(13,HIGH);
      
      break;
    }



  } 

   
  else if (soil < 500 && t < 100 && line_B == 1){
        analogWrite(A5 , 255); 

           breaks();
            delay(1500);
            digitalWrite(13 , HIGH);
            delay(3000);
            digitalWrite(13 , LOW);
           soil = soil + 500;
           delay(1000);
        }
      
  
 else if( light > 200 && line_B == 1){
    digitalWrite(12, HIGH);
    breaks();
   }
   
 else if(light_station == 1 && b < 100 && line_B == 1){

        breaks();
        delay(1500);
        digitalWrite(13, HIGH);
        delay(5000);
        digitalWrite(13,LOW);
        light_station = light_station + 5 ;
       
  }


if (value_B == 1){
  
 Serial.print(light);
 delay(2000); 
  
  }

 if( line_B == 1 )
{
  
     if (i > 600 && j > 600 ){
      forward();
        }
      else if( i < 60 && j > 600 ){
        left();
      }
      else if (i > 600 && j < 100 ){
      right();
      }
     else if( i < 60 && j < 100){
      breaks();
    }

}
       }


               //***************************************FORWARD*******************************************************

int forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  
          }
               //****************************************LEFT***********************************************************

 int left (){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
    
    }
           // **************************************RIGHT*********************************************************

int right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
 
  }
         //  ***********************************STOP***********************************************************

int breaks(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, LOW);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB,LOW);

    }

int back(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  
          }
