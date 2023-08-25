#include "actions.h"

Actions *Actions::instance = nullptr;

Actions::Actions()
{
    instance = this;
}

void Actions::processMessage(String uuid, char *topic, byte *payload, unsigned int length)
{
    int i = 0;
    int uuidLength = uuid.length();
    char uuidCharArray[37];
    char uuidCharArrayCopy[37];

    String topicString = String(topic);

    int topicUuidPos = topicString.indexOf(TOPIC_DELIMITER);
    if (topicUuidPos == -1)
        return; // UUID not found

    String topicUuid = topicString.substring(0, topicUuidPos);

    if (topicUuid != uuid)
        return; // Wrong UUID specified

    String topicCommand = topicString.substring(topicUuidPos + 1);
    topicCommand = TOPIC_DELIMITER + topicCommand; // Add delimiter

    uuid.toCharArray(uuidCharArray, sizeof(uuidCharArray));
    strcpy(uuidCharArrayCopy, uuidCharArray);

    // Parse JSON data
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, payload, length);

    if (error)
    {
        Serial.print("JSON parsing error: ");
        Serial.println(error.c_str());
        return;
    }

    Serial.println(topicUuid);
    Serial.println(topicCommand);

    // Forward topic data to respective function

    if (topicCommand == RELAY_TEST_ON)
    {
        Serial.println("Pin 1 on.");
        digitalWrite(PIN_REL1, HIGH); // Replace with real pin number
    }

    if (topicCommand == RELAY_TEST_OFF)
    {
        Serial.println("Pin 1 off.");
        digitalWrite(PIN_REL1, LOW); // Replace with real pin number
    }

    if (topicCommand == RELAY_TEST_KICK)
    {
        Serial.println("Pin 2 kick.");
        digitalWrite(PIN_REL2, HIGH); // Replace with real pin number
    }

    if (topicCommand == FUNCTION_PARAMS)
    {
        instance->domain.processFunctionParams(doc);
        Serial.println(instance->domain.getFunctionalParameters().getEnergyMessageInterval());
    }

    // while (READ_TOPICS[i] != nullptr)
    // {
    //     if (strcmp(topic, strcat(uuidCharArrayCopy, READ_TOPICS[i])) == 0)
    //     {
    //         // get each json field and send them separately to domain

    //         // Serial.print("p_max was: ");
    //         // Serial.println(domain.pMax);

    //         // float max_power = doc["max_power"];
    //         // domain.setPMax(max_power);
    //         // // p_max = max_power;
    //         // // p_tmax = max_power;
    //         // Serial.print("p_max set to: ");
    //         // Serial.println(domain.pMax);

    //         memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    //         strcpy(uuidCharArrayCopy, uuidCharArray);
    //         break;
    //     }
    // }

    // // Check if message is on init-session topic
    // if (strcmp(topic, strcat(uuidCharArrayCopy, SESSION_INIT)) == 0)
    // {
    //     // get each json field and send them separately to domain

    //     // Serial.print("p_max was: ");
    //     // Serial.println(domain.pMax);

    //     // float max_power = doc["max_power"];
    //     // domain.setPMax(max_power);
    //     // // p_max = max_power;
    //     // // p_tmax = max_power;
    //     // Serial.print("p_max set to: ");
    //     // Serial.println(domain.pMax);
    // }
    // memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    // strcpy(uuidCharArrayCopy, uuidCharArray);

    // Serial.println("test7");

    // // Check if message is on update-session topic
    // if (strcmp(topic, strcat(uuidCharArrayCopy, "commands/update-session")) == 0)
    // {
    //     // int max_power = doc["max_power"];
    //     // int duration = doc["duration"];
    //     // p_tmax = max_power;
    //     // timeout = duration * 1000;
    //     // start_time = millis();
    //     // Serial.print("p_tmax set to: ");
    //     // Serial.println(p_tmax);
    //     // Serial.print("timeout set to: ");
    //     // Serial.println(timeout);
    // }
    // memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    // strcpy(uuidCharArrayCopy, uuidCharArray);

    // if (strcmp(topic, strcat(uuidCharArrayCopy, RELAY_TEST_ON)) == 0)
    // {
    //     Serial.println("Pin 1 on.");
    //     digitalWrite(PIN_REL1, HIGH); // Replace with real pin number
    // }
    // memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    // strcpy(uuidCharArrayCopy, uuidCharArray);

    // if (strcmp(topic, strcat(uuidCharArrayCopy, RELAY_TEST_OFF)) == 0)
    // {
    //     Serial.println("Pin 1 off.");
    //     digitalWrite(PIN_REL1, LOW); // Replace with real pin number
    // }
    // memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    // strcpy(uuidCharArrayCopy, uuidCharArray);

    // if (strcmp(topic, strcat(uuidCharArrayCopy, RELAY_TEST_KICK)) == 0)
    // {
    //     Serial.println("Kicking pin 2");
    //     digitalWrite(PIN_REL2, LOW); // Replace with real pin number
    // }
    // memset(uuidCharArrayCopy, 0, sizeof(uuidCharArrayCopy));
    // strcpy(uuidCharArrayCopy, uuidCharArray);

    // Serial.println(uuidCharArrayCopy);

    instance->domain.test11();
}