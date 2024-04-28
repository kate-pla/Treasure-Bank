#include <LiquidCrystal.h>
int Contrast =75;
LiquidCrystal lcd(12,11,5,4,3,2);
#define buttonAdd01 13
#define buttonAdd10 9
#define buttonAdd25 8
#define buttonAdd05 7
#define buttonAdd1 10
#define buttonAdd5 1
#define buttonUndo 0
#define buttonReset A0

float total = 0;
float previous =0;
void setup() {
  #Initalizes the Contrast
  analogWrite(6,Contrast);
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
}

void loop() {
  // Displays the total amount of money
  lcd.setCursor(0, 0);
  lcd.print("Amount");
  lcd.setCursor(0, 1);
  lcd.print(total);
  
  // Adds the value amount depending which button is pressed
  if(digitalRead(buttonAdd01)==LOW)
  {
    Serial.print("Works");
    ftotal+= 0.01;
    previous = 0.01;
    delay(500);
  }
  
  else if(digitalRead(buttonAdd05)==LOW)
  {
    total+= 0.05;
    previous = 0.05;
    delay(500);
  }
  else if(digitalRead(buttonAdd10)==LOW)
  {
    total+= 0.10;
    previous = 0.10;
    delay(500);
  }
  else if(digitalRead(buttonAdd25)==LOW)
  {
    total+= 0.25;
    previous = 0.25;
    delay(500);
  }
  else if(digitalRead(buttonAdd1)==LOW)
  {
    total+= 1.00;
    previous = 1.00;
    delay(500);
  }
  else if(digitalRead(buttonAdd5)==LOW)
  {
    total+= 5.00;
    previous = 5.00;
    delay(500);
  }
  else if(digitalRead(buttonUndo)==LOW)
  {

    total -= previous;
    delay(500);
  }
  else if(analogRead(buttonReset)==LOW)
  {
    total=0.00;
    delay(500);
  }
  
}
