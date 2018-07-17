
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

int steps[] = {1, 3, 2, 6, 4, 12, 8, 9};
int x = 0;
int direction = 1;
int cycles =0;

void loop() {
  int step = steps[x+=direction];
  if (x >= 8) x = 0;
  if (x < 0) x = 8;
  digitalWrite(4, step & 1);
  digitalWrite(5, step & 2);
  digitalWrite(6, step & 4);
  digitalWrite(7, step & 8);
  delay(1);
  cycles++;
  if (cycles == 5000) {
    direction = -direction;
    cycles=0;
  }
}

void println(String x){ if(Serial){Serial.println(x);}}

