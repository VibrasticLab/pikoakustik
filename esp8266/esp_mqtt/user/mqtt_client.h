#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include "user_config.h"

#if TEST_MQTT_WAHYU
void mqttWahyuTest(void);
#endif

void mqttWifiConnectCb(uint8_t status);
void mqttClientInit(void);

#endif // MQTT_CLIENT_H
