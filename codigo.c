#include <LiquidCrystal.h>

int seconds = 300;
int fotoresistorValue = 0; // Variável para armazenar o valor lido do fotoresistor
const int pinoRELE = 7;
const int pinoPIR = 6;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  pinMode(A0, INPUT); // Definir o pino A0 como entrada
  pinMode(pinoRELE, OUTPUT);
  pinMode(pinoPIR, INPUT);
}

void loop() {
  fotoresistorValue = analogRead(A0); // Ler o valor analógico do pino A0
  lcd_1.setCursor(0, 1); // Definir o cursor na linha 2, coluna 1
  delay(1000); // Esperar por 1 segundo
  seconds += 1;

  if (fotoresistorValue > 110) {
    lcd_1.print("Dia  ");
  } else if (fotoresistorValue < 110) {
    lcd_1.print("Noite");
    int valor = digitalRead(pinoPIR);

    if (valor == HIGH) {
      digitalWrite(pinoRELE, HIGH);
      delay(5000);
      digitalWrite(pinoRELE, LOW);
    }
  }
}
