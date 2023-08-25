#include "main.h"

Data data;
MQTTClient mqtt;
Actions actions;

void setup()
{
    Serial.begin(9600);

    data.setup();

    connectToMqtt();
    mqtt.actions = actions;
}

void loop()
{
    data.checkSerialInput();
    // mqtt.checkReconnect();
    mqtt.loop();
}

void connectToMqtt()
{
    String wifiSsid = data.getConfigField("ssid");
    String wifiPassword = data.getConfigField("password");

    String brokerUrl = data.getConfigField("mqttBrokerURL");
    String port = data.getConfigField("mqttBrokerPort");
    String username = data.getConfigField("mqttUser");
    String password = data.getConfigField("mqttPass");
    String uuid = data.getConfigField("uuid");
    String certificate = data.getRootCA();

    mqtt.uuid = uuid;

    mqtt.initWifiConnection(wifiSsid.c_str(), wifiPassword.c_str());
    mqtt.connect(brokerUrl.c_str(), atoi(port.c_str()), username.c_str(), password.c_str(), certificate.c_str());
}