//constant declaration
const int buttonLeft=2;
const int buttonRight=3;

const int channelOne=13;
const int channelTwo=12;

//variable declaration
int leftButtonState=0;
int leftButtonLastState=0;

int rightButtonState=0;
int rightButtonLastState=0;

int targetDirection=0;
//0 - LEFT
//1 - RIGHT
//2 - STOP

void setup()
{
  //input initiation
  pinMode(buttonLeft,INPUT_PULLUP);
  pinMode(buttonRight,INPUT_PULLUP);
  
  //output initiation
  pinMode(channelOne,OUTPUT);
  pinMode(channelTwo,OUTPUT);
  
  //debug settings
  Serial.begin(9600);
}

void loop()
{
  leftButtonState=digitalRead(buttonLeft);
  //Serial.println(leftButtonState);

  rightButtonState=digitalRead(buttonRight);
  //Serial.println(rightButtonState);
    
  //input read
  if(leftButtonState==0&&rightButtonState==0)
  {
    targetDirection=2;
  }
  else if(leftButtonState==0)
  {
    targetDirection=1;
  }
  else
  {
    targetDirection=0;
  }

  //engine controls
  if(targetDirection==0)
  {
    digitalWrite(channelOne,HIGH);
    digitalWrite(channelTwo,LOW);
  }
  else if(targetDirection==1)
  {
    digitalWrite(channelOne,LOW);
    digitalWrite(channelTwo,HIGH);
  }
  else
  {
    digitalWrite(channelOne,LOW);
    digitalWrite(channelTwo,LOW);
  }
}
