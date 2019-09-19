#include "melody.h"

#define start  5 // switch destro (avvio melodia)
#define select  6 // switch sinistro (selezione melodia)
#define gate  7 // pin gate mosfet

#define numsong 9

int num = 0;
int pausenotes = 0;
int i = 0;

void setup()
{
  pinMode(gate, OUTPUT);
  digitalWrite(gate, LOW);
  pinMode(start, INPUT);
  pinMode(select, INPUT);
}

void suonaSuoneria(int* melodia, int* noteDurata, int durata, float pausa, int sizeMelodia) {

  for (int thisNote = 0; thisNote < sizeMelodia; thisNote++) {
    int noteDuration = durata / noteDurata[thisNote];
    tone(gate, melodia[thisNote], noteDuration);
    pausenotes = noteDuration * pausa;
    delay(pausenotes);
    noTone(gate);
  }
}

void loop()
{
  if (digitalRead(select)) {
    while (digitalRead(select)) delay(10);
    if (num >= numsong) num = 0;
    else num++;
  }

  switch (num) {

    case 0: // Clacson corriera
      if (digitalRead(start)) suonaSuoneria(melody1, noteDurations1, 1000, 1.30, (sizeof(melody1) / sizeof(melody1[0])));
      digitalWrite(gate, LOW);
      break;

    case 1: //Mario
      if (digitalRead(start)) suonaSuoneria(melody2, noteDurations2, 2000, 0.85, (sizeof(melody2) / sizeof(melody2[0])));
      digitalWrite(gate, LOW);
      break;

    case 2: // Tetris
      if (digitalRead(start)) suonaSuoneria(melody3, noteDurations3, 1000, 1.30, (sizeof(melody3) / sizeof(melody3[0])));
      digitalWrite(gate, LOW);
      break;

    case 3: // Seven nation army
      if (digitalRead(start)) suonaSuoneria(melody4, noteDurations4, 3200, 1.2, (sizeof(melody4) / sizeof(melody4[0])));
      digitalWrite(gate, LOW);
      break;

    case 4: //Natale
      if (digitalRead(start)) suonaSuoneria(melody5, noteDurations5, 1000, 1.50, (sizeof(melody5) / sizeof(melody5[0])));
      digitalWrite(gate, LOW);
      break;

    case 5: //L'amour toujours
      if (digitalRead(start)) suonaSuoneria(melody6, noteDurations6, 1000, 1.30, (sizeof(melody6) / sizeof(melody6[0])));
      digitalWrite(gate, LOW);
      break;

    case 6: // Natale
      if (digitalRead(start)) suonaSuoneria(melody7, noteDurations7, 800, 1.30, (sizeof(melody7) / sizeof(melody7[0])));
      digitalWrite(gate, LOW);
      break;

    case 7: // Hazard Dixie
      if (digitalRead(start)) suonaSuoneria(melody8, noteDurations8, 900, 1.30, (sizeof(melody8) / sizeof(melody8[0])));
      digitalWrite(gate, LOW);
      break;
  }
  delay(10);
}
