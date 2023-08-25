#include "actions.h"

Actions::Actions() {}

int Actions::test1()
{
    return 456;
}

void Actions::processMessage(String uuid, char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    int uuidLength = uuid.length();
    char uuidCharArray[37];
    uuid.toCharArray(uuidCharArray, sizeof(uuidCharArray));
    char tempUuidCharArray[37];
    strcpy(tempUuidCharArray, uuidCharArray);

    // Parse JSON data
    Serial.println("test1");
    DynamicJsonDocument doc(1024);
    Serial.println("test2");
    DeserializationError error = deserializeJson(doc, payload, length);
    Serial.println("test3");

    if (error)
    {
        Serial.println("test4");
        Serial.print("JSON parsing error: ");
        Serial.println(error.c_str());
        return;
    }
    Serial.println("test5");

    Serial.println(uuidCharArray);
    Serial.println(uuid);
    Serial.println("test6");

    // Forward topic data to respective function

    // Check if message is on init-session topic
    if (strcmp(topic, strcat(tempUuidCharArray, SESSION_INIT)) == 0)
    {
        // get each json field and send them separately to domain

        // Serial.print("p_max was: ");
        // Serial.println(domain.pMax);

        // float max_power = doc["max_power"];
        // domain.setPMax(max_power);
        // // p_max = max_power;
        // // p_tmax = max_power;
        // Serial.print("p_max set to: ");
        // Serial.println(domain.pMax);
    }
    memset(tempUuidCharArray, 0, sizeof(tempUuidCharArray));
    strcpy(tempUuidCharArray, uuidCharArray);

    Serial.println("test7");

    // Check if message is on update-session topic
    if (strcmp(topic, strcat(tempUuidCharArray, "commands/update-session")) == 0)
    {
        // int max_power = doc["max_power"];
        // int duration = doc["duration"];
        // p_tmax = max_power;
        // timeout = duration * 1000;
        // start_time = millis();
        // Serial.print("p_tmax set to: ");
        // Serial.println(p_tmax);
        // Serial.print("timeout set to: ");
        // Serial.println(timeout);
    }
    memset(tempUuidCharArray, 0, sizeof(tempUuidCharArray));
    strcpy(tempUuidCharArray, uuidCharArray);

    if (strcmp(topic, strcat(tempUuidCharArray, RELAY_TEST_ON)) == 0)
    {
        Serial.println("Pin 1 on.");
        digitalWrite(PIN_REL1, HIGH); // Replace with real pin number
    }
    memset(tempUuidCharArray, 0, sizeof(tempUuidCharArray));
    strcpy(tempUuidCharArray, uuidCharArray);

    if (strcmp(topic, strcat(tempUuidCharArray, RELAY_TEST_OFF)) == 0)
    {
        Serial.println("Pin 1 off.");
        digitalWrite(PIN_REL1, LOW); // Replace with real pin number
    }
    memset(tempUuidCharArray, 0, sizeof(tempUuidCharArray));
    strcpy(tempUuidCharArray, uuidCharArray);

    if (strcmp(topic, strcat(tempUuidCharArray, RELAY_TEST_KICK)) == 0)
    {
        Serial.println("Kicking pin 2");
        digitalWrite(PIN_REL2, LOW); // Replace with real pin number
    }
    memset(tempUuidCharArray, 0, sizeof(tempUuidCharArray));
    strcpy(tempUuidCharArray, uuidCharArray);

    Serial.println(tempUuidCharArray);
}