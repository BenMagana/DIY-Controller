//pin definitions are upper case
//valid pins: digital 0:32
//Analog: 14:25, 29:31
//serial1: 8-TX, 9-RX
//I2c: 10-SDA, 11-SCL 

#define A 0
#define B 1
#define Y 2
#define X 3

#define Start 4
#define Back 5
#define ConsoleBtn 6

#define RS 7

#define SDA 10
#define SCL 11

#define LS 12
#define Up 13
#define Left 14
#define Down 15
#define Right 16

#define LY A3 //17
#define LX A4 //18
#define RY A5 //19
#define RX A6 //20+
#define LT A7 //21
#define RT A8 //22
#define LB A9 //23
#define RB A10 //24

//A11 /25
//26
//27
//A12 //28
//A13 //29
//A14 //30
//A15 //31
//32

#define debounce 5

int bLast = 0;
int aLast = 0;
int xLast = 0;
int yLast = 0;
int startLast = 0;
int backLast = 0;
int consoleLast = 0;
int upLast = 0;
int leftLast = 0;
int rightLast = 0;
int downLast = 0;
int lsLast = 0;
int rsLast = 0;

int lsxLast = 512;
int lsyLast = 512;
int rsxLast = 512;
int rsyLast = 512;
int ltLast = 512;
int rtLast = 512;
int lbLast = 512;
int rbLast = 512;

//stored inputs are lower case
int b;
int a;
int x;
int y;
int startbtn;
int back;
int console = 0;
int up;
int left;
int right;
int down;
int ls;
int rs;

int lsx;
int lsy;
int rsx;
int rsy;
int lt;
int rt;
int lb;
int rb;

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
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(ConsoleBtn, INPUT);
  
  pinMode(LX, INPUT);
  pinMode(LY, INPUT);
  pinMode(RX, INPUT);
  pinMode(RY, INPUT);
  pinMode(LT, INPUT);
  pinMode(RT, INPUT);
  pinMode(LB, INPUT);
  pinMode(RB, INPUT);

//initialize serial communication at 9600 baud
//serial 1 per instructions
  Serial1.begin(9600);
}

void loop() {
  readPins();
  comparePins();
}

void readPins(){
  a = digitalRead(A);
  b = digitalRead(B);
  y = digitalRead(Y);
  x = digitalRead(X);
  startbtn = digitalRead(Start);
  back = digitalRead(Back);
  up = digitalRead(Up);
  left = digitalRead(Left);
  right = digitalRead(Right);
  down = digitalRead(Down);
  ls = digitalRead(LS);
  rs = digitalRead(RS);
  console = digitalRead(ConsoleBtn);
  
  lsx = analogRead(LX);
  lsy = analogRead(LY);
  rsx = analogRead(RX);
  rsy = analogRead(RY);
  lb = analogRead(LB);
  rb = analogRead(RB);
  rt = analogRead(RT);
  lt = analogRead(LT);
}

void comparePins(){
  compareD(a, aLast, "A");
  compareD(b, bLast, "B");
  compareD(y, yLast, "Y");
  compareD(x, xLast, "X");
  compareD(startbtn, startLast, "Start");
  compareD(back, backLast, "Back");
  compareD(up, upLast, "Up");
  compareD(left, leftLast, "Left");
  compareD(right, rightLast, "Right");
  compareD(down, downLast, "Down");
  compareD(ls, lsLast, "LeftStick");
  compareD(rs, rsLast, "RightStick");
  compareD(console, consoleLast, "Console");

  compareA(lsx, lsxLast, "lSX");
  compareA(lsy, lsyLast, "lSY");
  compareA(rsx, rsxLast, "RSX");
  compareA(rsy, rsyLast, "RSY");
  compareA(lb, lbLast, "LB");
  compareA(rb, rbLast, "RB");
  compareA(lt, ltLast, "LT");
  compareA(rt, rtLast, "RT");
}

void compareD(int btn, int &btnLast, String btnName ){
  if((btnLast == 0) && btn == 1){
    Serial1.println(btnName + " Down");
    btnLast = 1;
  }
  else if ((btnLast == 1) && btn == 0){
    Serial1.println(btnName + " Up");
    btnLast = 0;
  }
}

void compareA(int pot, int &potLast, String Name){
  if ( abs(pot - potLast) > debounce){
    potLast = pot;
    Serial1.println(Name + ": " + String(pot));
  }
}
