#include <Arduino.h>
#include "fakeDMA.h"

#define pinANALOG A5 // Configura o pino de leitura
#define GAIN 1
#define OFFSET 0
uint32_t timeStampMS = 0;

void setup() {
    Serial.begin(9600);
    fakeDMA_init(pinANALOG);  // usar pino A0
    fakeDMA_start();
}

void loop() {
    if (fakeDMA_available()) {
        Serial.print(">graf:");
        Serial.print(timeStampMS++);
        Serial.print(":");
        Serial.print(GAIN*fakeDMA_read()+OFFSET);
        Serial.println("|g");
    }
    // loop livre para outras tarefas
}