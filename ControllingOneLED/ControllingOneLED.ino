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
  // put your main code here, to run repeatedly:
  //Turn column 4 on, turn layer 3 on
  turnLEDOn(4, 3);
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
  for (int j = 0; j < repeat; j++){
    for (int i = 0; i < 4; i++){
      turnLEDOn(columnInterest2[i], layerInterest2[i]);
      delay(delayT);
    }
  }
}

