int latchPin = 13;   // connect to LCK pin
int clockPin = 12;   // connect to CLK pin
int dataPin = 11;    // connect to SDI pin

int LED_SEG_TAB[]={
  0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0x01,0xee,0x3e,0x1a,0x7a,0x9e,0x8e,0x01,0x00};
//0     1    2     3    4    5    6    7    8    9   dp   .    a    b    c    d    e    f   off

void setup() 
{
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void displayNumber(int value)
// break down "value" into digits and store in a,b,c,d  
{
  int a,b,c,d;
  a = value / 1000;
  value = value % 1000;
  b = value / 100;
  value = value % 100;
  c = value / 10;
  value = value % 10;
  d = value;

    if (a==0 && b>0)                  {
      a = 18;
    } 
    if (a==0 && b==0 && c>0)          {
      a = 18; 
      b = 18;
    }
    if (a==0 && b==0 && c==0)         {
      a = 18; 
      b = 18; 
      c = 18;
    }
    if (a==0 && b==0 && c==0 && d==0) {
      a = 18; 
      b = 18; 
      c = 18; 
      d = 18;
    }
  

  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[d]);  
  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[c]);  
  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[b]);  
  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[a]);  
}

void displays(int i, int j, int k) 
{
  digitalWrite(latchPin, LOW);

  displayNumber(i);
  displayNumber(j);
  displayNumber(k);

  digitalWrite(latchPin, HIGH);
}

void loop() {

  displays(1111, 2222, 3333);
  delay(1000);
}


