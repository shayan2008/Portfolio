int pins[] = {2, 3, 4, 5, 6, 7, 8}; // LED pins
int digits[] = {10, 11, 12, 13}; // digit control pins
int zero[] = {1, 1, 1, 1, 1, 1, 0}; // LED states for zero
int one[] = {0, 1, 1, 0, 0, 0, 0}; // LED states for one
int two[] = {1, 1, 0, 1, 1, 0, 1};
int three[] = {1, 1, 1, 1, 0, 0, 1};
int four[] = {0, 1, 1, 0, 0, 1, 1};
int five[] = {1, 0, 1, 1, 0, 1, 1};
int six[] = {1, 0, 1, 1, 1, 1, 1};
int seven[] = {1, 1, 1, 0, 0, 0, 0};
int eight[] = {1, 1, 1, 1, 1, 1, 1};
int nine[] = {1, 1, 1, 1, 0, 1, 1};
int time, n;
int j;
int k;
void setup()
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  // define pins and digits as output

  for (int i = 0; i < 7; i++) pinMode (pins[i], OUTPUT);

  for (int i = 0; i < 4; i++) pinMode (digits[i], OUTPUT);
}
void loop()
{
  int a = digitalRead(1);
  int b = digitalRead(0);
  if (a == 1) {
    for (k = 0 ; k < 10 ; k++) {
      number(k); // modulus(time, 100)/10
      digit(2); // digit D3 for tens
      delay(5);
      for (j = 0 ; j < 10 ; j++) {
        number(k); // modulus(time, 100)/10
        digit(2); // digit D3 for tens
        delay(5);
        number(j); // modulus(time, 10)
        digit(3); // digit D4 for units
        delay(1000);
      }
    }
  }
}

void digit(int d)

// function to set digit states
{

  // turn all digits off

  for (int i = 0; i < 4; i++) digitalWrite(digits[i], 1);

  digitalWrite(digits[d], 0); // digit pin state is LOW, display is on
}
void number(int n)

// function to display numbers
{

  if

  (n == 0) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], zero[i]);

  else if (n == 1) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], one[i]);

  else if (n == 2) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], two[i]);

  else if (n == 3) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], three[i]);

  else if (n == 4) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], four[i]);

  else if (n == 5) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], five[i]);

  else if (n == 6) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], six[i]);

  else if (n == 7) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], seven[i]);

  else if (n == 8) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], eight[i]);

  else if (n == 9) for (int i = 0; i < 7; i++)

      digitalWrite(pins[i], nine[i]);
}
