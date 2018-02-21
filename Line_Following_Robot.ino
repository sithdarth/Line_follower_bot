int in_1 = 5;
int in_2 = 6;
int in_3 = 10;
int in_4 = 11;
int irr = 8 ;
int irl = 9 ;
int irc = 12 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(in_1,OUTPUT);
  pinMode(in_2,OUTPUT);
  pinMode(in_3,OUTPUT);
  pinMode(in_4,OUTPUT);
  pinMode(irl,INPUT);
  pinMode(irr,INPUT);
  pinMode(irc,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int left=digitalRead(irl);
  int right=digitalRead(irr);
  int center=digitalRead(irc);
  if((left == 0 && right == 0 && center == 1)||(left==0 && right == 1 && center == 1))//for right n forward option
  {
    dforward();
  }
  else if((left == 1 && right == 0 && center < 2) || (left == 0 && right == 0 && center == 0))
    dleft();
  }
  else if(left==0 && right==1 && center < 2) 
  {
    dright();
  }
  else if(left==1 && right==1 )
  {
    dstop();
  }
}
void dforward()
{
  analogWrite(in_1,190);
  analogWrite(in_2,0) ;
  analogWrite(in_3,190);
  analogWrite(in_4,0);
}
void dleft()
{
  analogWrite(in_1,190);
  analogWrite(in_2,0) ;
  analogWrite(in_3,0) ;
  analogWrite(in_4,190) ;
}
void dright()
{
  analogWrite(in_1,0);
  analogWrite(in_2,190) ;
  analogWrite(in_3,190) ;
  analogWrite(in_4,0) ;
}
void stop()
{
  
  analogWrite(in_1,0);
  analogWrite(in_2,0) ;
  analogWrite(in_3,0) ;
  analogWrite(in_4,0) ;
}
//orange5 yellow6 black8 brownir9 red10 brown11
