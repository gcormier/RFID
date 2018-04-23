#define COIL_PIN  10  // This HAS to be AVR OC1A which is physical pin 16, Arduino pin 10
bool coilOut = true;


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  setupTimer();

}

void loop() {

}

void setupTimer()
{
  TCCR1A = _BV(COM1B0);// | _BV(WGM10);// | _BV(WGM11)
  TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(CS10);// | _BV(WGM13);

  OCR1A = 0;
  TIMSK1 |= (1 << OCIE1A);



}

ISR(TIMER1_COMPA_vect)
{
  PORTD ^= _BV(7);

}