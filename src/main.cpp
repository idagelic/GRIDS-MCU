#include "main.h"

Data data;
// MQTTClient mqtt;
// Domain domain;

int tempNum = 5;

void setup()
{
    Serial.begin(9600);

    data.setup();

    // String wifiSsid = data.getConfigField("ssid");
    // String wifiPassword = data.getConfigField("password");
    // Serial.println(wifiSsid);
    // Serial.println(wifiPassword);

    // connectToMqtt();
}

void loop()
{
    delay(1000);
    // data.checkSerialInput();
    // mqtt.checkReconnect();
    // mqtt.loop();

    // delay(3000);
    // testFunctionalParameters();
}

// void testFunctionalParameters()
// {
//     const int jsonCapacity = JSON_OBJECT_SIZE(4);
//     DynamicJsonDocument jsonDoc(jsonCapacity);

//     // Create the JSON data
//     jsonDoc["pMaxActionThreshold"] = 2 * tempNum++;
//     jsonDoc["pMaxActionDelay"] = 4 * tempNum++;
//     jsonDoc["energyDeliveryStopDelay"] = 10 * tempNum++;
//     jsonDoc["energyMessageInterval"] = 20 * tempNum++;

//     domain.processFunctionParams(jsonDoc);

//     FunctionalParameters fp = domain.getFunctionalParameters();
//     Serial.println("pMaxActionThreshold: ");
//     Serial.println(fp.getPMaxActionThreshold());
//     Serial.println("pMaxActionDelay: ");
//     Serial.println(fp.getPMaxActionDelay());
//     Serial.println("energyDeliveryStopDelay: ");
//     Serial.println(fp.getEnergyDeliveryStopDelay());
//     Serial.println("Current message interval: ");
//     Serial.println(fp.getEnergyMessageInterval());
// }

// void connectToMqtt()
// {
//     String wifiSsid = data.getConfigField("ssid");
//     String wifiPassword = data.getConfigField("password");

//     String brokerUrl = data.getConfigField("mqttBrokerURL");
//     String port = data.getConfigField("mqttBrokerPort");
//     String username = data.getConfigField("mqttUser");
//     String password = data.getConfigField("mqttPass");
//     String uuid = data.getConfigField("uuid");
//     String certificate = data.getRootCA();

//     mqtt.uuid = uuid;

//     mqtt.connectToWiFi(wifiSsid.c_str(), wifiPassword.c_str());
//     mqtt.connect(brokerUrl.c_str(), atoi(port.c_str()), username.c_str(), password.c_str(), certificate.c_str());
// }