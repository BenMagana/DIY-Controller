//pin definitions are upper case
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
#define LS A2
#define RY A3
#define RX A4
#define RS A5
#define LT A6
#define RT A7
//#define LB
//#defime RB
//#define Console

#define debounce 5

int bLast = 0;
int aLast = 0;
int xLast = 0;
int yLast = 0;
int startLast = 0;
int backLast = 0;
int upLast = 0;
int leftLast = 0;
int rightLast = 0;
int downLast = 0;
int lsLast = 0;
//int consoleLast = 0;
int rsLast = 0;

int lsxLast = 512;
int lsyLast = 512;
int rsxLast = 512;
int rsyLast = 512;
int ltLast = 512;
int rtLast = 512;
//int lbLast = 512;
//int rbLast = 512;

//stored inputs are lower case
int b;
int a;
int x;
int y;
int start;
int back;
int up;
int left;
int right;
int down;
int ls;
int rs;
//int console = 0;

int lsx;
int lsy;
int rsx;
int rsy;
int lt;
int rt;
//int lb;
//int rb;

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
//pinMode(console, INPUT);

pinMode(LX, INPUT);
pinMode(LY, INPUT);
pinMode(RX, INPUT);
pinMode(RY, INPUT);
pinMode(LT, INPUT);
pinMode(RT, INPUT);
//pinMode(LB, INPUT);
//pinMode(RB, INPUT):

//initialize serial communication at 9600 baud
Serial.begin(9600);
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
  start = digitalRead(Start);
  back = digitalRead(Back);
  up = digitalRead(Up);
  left = digitalRead(Left);
  right = digitalRead(Right);
  down = digitalRead(Down);
  ls = digitalRead(LS);
  rs = digitalRead(RS);
  //console = digitalRead(Console);
  
  lsx = analogRead(LX);
  lsy = analogRead(LY);
  rsx = analogRead(RX);
  rsy = analogRead(RY);
  //lb = analogRead(LB);
  //rb = analogRead(RB);
  rt = analogRead(RT);
  lt = analogRead(LT);
}

void comparePins(){
  compareD(a, aLast, "A");
  compareD(b, bLast, "B");
  compareD(y, yLast, "Y");
  compareD(x, xLast, "X");
  compareD(start, startLast, "A");
  compareD(back, backLast, "B");
  compareD(up, upLast, "Y");
  compareD(left, leftLast, "X");
  compareD(right, rightLast, "A");
  compareD(down, downLast, "B");
  compareD(ls, lsLast, "Y");
  compareD(rs, rsLast, "X");
  //compareD(console, consoleLast, "Console");

  compareA(lsx, lsxLast, "lSX");
  compareA(lsy, lsyLast, "lSY");
  compareA(rsx, rsxLast, "RSX");
  compareA(rsy, rsyLast, "RSY");
  //compareA(lb, lbLast, "LB");
  //compareA(rb, rbLast, "RB");
  //compareA(lt, ltLast, "LT");
  //compareA(rt, rtLast, "RT");
}

void compareD(int btn, int &btnLast, String btnName ){
  if((btnLast == 0) && btn == 1){
    Serial.println(btnName + " Down");
    btnLast = 1;
  }
  else if ((btnLast == 1) && btn == 0){
    Serial.println(btnName + " Up");
    btnLast = 0;
  }
}

void compareA(int pot, int &potLast, String Name){
  if ( abs(pot - potLast) > debounce){
    potLast = pot;
    Serial.println(Name + ": " + String(pot));
  }
}
