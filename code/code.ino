/*
 * This program show random dice numbers on a breadboard with 7 leds.
 * 
 * A dice is represented like this :
 * 
 * 1     2
 * 3  4  5 
 * 6     7
 */

const int OUT_1 = 2; // The points : 4
const int OUT_2 = 3; // The points : 1,7
const int OUT_3 = 4; // The points : 2,6
const int OUT_4 = 5; // The points : 3,5
const int DELAY_TIMER_TEST = 1000;
const int DELAY_TIMER = 5000;

int randomNumber;

void setup() {
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  pinMode(OUT_3, OUTPUT);
  pinMode(OUT_4, OUTPUT);

  randomSeed(analogRead(0));

  executeTest();
}

void loop() {
  showNumber(random(1, 7));

  delay(DELAY_TIMER);
  setAllOutOff();
}

/**
 * Execute a test program to test if all leds are connected.
 * Show all numbers in a row on the board.
 */
void executeTest() {
  setAllOutOn();
  delay(DELAY_TIMER_TEST);

  for (int i = 0; i < 6; i++) {
    showNumber(i + 1);
    delay(DELAY_TIMER_TEST);
  }

  setAllOutOff();

  delay(DELAY_TIMER_TEST);
}

/**
 * Turn on the corresponding leds on the board to the of the specified number.
 * Turn off all leds if number not in [1;6].
 */
void showNumber(int number) {
  setAllOutOff();
  
  switch (number) {
    case 1:
      setOutState(OUT_1, true);
      break;

    case 2:
      setOutState(OUT_2, true);
      break;

    case 3:
      setOutState(OUT_1, true);
      setOutState(OUT_2, true);
      break;

    case 4:
      setOutState(OUT_2, true);
      setOutState(OUT_3, true);
      break;

    case 5:
      setOutState(OUT_1, true);
      setOutState(OUT_2, true);
      setOutState(OUT_3, true);
      break;

    case 6:
      setOutState(OUT_2, true);
      setOutState(OUT_3, true);
      setOutState(OUT_4, true);
      break;

    default:
      setAllOutOn();
  }
}

/**
 * Turn on all leds.
 */
void setAllOutOn() {
  setOutState(OUT_1, true);
  setOutState(OUT_2, true);
  setOutState(OUT_3, true);
  setOutState(OUT_4, true);
}

/**
 * Turn off all leds.
 */
void setAllOutOff() {
  setOutState(OUT_1, false);
  setOutState(OUT_2, false);
  setOutState(OUT_3, false);
  setOutState(OUT_4, false);
}

/**
 * Set the state of the specified out pin.
 */
void setOutState(int out, bool on) {
  digitalWrite(out, on ? LOW : HIGH);
}
