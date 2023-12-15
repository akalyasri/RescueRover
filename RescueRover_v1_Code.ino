#define JackMode   0b00000000
#define RoverMode  0b11111111

#define yAxisPin A0
#define xAxisPin A1

#define LED_1 2
#define LED_2 7

#define TrackMotor_Left_Forward 3
#define TrackMotor_Left_Reverse 4

#define TrackMotor_Right_Forward 5
#define TrackMotor_Right_Reverse 6

#define ModeSwitchPin 9

#define JackUpPin 11
#define JackDownPin 12



int xAxisValue = 0;
int yAxisValue = 0;
unsigned char Joystick_Mode = RoverMode; 
unsigned char ModeKey;


void setup() 
{
  Serial.begin(9600); //how fast it's printing, 9600 bits per second
  
  pinMode(JackUpPin, OUTPUT);
  pinMode(JackDownPin, OUTPUT);
  
  pinMode(yAxisPin, INPUT);
  pinMode(xAxisPin, INPUT);
  
  pinMode(ModeSwitchPin, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  xAxisValue = analogRead(xAxisPin);
  yAxisValue = analogRead(yAxisPin);
  delay(100);
  yAxisValue = analogRead(yAxisPin);
 
  ModeKey = digitalRead(ModeSwitchPin);

  if(ModeKey == 0)
  {
    Joystick_Mode = ~Joystick_Mode;
    delay(100);
  }

  //debugging
  Serial.print(xAxisValue,DEC);
  Serial.print("         ");
  Serial.print(yAxisValue, DEC);
  Serial.print("         ");
  Serial.print(Joystick_Mode, DEC);
  Serial.print("\n");
  
  if (Joystick_Mode == RoverMode)
  {
    if(yAxisValue > 800)
    {
      digitalWrite(TrackMotor_Left_Forward, HIGH);
      digitalWrite(TrackMotor_Left_Reverse, LOW);

      digitalWrite(TrackMotor_Right_Forward, HIGH);
      digitalWrite(TrackMotor_Right_Reverse, LOW);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      
    }else if (yAxisValue < 200)
    {
      digitalWrite(TrackMotor_Left_Forward, LOW);
      digitalWrite(TrackMotor_Left_Reverse, HIGH);

      digitalWrite(TrackMotor_Right_Forward, LOW);
      digitalWrite(TrackMotor_Right_Reverse, HIGH);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
               
    }else
    {
      digitalWrite(TrackMotor_Left_Forward, LOW);
      digitalWrite(TrackMotor_Left_Reverse, LOW);

      digitalWrite(TrackMotor_Right_Forward, LOW);
      digitalWrite(TrackMotor_Right_Reverse, LOW);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      
    }

    if(xAxisValue > 800)
    {
      digitalWrite(TrackMotor_Left_Forward, LOW);
      digitalWrite(TrackMotor_Left_Reverse, LOW);

      digitalWrite(TrackMotor_Right_Forward, HIGH);
      digitalWrite(TrackMotor_Right_Reverse, LOW);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
    }else if (xAxisValue < 200)
    {
      digitalWrite(TrackMotor_Left_Forward, HIGH);
      digitalWrite(TrackMotor_Left_Reverse, LOW);

      digitalWrite(TrackMotor_Right_Forward, LOW);
      digitalWrite(TrackMotor_Right_Reverse, LOW);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
    }else
    {
      digitalWrite(TrackMotor_Left_Forward, LOW);
      digitalWrite(TrackMotor_Left_Reverse, LOW);

      digitalWrite(TrackMotor_Right_Forward, LOW);
      digitalWrite(TrackMotor_Right_Reverse, LOW);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
    }

    
  }else 
  {
      if(yAxisValue > 800)
      {
       digitalWrite(JackUpPin, HIGH);
       digitalWrite(JackDownPin, LOW);  
    
       digitalWrite(LED_1, HIGH);
       digitalWrite(LED_2, HIGH);
      }
      else if (yAxisValue < 200)
      {
          digitalWrite(JackUpPin, LOW);
          digitalWrite(JackDownPin, HIGH);
    
          digitalWrite(LED_1, HIGH);
          digitalWrite(LED_2, HIGH);
      }
        else
        {
          digitalWrite(JackUpPin, LOW);
          digitalWrite(JackDownPin, LOW); 
      
          digitalWrite(LED_1, HIGH);
          digitalWrite(LED_2, HIGH);
          
         }
  }

    delay(500);
}
