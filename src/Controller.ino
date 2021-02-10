#define B 2
#define X 3
#define A 4
#define Y 5
#define Start 6
#define Back 8
#define Up 9
#define Left 10
#define Down 11
#define Right 12
#define LY A0
#define LX A1
#define LB A2
#define RY A3
#define RX A4
#define RB A5
#define LT A6
#define RT A7

void setup() {
  // put your setup code here, to run once:
pinMode(B, INPUT);
pinMode(A, INPUT);
pinMode(X, INPUT);
pinMode(Y, INPUT);
pinMode(Start, INPUT);
pinMode(Back, INPUT);
pinMode(Up, INPUT);
pinMode(Left, INPUT);
pinMode(Down, INPUT);
pinMode(Right, INPUT);
//pinMode(LX, INPUT);
//pinMode(LY, INPUT);
pinMode(LB, INPUT);
//pinMode(RX, INPUT);
//pinMode(RY, INPUT);
pinMode(RB, INPUT);
//pinMode(LT, INPUT);
//pinMode(LT, INPUT);

//initialize serial communication at 9600 baud
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(A) == 1)
    Serial.println("A");
  
  if(digitalRead(B) == 1)
    Serial.println("B");
    
  if(digitalRead(Y) == 1)
    Serial.println("Y");

  if(digitalRead(X) == 1)
    Serial.println("X");

 if(digitalRead(Up) == 1)
    Serial.println("Up");
  
  if(digitalRead(Left) == 1)
    Serial.println("Left");
    
  if(digitalRead(Right) == 1)
    Serial.println("Right");

  if(digitalRead(Down) == 1)
    Serial.println("Down");
      
  if(digitalRead(Start) == 1)
    Serial.println("Start");

  if(digitalRead(Back) == 1)
    Serial.println("Back");
      
  if(digitalRead(LB) == 1)
    Serial.println("LB");

  if(digitalRead(RB) == 1)
    Serial.println("RB");
  LS();
  RS();
  delay(250);  
}

void LS(){
  Serial.print("LS: " + String(analogRead(LX)) + ", " + String(analogRead(LY))+ "\t");
}

void RS(){
  Serial.println("RS: " + String(analogRead(RX)) + ", " + String(analogRead(RY)));
}
