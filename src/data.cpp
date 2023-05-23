#include "data.h"

const char *configFieldList[] = {
    "ssid",
    "password",
    "mqttBrokerURL",
    "mqttBrokerPort",
    "mqttUser",
    "mqttPass",
    "mqttCert",
};

Data::Data() {}

void Data::setup()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("Failed to mount SPIFFS");
        return;
    }

    if (SPIFFS.exists(configFileName))
    {
        File configFile = SPIFFS.open(configFileName, "r");
        if (!configFile)
        {
            Serial.println("Failed to open config file for reading");
            return;
        }

        size_t size = configFile.size();
        std::unique_ptr<char[]> buf(new char[size]);
        configFile.readBytes(buf.get(), size);
        configFile.close();

        DynamicJsonDocument doc(jsonCapacity);
        DeserializationError error = deserializeJson(doc, buf.get());

        if (error)
        {
            Serial.print("Failed to parse config file: ");
            Serial.println(error.c_str());
            return;
        }

        // Serialize the JSON document to a string
        String jsonString;
        serializeJson(doc, jsonString);

        // Update the configuration based on the loaded values
        // updateConfig(jsonString.c_str());
    }
    else
    {
        Serial.println("Config file not found, using default values");
    }
}

void Data::loop()
{
}

void Data::updateConfig(const char *newLine)
{
    File configFile = SPIFFS.open(configFileName, "r");
    File tempFile = SPIFFS.open("/temp.txt", "w");

    if (!configFile || !tempFile)
    {
        Serial.println("Failed to open config file for reading");
        return;
    }

    while (configFile.available())
    {
        String line = configFile.readStringUntil('\n');
        char *replacementLine = strdup(newLine);
        char *fieldName = strtok(replacementLine, "=");

        if (line.startsWith(fieldName))
        {
            Serial.println("Adding new line to config.");
            tempFile.println(newLine);
        }
        else
        {
            tempFile.println(line);
        }
    }

    tempFile.close();
    configFile.close();

    SPIFFS.remove(configFileName);
    SPIFFS.rename("/temp.txt", configFileName);

    return;
}

String Data::readConfig(const char *fieldName)
{
    File configFile = SPIFFS.open(configFileName, "r");
    if (!configFile)
    {
        Serial.println("Failed to open config file for reading");
        return "";
    }

    while (configFile.available())
    {
        String line = configFile.readStringUntil('\n');

        if (line.startsWith(fieldName))
        {
            char *token = strtok(strdup(line.c_str()), "="); // Get the first token
            token = strtok(NULL, "=");                       // Get second token

            // Remove the semicolon from the token
            char *semicolonPos = strchr(token, ';');
            if (semicolonPos != NULL)
            {
                *semicolonPos = '\0'; // Replace semicolon with null character
            }

            return token;
        }
    }
    return "";
    configFile.close();
}

void Data::checkSerialInput()
{
    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('\n');

        if (input.startsWith("+++"))
        {
            String data = input.substring(3);
            updateConfig(data.c_str());
        }
        else if (input.startsWith("***"))
        {
            String fieldName = input.substring(3);
            readConfig(fieldName.c_str());
        }
    }
}

String Data::getConfigField(const char *fieldName)
{
    return readConfig(fieldName);
}

String Data::getRootCA()
{
    File caFile = SPIFFS.open("/root_ca.txt", "r");
    String response;

    if (!caFile)
    {
        Serial.println("Failed to open CA file for reading");
        return "";
    }

    while (caFile.available())
    {
        response = caFile.readString();
    }

    caFile.close();

    return response;
}

bool Data::checkDataReady()
{
    bool check = true;
    size_t dataCount = sizeof(configFieldList) / sizeof(configFieldList[0]);
    for (int i = 0; i < dataCount; i++)
    {
        if (getConfigField(configFieldList[i]) == "")
        {
            check = false;
        }
    }
    return check;
}