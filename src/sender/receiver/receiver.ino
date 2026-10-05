#include <SPI.h>
#include "df_can.h"

const int SPI_CS_PIN = 10;

MCPCAN CAN(SPI_CS_PIN);

unsigned char len = 0;
unsigned char buf[8];

void setup() {

    Serial.begin(115200);

    int count = 50;

    do {
        CAN.init();

        if (CAN_OK == CAN.begin(CAN_500KBPS)) {
            Serial.println("CAN Bus Shield initialized successfully.");
            break;
        } else {
            Serial.println("CAN Bus Shield initialization failed.");
            Serial.println("Retrying...");

            delay(1000);

            if (count <= 1) {
                Serial.println("CAN initialization failed.");
            }
        }

    } while (count--);
}

void loop() {

    if (CAN.checkReceive() == CAN_MSGAVAIL) {

        CAN.readMsgBuf(&len, buf);

        unsigned long canId = CAN.getCanId();

        Serial.println("Receiver: CAN message received");

        Serial.print("CAN ID: 0x");
        Serial.println(canId, HEX);

        Serial.print("Length: ");
        Serial.println(len);

        Serial.print("Payload: ");

        for (int i = 0; i < len; i++) {
            Serial.print(buf[i], HEX);
            Serial.print(" ");
        }

        Serial.println();
        Serial.println();
    }
}
