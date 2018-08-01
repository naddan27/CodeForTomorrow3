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
  //Turn column 9 on, turn layer 1 on
  digitalWrite(columns[9], HIGH);
  digitalWrite(layers[1], LOW);
  delay(1000);
  digitalWrite(columns[9], LOW);
  digitalWrite(layers[1], HIGH);
  delay(1000);
}

void turnLEDOn(int column, int layer) {
  //1. Turn the old LED off
  digitalWrite(columns[activeColumn], LOW);
  digitalWrite(layers[activeLayer], HIGH);

  activeColumn = column;
  activeLayer = layer;
  //2. Turn the new LED on
}

