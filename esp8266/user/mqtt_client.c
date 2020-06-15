#include "ets_sys.h"
#include "osapi.h"
#include "mqtt.h"
#include "user_interface.h"
#include "mem.h"

MQTT_Client mqttClient;

#if TEST_MQTT_WAHYU
/**
 * @brief MQTT Data Test timer
 */
LOCAL os_timer_t mqttWahyu_timer;

/**
 * @brief MQTT Data Test
 */
void mqttWahyuTest(void){
    char var_mqtt[512];
    unsigned char lm35[1];

    os_get_random((unsigned char *)lm35, 2);
    os_printf("LM35 = %d\r\n",lm35[0]);

    os_sprintf(var_mqtt,"{\"nodeid\":\"esp8266-T\","\
                "\"signal\":0.4721340367221931,\"battery\":0.4806644371638398,\"context\":\"\","\
                "\"location\":{"\
                   "\"lat\":-7.283511242678959,"\
                   "\"long\":112.78932384338379,"\
                   "\"altitude\":289"\
                "},"\
                "\"sensor\":{"\
                   "\"temperature\":["\
                       "{\"sensorid\":\"esp8266_lm35\",\"value\":%d,\"context\":\"\"}"\
                    "]"\
                "}"\
              "}",lm35[0]);

    MQTT_Publish(&mqttClient, "device/esp8266", var_mqtt, os_strlen(var_mqtt), 0, 0);
}

/**
 * @brief MQTT Data Test Update handler
 */
LOCAL void ICACHE_FLASH_ATTR mqttWahyu_timer_handler(void *prv){
    mqttWahyuTest();
}
#endif

LOCAL void mqttConnectedCb(uint32_t *args){
    MQTT_Client* client = (MQTT_Client*)args;
    os_printf("MQTT: Connected\r\n");

#if TEST_MQTT_WAHYU
 #if SUBSCRIBE_CMD
  #if SUB_SAME_TOPIC
    MQTT_Subscribe(client, "device/esp8266", 0);
    os_printf("MQTT Subscribed: device/esp8266 \r\n");
  #else
    MQTT_Subscribe(client, "device/null", 0);
    os_printf("MQTT Subscribed: device/null \r\n");
  #endif
 #endif

    os_timer_disarm(&mqttWahyu_timer);
    os_timer_setfn(&mqttWahyu_timer, (os_timer_func_t *)mqttWahyu_timer_handler, NULL);
    os_timer_arm(&mqttWahyu_timer, 5000, 1);
#else
 #if SUBSCRIBE_CMD
    MQTT_Subscribe(client, "hello/world", 0);
 #endif
    MQTT_Publish(client, "hello/world", "hello_mqtt", 10, 0, 0);
#endif
}

LOCAL void mqttDisconnectedCb(uint32_t *args){
    MQTT_Client* client = (MQTT_Client*)args;
    os_printf("MQTT: Disconnected\r\n");
}

LOCAL void mqttPublishedCb(uint32_t *args){
    MQTT_Client* client = (MQTT_Client*)args;
    os_printf("MQTT: Published\r\n");
}

LOCAL void mqttDataCb(uint32_t *args, const char* topic, uint32_t topic_len, const char *data, uint32_t data_len){
    char *topicBuf = (char*)os_zalloc(topic_len+1),
            *dataBuf = (char*)os_zalloc(data_len+1);

    MQTT_Client* client = (MQTT_Client*)args;

    os_memcpy(topicBuf, topic, topic_len);
    topicBuf[topic_len] = 0;

    os_memcpy(dataBuf, data, data_len);
    dataBuf[data_len] = 0;

    os_printf("Receive topic: %s, data: %s \r\n", topicBuf, dataBuf);
    os_free(topicBuf);
    os_free(dataBuf);
}

void mqttWifiConnectCb(uint8_t status){
    if(status == STATION_GOT_IP){
        MQTT_Connect(&mqttClient);
    }
    else {
        MQTT_Disconnect(&mqttClient);
    }
}

void mqttClientInit(void){
#if TEST_MQTT_WAHYU
    MQTT_InitConnection(&mqttClient, "iot.elefante.co.id", 1883, 0);
#else
    MQTT_InitConnection(&mqttClient, "192.168.43.1", 1883, 0);
#endif
    MQTT_InitClient(&mqttClient, "esp8266", NULL, NULL, 120, 0);

    MQTT_OnConnected(&mqttClient, mqttConnectedCb);
    MQTT_OnDisconnected(&mqttClient, mqttDisconnectedCb);
    MQTT_OnPublished(&mqttClient, mqttPublishedCb);
    MQTT_OnData(&mqttClient, mqttDataCb);

    os_printf("MQTT Done!! \r\n");
}

