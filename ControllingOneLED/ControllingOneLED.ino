int columns[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
int layers[] = {A0, A1, A2, A3};
int activeColumn = 0;
int activeLayer = 0;

void setup() {
  // put your setup code here, to run once:
  // Turning all of the columns into outputs and turning them off
  for (int i = 0; i < 16; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], LOW);
  }

  //Turn all of the layers into outputs and turn them off
  for (int i = 0; i < 4; i++) {
    pinMode(layers[i], OUTPUT);
    digitalWrite(layers[i], HIGH);
  }
}


void loop() {
  snake();
}

void snake() {
  int delayT = 200;
  int repeat = 1000;
  
  for (int i = 0; i < 4; i++) {
    if ((i == 0) || (i == 2)) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < repeat; k++){
          for (int offset = 0; offset < 4; offset++){
            turnLEDOn(i + (4 * offset), j);
            delayMicroseconds(delayT);
          }
        }
      }
    }
    if ((i == 1) || (i == 3)){
      for (int j = 3; j >= 0; j--){
        turnLEDOn(i, j);
        delay(300);
      }
    }
  }
}

/*
   Turning LEDs on two a time
*/
void fionnnnnnaa() {
  int delayT = 100;
  int repeat = 1000;
  //First set:
  //Columns: 7, 4; Layer:3, 1
  for (int i = 0; i < repeat; i++) {
    turnLEDOn(7, 3);
    delayMicroseconds(delayT);
    turnLEDOn(3, 1);
    delayMicroseconds(delayT);
  }

  //Second set:
  //Columns: 8, 6; Layer: 2, 1
  for (int i = 0; i < repeat; i++) {
    turnLEDOn(8, 2);
    delayMicroseconds(delayT);
    turnLEDOn(6, 2);
    delayMicroseconds(delayT);
  }
}

/*
   Turning all of the LEDs one by one with a 300ms delay in between
*/
void simpleArrangement() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 16; j++) {
      turnLEDOn(j, i);
      delay(300);
    }
  }
}


void turnLEDOn(int column, int layer) {
  //1. Turn the old LED off
  digitalWrite(columns[activeColumn], LOW);
  digitalWrite(layers[activeLayer], HIGH);

  activeColumn = column;
  activeLayer = layer;

  //2. Turn the new LED on
  digitalWrite(columns[activeColumn], HIGH);
  digitalWrite(layers[activeLayer], LOW);
}

//void testConcept(boolean[4][4][4] matrix, int hold){
//
//}

void animate(int delayT, int repeat) {
  int columnInterest1[] = {12, 15, 12, 15};
  int layerInterest1[] = {0, 0, 3, 3};

  int columnInterest2[] = {13, 14, 13, 14};
  int layerInterest2[] = {1, 1, 2, 2};

  for (int j = 0; j < repeat; j++) {
    for (int i = 0; i < 4; i++) {
      turnLEDOn(columnInterest1[i], layerInterest1[i]);
      delay(delayT);
    }
  }
  for (int j = 0; j < repeat; j++) {
    for (int i = 0; i < 4; i++) {
      turnLEDOn(columnInterest2[i], layerInterest2[i]);
      delay(delayT);
    }
  }
}
