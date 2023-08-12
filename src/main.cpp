#include "main.h"

Data data;
MQTTClient mqtt;

void setup()
{
    Serial.begin(9600);

    data.setup();

    String ssid = data.getConfigField("ssid");
    String password = data.getConfigField("password");
    connectToWiFi(ssid.c_str(), password.c_str());

    connectToMqtt();
}

void loop()
{
    checkMqttConnection();

    // if (!mqttClient.connected())
    // {
    //     mqttClient.mqttReconnect();
    // }
    // mqttClient.loop();
    // data.checkSerialInput();
    // String ssid = data.getConfigField("ssid");
    // String password = data.getConfigField("password");
    // checkWifiConnection(ssid.c_str(), password.c_str());

    // // Todo: Create "check mqtt connection"...
    // mqtt.reconnect();

    mqtt.loop();

    // delay(1000);

    // mqtt.publish("test", "1");
}

void connectToMqtt()
{
    String brokerUrl = data.getConfigField("mqttBrokerURL");
    String port = data.getConfigField("mqttBrokerPort");
    String username = data.getConfigField("mqttUser");
    String password = data.getConfigField("mqttPass");
    String uuid = data.getConfigField("uuid");
    String certificate = data.getRootCA();

    mqtt.uuid = uuid;

    mqtt.connect(brokerUrl.c_str(), atoi(port.c_str()), username.c_str(), password.c_str(), certificate.c_str());
}

void checkMqttConnection()
{
    mqtt.checkReconnect();
}