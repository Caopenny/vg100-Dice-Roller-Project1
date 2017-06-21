#define ENA 7 
#define IN1 6 
#define IN2 5 
#define IN3 4 
#define IN4 3 
#define ENB 2 
#define GS A1 
#define T 50
#define TimeUp 6000
#define TimeDown 20000

void setup() 
{
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(GS,INPUT);
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  delay(4000);
}
void loop() 
{
up();
  toward();
down();
delay(100000);
}
void toward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,255);
  
  while(digitalRead(GS)==HIGH)
  {
    delay(T);
  }
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,255);
  
}
void up()
{
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,255);
  delay(TimeUp);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,255);
}
void down()
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,255);
  delay(TimeDown);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,0);
}

