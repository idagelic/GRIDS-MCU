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
}