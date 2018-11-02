/**
 * CONSTANTS PIN
 */
const byte PIN_A = 12;
const byte PIN_B = 11;
const byte PIN_C = 10;
const byte PIN_D = 9;

/**
 * SEGMENTS PIN
 */
const byte SEGMENT_A = 7;
const byte SEGMENT_B = 8;
const byte SEGMENT_C = 4;
const byte SEGMENT_D = 3;
const byte SEGMENT_E = 2;
const byte SEGMENT_F = 6;
const byte SEGMENT_G = 5;

/**
 * Initialize a pin mode.
 */
void setup() 
{  
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_C, INPUT);
  pinMode(PIN_D, INPUT);
  
  pinMode(SEGMENT_A, OUTPUT);
  pinMode(SEGMENT_B, OUTPUT);
  pinMode(SEGMENT_C, OUTPUT);
  pinMode(SEGMENT_D, OUTPUT);
  pinMode(SEGMENT_E, OUTPUT);
  pinMode(SEGMENT_F, OUTPUT);
  pinMode(SEGMENT_G, OUTPUT);
  Serial.begin(9600);
}

/**
 * On Segment A.
 */
void onA(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool a = (pinB && pinC) || (!pinA && pinC && pinD) || (!pinA && pinB && pinD) || (pinA && !pinC && !pinD) || (pinA && !pinB && !pinC) || (!pinB && !pinD);
  Serial.println( a );
  digitalWrite(SEGMENT_A, a);
}

/**
 * On Segment B.
 */
void onB(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool b = (!pinA && !pinB) || (!pinA && !pinC && !pinD) || (!pinA && pinC && pinD) || (pinA && !pinC && pinD) || (!pinB && !pinD);
  Serial.println( b );
  digitalWrite(SEGMENT_B, b);
}

/**
 * On Segment C.
 */
void onC(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool c = (!pinA && pinD) || (!pinA && pinB || pinA && !pinB) || (!pinB && !pinC) || (pinA && !pinC && pinD);
  Serial.println( c );
  digitalWrite(SEGMENT_C, c);
}

/**
 * On Segment D.
 */
void onD(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool d = (!pinA && !pinB && !pinD) || (!pinB && pinC && pinD) || (pinB && !pinC && pinD) || (pinB && pinC && !pinD) || (pinA && !pinC && !pinD);
  Serial.println( d );
  digitalWrite(SEGMENT_D, d);
}

/**
 * On Segment E.
 */
void onE(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool e = (!pinB && !pinD) || (pinA && pinB) || (pinA && pinC) || (pinC && !pinD);
  Serial.println( e );
  digitalWrite(SEGMENT_E, e);
}

/**
 * On Segment F.
 */
void onF(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool f = (!pinC && !pinD) || (!pinA && pinB && !pinC) || (pinA && !pinB) || (pinA && pinC)  || (pinB && pinC && !pinD);
  Serial.println( f );
  digitalWrite(SEGMENT_F, f);
}

/**
 * On Segment G.
 */
void onG(byte pinA, byte pinB, byte pinC, byte pinD)
{
  bool g = (!pinA && !pinB && pinC) || (!pinA && pinB && !pinD) || (pinB && !pinC && pinD) || (pinA && pinB && pinC)  || (pinA && !pinB);
  Serial.println( g );
  digitalWrite(SEGMENT_G, g);
}

/**
 * System Loop.
 */
void loop() 
{
  byte pinA = digitalRead(PIN_A);
  byte pinB = digitalRead(PIN_B);
  byte pinC = digitalRead(PIN_C);
  byte pinD = digitalRead(PIN_D);

  onA(pinA, pinB, pinC, pinD);
  onB(pinA, pinB, pinC, pinD);
  onC(pinA, pinB, pinC, pinD);
  onD(pinA, pinB, pinC, pinD);
  onE(pinA, pinB, pinC, pinD);
  onF(pinA, pinB, pinC, pinD);
  onG(pinA, pinB, pinC, pinD);
  
  delay(500);
}