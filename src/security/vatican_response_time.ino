#include <SPI.h>
#include <df_can.h> //dfrobots
#include <EEPROM.h> // read written ID in the EEPROM
#include "vatican.h"

#define TIMEOUT 500000 // 500 ms timeout
const int SPI_CS_PIN = 10;

MCPCAN can(SPI_CS_PIN); // Set CS pin
VatiCAN secure("swordfish", VATICAN_FAVOUR_PERFORMANCE, can, NONCE_ID); // 128-bit key

unsigned long pingStart;    // Start time for request
unsigned long responseTime; // Time taken for a valid response
bool WaitingForReply = false;

void setup() {
    Serial.begin(115200);
    while (!Serial); // Wait for Serial Monitor
    
    if (can.begin(CAN_500KBPS) == CAN_OK) {
        Serial.println("CAN Bus initialized successfully.");
    } else {
        Serial.println("CAN Bus initialization failed.");
        while (1); // Stop execution
    }
    
    secure.AddVatiCANChannel(SECURE_RPM, SECURE_RPM + 1); // Example channel setup
}

void loop() {
    uint8_t samplePayload[] = {0x02, 0x01, 0x0C, 0x55, 0x55, 0x55, 0x55, 0x55};
    unsigned long currentTime = millis();

    if (!WaitingForReply) {
        // Send request
        pingStart = micros(); // Record the start time
        can.sendMsgBuf(0x7df, 0, sizeof(samplePayload), samplePayload);
        Serial.println("Request sent...");
        WaitingForReply = true;
    }

    // Check for response
    if (WaitingForReply) {
        uint8_t len = 0;
        uint8_t buf[8];
        if (can.checkReceive() == CAN_MSGAVAIL) {
            can.readMsgBuf(&len, buf);
            unsigned long endTime = micros(); // Record the end time
            WaitingForReply = false;

            // Process response
            Serial.print("Response received: ");
            for (int i = 0; i < len; i++) {
                Serial.print(buf[i], HEX);
                Serial.print(" ");
            }
            Serial.println();

            // Calculate elapsed time
            responseTime = endTime - pingStart;
            Serial.print("Time to receive response: ");
            Serial.print(responseTime);
            Serial.println(" microseconds.");
        }
    }

    // Handle timeout
    if (WaitingForReply && (micros() - pingStart > TIMEOUT)) {
        Serial.println("No reply within timeout period.");
        WaitingForReply = false;
    }

    delay(100); // Small delay to prevent excessive polling
}
