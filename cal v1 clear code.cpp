#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int index1 = 0;
byte prnmbr1, deunmbr1, troinmbr1;
byte prnmbr2, deunmbr2, troinmbr2;
byte prnmbr3, deunmbr3, troinmbr3;
byte mettreenville = 0;
byte prnmbrhorloge, deunmbrhorloge;
byte jour = 1, mois = 1;
byte annee1 = 19, annee2 = 20;
byte d = 60;
byte sswitch = 0;
int modevalue; int keypad; int valuekeypad;
char operation = ' '; char operation2 = ' ';
byte second; byte minute = 59; byte heur;
int lenmbr1; int lenmbr2; int lenmbr3;
byte m = 0; byte mh = 0;
byte xrh = 0; byte xmh = 0;
byte x = 0; byte y = 0; byte r = 0;
byte l = 0; byte l1 = 0; byte l2;
byte index; byte zid;
byte modificationpin = A2;
float resulta = 0; float resulta2 = 0;
byte resultahorloge;
unsigned long arduinotime; long n = 0;
int TMP;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(16, 1);
  lcd.print("By Z A I D aguerdoum");
  for (int b = 0; b < 38; b++) {
    lcd.scrollDisplayLeft();
    delay(50);
  }
  lcd.clear();
  lcd.setCursor(20, 0);
  lcd.print("Hello");
  lcd.setCursor(20, 1);
  lcd.print("WORLD");
  for (int b = 0; b < 14; b++) {
    lcd.scrollDisplayLeft();
    delay(50);
  }
  l2 = 0;
  while (arduinotime < 2000) {
    arduinotime = millis();
    Serial.println(arduinotime);
  }
}
void loop() {
  valuekeypad = analogRead(A0);
  if ((m != 1) && (mettreenville == 0) && (valuekeypad == 201)) {
    mettreenville = 1;
    delay(60);
  }
  valuekeypad = analogRead(A0);
  if ((mettreenville == 1) && (valuekeypad == 201)) {
    mettreenville = 0;
    delay(60);
  }
  if (mettreenville == 1) {
    lcd.clear();
    delay(100);
    lcd.setCursor(1, 0);
    lcd.print("mettre en ville");
    if (l1 == 0) {
      l1 = 1;
      for (byte scrol = 0; scrol < 6; scrol++) {
        lcd.scrollDisplayLeft();
        delay(400);
        lcd.scrollDisplayRight();
        delay(400);
      }
    }
    lcd.clear();
    digitalWrite(8, HIGH);
    l = 0;
    mh = 0;
    r = 0;
    xmh = 0;
  } else {
    digitalWrite(8, LOW);
    if (l == 0) {
      lcd.begin(16, 2);
      if (l2 == 1) {
        lcd.setCursor(6, 0);
        lcd.print("Hello");
        delay(1000);
        lcd.clear();
      }
      l = 1;
      l1 = 0;
    }
  }
  l2 = 1;
  arduinotime = millis();
  Serial.print("millisnov:");
  Serial.println(arduinotime);
  if (second == 60) {
    minute++;
    n = n - second;
  }
  second = n + (arduinotime / 1000) - 2;
  if (minute >= 60) {
    minute = 0;
    heur++;
  }
  if (heur >= 24) {
    heur = 0;
    jour++;
  }
  if ((jour == 31) && (mois == 4 || mois == 6 || mois == 9 || mois == 11)) {
    jour = 1;
    mois++;
  }
  if ((jour == 32) && (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)) {
    jour = 1;
    mois++;
  }
  if ((jour == 29) && (mois == 2)) {
    jour = 1;
    mois++;
  }
  if (mois == 13) {
    mois = 1;
    annee1++;
  }
  if (annee1 == 100) {
    annee1 = 0;
    annee2++;
  }
  if (mettreenville == 0) {
    modevalue = analogRead(modificationpin);
    if ((m == 0) && (modevalue == 341)) {
      m = 1;
      lcd.clear();
      delay(60);
    }
    modevalue = analogRead(modificationpin);
    if ((m == 1) && (modevalue == 341)) {
      m = 0;
      lcd.clear();
      sswitch = 1;
      delay(60);
    }
    if (m == 0) {
      y = 0;
      modevalue = analogRead(modificationpin);
      if ((mh == 0) && (modevalue == 205)) {
        mh = 1;
        lcd.clear();
        lcd.setCursor(8, 0);
        lcd.print("^^");
        resultahorloge = 189;
        delay(60);
      }
      modevalue = analogRead(modificationpin);
      if ((mh == 1) && (modevalue == 205)) {
        mh = 2;
        lcd.clear();
        lcd.setCursor(11, 0);
        lcd.print("^^");
        resultahorloge = 189;
        delay(60);
      }
      modevalue = analogRead(modificationpin);
      if ((mh == 2) && (modevalue == 205)) {
        mh = 3;
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("^^");
        resultahorloge = 189;
        delay(60);
      }
      modevalue = analogRead(modificationpin);
      if ((mh == 3) && (modevalue == 205)) {
        mh = 4;
        lcd.clear();
        lcd.setCursor(3, 1);
        lcd.print("^^");
        resultahorloge = 189;
        delay(60);
      }
      modevalue = analogRead(modificationpin);
      if ((mh == 4) && (modevalue == 205)) {
        mh = 5;
        lcd.clear();
        lcd.setCursor(9, 1);
        lcd.print("^^^^");
        resultahorloge = 189;
        delay(60);
      }
      modevalue = analogRead(modificationpin);
      if ((mh == 5) && (modevalue == 205)) {
        mh = 0;
        r = 0;
        delay(60);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (xmh == 0)) {
        if (mh == 1) {
          lcd.setCursor(8, 0);
          lcd.print("^^");
        }
        if (mh == 2) {
          lcd.setCursor(11, 0);
          lcd.print("^^");
        }
        if (mh == 3) {
          lcd.setCursor(6, 1);
          lcd.print("^^");
        }
        if (mh == 4) {
          lcd.setCursor(3, 1);
          lcd.print("^^");
        }
        if ((mh == 5) && (r == 0)) {
          lcd.setCursor(9, 1);
          lcd.print("^^^^");
        }
        if ((mh == 1) && (keypad < 3)) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(8, 0);
          lcd.print(prnmbrhorloge);
        }
        if ((mh == 2) && (keypad < 6)) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(11, 0);
          lcd.print(prnmbrhorloge);
        }
        if ((mh == 3) && (keypad == 0 || keypad == 1)) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(6, 1);
          lcd.print(prnmbrhorloge);
        }
        if ((mh == 4) && (((mois == 2) && (keypad < 3)) || ((mois != 2) && (keypad < 4)))) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(3, 1);
          lcd.print(prnmbrhorloge);
        }
        if ((mh == 5) && (r == 0)) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(9, 1);
          lcd.print(prnmbrhorloge);
        }
        if ((mh == 5) && (r == 1)) {
          prnmbrhorloge = keypad;
          xmh = 1;
          lcd.setCursor(11, 1);
          lcd.print(prnmbrhorloge);
        }
        delay(60);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (xmh == 1)) {
        if ((mh == 1) && ((prnmbrhorloge < 2) || ((prnmbrhorloge == 2) && (keypad < 4)))) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(9, 0);
          lcd.print(deunmbrhorloge);
        }
        if (mh == 2) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(12, 0);
          lcd.print(deunmbrhorloge);
        }
        if ((mh == 3) && (((prnmbrhorloge == 0) && (keypad < 10) && (keypad > 0)) || ((prnmbrhorloge == 1) && (keypad < 3)))) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(7, 1);
          lcd.print(deunmbrhorloge);
        }
        if ((mh == 4) && ((prnmbrhorloge == 0) && (keypad > 0) || (prnmbrhorloge > 0)) && (((mois == 2) && ((prnmbrhorloge < 2) || ((prnmbrhorloge == 2) && (keypad < 9)))) || ((mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12) && ((prnmbrhorloge < 3) || ((prnmbrhorloge == 3) && (keypad < 2)))) || ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && ((prnmbrhorloge < 3) || ((prnmbrhorloge == 3) && (keypad == 0)))))) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(4, 1);
          lcd.print(deunmbrhorloge);
        }
        if ((mh == 5) && (r == 0)) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(10, 1);
          lcd.print(deunmbrhorloge);
        }
        if ((mh == 5) && (r == 1)) {
          deunmbrhorloge = keypad;
          xmh = 2;
          lcd.setCursor(12, 1);
          lcd.print(deunmbrhorloge);
        }
        delay(60);
      }
      if (xmh == 2) {
        resultahorloge = (prnmbrhorloge * 10) + (deunmbrhorloge * 1);
        xmh = 0;
      }
      if ((mh == 1) && (resultahorloge != 189) && (resultahorloge < 24)) {
        heur = resultahorloge;
      }
      if ((mh == 2) && (resultahorloge != 189) && (resultahorloge < 60)) {
        minute = resultahorloge;
      }
      if ((mh == 3) && (resultahorloge != 189) && (resultahorloge < 13) && (0 < resultahorloge)) {
        mois = resultahorloge;
      }
      if ((mh == 4) && (resultahorloge != 189) && (0 < resultahorloge) && (((resultahorloge < 29) && (mois == 2)) || ((resultahorloge < 32) && (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)) || ((resultahorloge < 31) && (mois == 4 || mois == 6 || mois == 9 || mois == 11)))) {
        jour = resultahorloge;
      }
      if ((mh == 5) && (resultahorloge != 189) && (r == 0)) {
        r = 1;
        annee2 = resultahorloge;
        resultahorloge = 189;
      }
      if ((mh == 5) && (resultahorloge != 189) && (r == 1)) {
        annee1 = resultahorloge;
        resultahorloge = 189;
        r = 0;
      }
      if (mh == 0) {
        xmh = 0;
        r = 0;
        if ((0 <= second) && (second < 10)) {
          lcd.setCursor(14, 0);
          lcd.print("0");
          lcd.setCursor(15, 0);
          lcd.print(second);
        }
        if ((10 <= second) && (second < 60)) {
          lcd.setCursor(14, 0);
          lcd.print(second);
        }
        if ((0 <= minute) && (minute < 10)) {
          lcd.setCursor(11, 0);
          lcd.print("0");
          lcd.setCursor(12, 0);
          lcd.print(minute);
        }
        if ((10 <= minute) && (minute <= 60)) {
          lcd.setCursor(11, 0);
          lcd.print(minute);
        }
        if ((0 <= heur) && (heur < 10)) {
          lcd.setCursor(8, 0);
          lcd.print("0");
          lcd.setCursor(9, 0);
          lcd.print(heur);
        }
        if ((10 <= heur) && (heur <= 60)) {
          lcd.setCursor(8, 0);
          lcd.print(heur);
        }
        if ((1 <= jour) && (jour < 10)) {
          lcd.setCursor(4, 1);
          lcd.print(jour);
          lcd.setCursor(3, 1);
          lcd.print("0");
        }
        if ((10 <= jour) && (jour <= 31)) {
          lcd.setCursor(3, 1);
          lcd.print(jour);
        }
        if ((1 <= mois) && (mois < 10)) {
          lcd.setCursor(7, 1);
          lcd.print(mois);
          lcd.setCursor(6, 1);
          lcd.print("0");
        }
        if ((10 <= mois) && (mois <= 12)) {
          lcd.setCursor(6, 1);
          lcd.print(mois);
        }
        if ((0 <= annee1) && (annee1 < 10)) {
          lcd.setCursor(11, 1);
          lcd.print("0");
          lcd.setCursor(12, 1);
          lcd.print(annee1);
        }
        if ((10 <= annee1) && (annee1 <= 99)) {
          lcd.setCursor(11, 1);
          lcd.print(annee1);
        }
        if ((0 <= annee2) && (annee2 < 10)) {
          lcd.setCursor(9, 1);
          lcd.print("0");
          lcd.setCursor(10, 1);
          lcd.print(annee2);
        }
        if ((10 <= annee2) && (annee2 <= 99)) {
          lcd.setCursor(9, 1);
          lcd.print(annee2);
        }
      }
      lcd.setCursor(5, 1);
      lcd.print("/");
      lcd.setCursor(8, 1);
      lcd.print("/");
      lcd.setCursor(13, 0);
      lcd.print(":");
      lcd.setCursor(10, 0);
      lcd.print(":");
      int TMPvalue = analogRead(A1);
      TMP = map(TMPvalue, 20, 358, -40, 125);
      lcd.setCursor(0, 0);
      lcd.print("TMP:");
      lcd.setCursor(4, 0);
      lcd.print(TMP);
      if (((-40 <= TMP) && (TMP < -9)) || ((99 <= TMP) && (TMP < 125))) {
        lcd.setCursor(7, 0);
        lcd.print("C");
      }
      if (((-9 <= TMP) && (TMP < 0)) || ((9 <= TMP) && (TMP < 99))) {
        lcd.setCursor(6, 0);
        lcd.print("C ");
      }
      if ((0 <= TMP) && (TMP < 10)) {
        lcd.setCursor(5, 0);
        lcd.print("C  ");
      }
    }
    if (m == 1) {
      keypad = -14848;
      valuekeypad = analogRead(A0);
      /*DECLAREE*/
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 0)) {
        prnmbr1 = keypad;
        x = 1;
        lcd.setCursor(zid, 0);
        lcd.print(prnmbr1);
        zid++;
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 1)) {
        deunmbr1 = keypad;
        x = 2;
        lcd.setCursor(zid, 0);
        lcd.print(deunmbr1);
        zid++;
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 2)) {
        troinmbr1 = keypad;
        x = 3;
        lcd.setCursor(zid, 0);
        lcd.print(troinmbr1);
        zid++;
        delay(d);
      }
      if (x < 4) {
        if (valuekeypad == 426) {
          operation = '+';
        }
        if (valuekeypad == 301) {
          operation = '-';
        }
        if (valuekeypad == 233) {
          operation = '/';
        }
        if (valuekeypad == 193) {
          operation = '*';
        }
      }
      if ((x == 1) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr1 = prnmbr1;
        x = 4;
        index = 1;
        lcd.setCursor(index, 0);
        lcd.print(operation);
      }
      if ((x == 2) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr1 = (prnmbr1 * 10) + (deunmbr1 * 1);
        x = 4;
        index = 2;
        lcd.setCursor(index, 0);
        lcd.print(operation);
      }
      if ((x == 3) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr1 = (prnmbr1 * 100) + (deunmbr1 * 10) + (troinmbr1 * 1);
        index = 3;
        x = 4;;
        lcd.setCursor(index, 0);
        lcd.print(operation);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 4)) {
        prnmbr2 = keypad;
        x = 5;
        index++;;
        lcd.setCursor(index, 0);
        lcd.print(prnmbr2);
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 5)) {
        deunmbr2 = keypad;
        x = 6;
        index++;;
        lcd.setCursor(index, 0);
        lcd.print(deunmbr2);
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 6)) {
        troinmbr2 = keypad;
        x = 7;
        index++;
        lcd.setCursor(index, 0);
        lcd.print(troinmbr2);
        delay(d);
      }
      if ((x == 5) || (x == 6) || (x == 7)) {
        if (valuekeypad == 426) {
          operation2 = '+';
        }
        if (valuekeypad == 301) {
          operation2 = '-';
        }
        if (valuekeypad == 233) {
          operation2 = '/';
        }
        if (valuekeypad == 193) {
          operation2 = '*';
        }
      }
      if ((x == 5) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr2 = prnmbr2;
        index++;
        lcd.setCursor(index, 0);
        lcd.print(operation2);
        x = 8;
      }
      if ((x == 6) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr2 = (prnmbr2 * 10) + (deunmbr2 * 1);
        index++;
        lcd.setCursor(index, 0);
        lcd.print(operation2);
        x = 8;
      }
      if ((x == 7) && (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {
        lenmbr2 = (prnmbr2 * 100) + (deunmbr2 * 10) + (troinmbr2 * 1);
        index++;
        lcd.setCursor(index, 0);
        lcd.print(operation2);
        x = 8;
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 8)) {
        prnmbr3 = keypad;
        x = 9;
        index++;
        lcd.setCursor(index, 0);
        lcd.print(prnmbr3);
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 9)) {
        deunmbr3 = keypad;
        x = 10;
        index++;
        lcd.setCursor(index, 0);
        lcd.print(deunmbr3);
        delay(d);
      }
      /*DECLAREE*/
      keypad = -14848;
      valuekeypad = analogRead(A0);
      if (valuekeypad == 487) {
        keypad = 1;
      }
      if (valuekeypad == 465) {
        keypad = 2;
      }
      if (valuekeypad == 445) {
        keypad = 3;
      }
      if (valuekeypad == 330) {
        keypad = 4;
      }
      if (valuekeypad == 320) {
        keypad = 5;
      }
      if (valuekeypad == 310) {
        keypad = 6;
      }
      if (valuekeypad == 250) {
        keypad = 7;
      }
      if (valuekeypad == 244) {
        keypad = 8;
      }
      if (valuekeypad == 238) {
        keypad = 9;
      }
      if (valuekeypad == 197) {
        keypad = 0;
      }
      if ((keypad != -14848) && (x == 10)) {
        troinmbr3 = keypad;
        x = 11;
        index++;
        lcd.setCursor(index, 0);
        lcd.print(troinmbr3);
        delay(d);
      }
      if ((x == 5) && (valuekeypad == 189)) {
        lenmbr2 = prnmbr2;
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 12;
      }
      if ((x == 6) && (valuekeypad == 189)) {
        lenmbr2 = (prnmbr2 * 10) + (deunmbr2 * 1);
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 12;
      }
      if ((x == 7) && (valuekeypad == 189)) {
        lenmbr2 = (prnmbr2 * 100) + (deunmbr2 * 10) + (troinmbr2 * 1);
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 12;
      }
      if ((x == 9) && (valuekeypad == 189)) {
        lenmbr3 = prnmbr3;
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 13;
      }
      if ((x == 10) && (valuekeypad == 189)) {
        lenmbr3 = (prnmbr3 * 10) + (deunmbr3 * 1);
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 13;
      }
      if ((x == 11) && (valuekeypad == 189)) {
        lenmbr3 = (prnmbr3 * 100) + (deunmbr3 * 10) + (troinmbr3 * 1);
        lcd.setCursor(9, 1);
        lcd.print("=");
        x = 13;
      }
      if (x == 12) {
        if (operation == '+') {
          resulta = lenmbr1 + lenmbr2;
        }
        if (operation == '-') {
          resulta = lenmbr1 - lenmbr2;
        }
        if (operation == '/') {
          resulta = lenmbr1 / lenmbr2;
        }
        if (operation == '*') {
          resulta = lenmbr1 * lenmbr2;
        }
        if ((operation == '/') && (lenmbr2 == 0)) {
          lcd.setCursor(9, 1);
          lcd.print("Error");
        } else {
          lcd.setCursor(10, 1);
          lcd.print(resulta);
        }
      }
      if (x == 13) {
        if ((operation2 != '/') || (operation2 != '*')) {
          if (operation == '+') {
            resulta = lenmbr1 + lenmbr2;
          }
          if (operation == '-') {
            resulta = lenmbr1 - lenmbr2;
          }
        }
        if (operation == '/') {
          resulta = lenmbr1 / lenmbr2;
        }
        if (operation == '*') {
          resulta = lenmbr1 * lenmbr2;
        }
        if (operation2 == '+') {
          resulta2 = resulta + lenmbr3;
        }
        if (operation2 == '-') {
          resulta2 = resulta - lenmbr3;
        }
        if (operation2 == '/') {
          if ((operation == '+') && (operation2 == '/')) {
            resulta2 = (lenmbr2 / lenmbr3) + lenmbr1;
          } else {
            {
              resulta2 = resulta / lenmbr3;
            }
          }
          if ((operation == '-') && (operation2 == '/')) {
            resulta2 = ((lenmbr2 / lenmbr3) - lenmbr1) * -1;
          } else {
            resulta2 = resulta / lenmbr3;
          }
        }
        if (operation2 == '*') {
          if ((operation == '+') && (operation2 == '*')) {
            resulta2 = (lenmbr2 * lenmbr3) + lenmbr1;
          } else {
            resulta2 = resulta * lenmbr3;
          }
          if ((operation == '-') && (operation2 == '*')) {
            resulta2 = ((lenmbr2 * lenmbr3) - lenmbr1) * -1;
          } else {
            resulta2 = resulta * lenmbr3;
          }
        }
        if (((operation == '/') && (lenmbr2 == 0)) || ((operation2 == '/') && (lenmbr3 == 0))) {
          lcd.setCursor(9, 1);
          lcd.print("Error");
        } else {
          lcd.setCursor(10, 1);
          lcd.print(resulta2);
        }
      }
      if (valuekeypad == 201 || sswitch == 1) {
        sswitch = 0;
        prnmbr1 = 0;
        deunmbr1 = 0;
        troinmbr1 = 0;
        prnmbr2 = 0;
        deunmbr2 = 0;
        troinmbr2 = 0;
        prnmbr3 = 0;
        deunmbr3 = 0;
        troinmbr3 = 0;
        lenmbr1 = 0;
        lenmbr2 = 0;
        lenmbr3 = 0;
        x = 0;
        operation = ' ';
        operation2 = 0;
        resulta2 = 0;;
        index = 0;
        zid = 0;
        resulta = 0;
        lcd.clear();
      }
      while (y < 1) {
        mh = 0;
        y = 1;
      }
    }
  }
}