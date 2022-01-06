#include "MQTTLoggerAssistant.h"

// -------------------------------------------------------------------------------- MQTTLoggerAssistant
MQTTLoggerAssistant::MQTTLoggerAssistant(MQTTassistant& mqtt, String topic, bool set_as_default)
    : Logger(set_as_default), Assistant(), mqtt(mqtt), topic(topic) {}

void MQTTLoggerAssistant::_setup() {
    _loop();
}

void MQTTLoggerAssistant::_loop() {
    if (!buffer_empty() && mqtt.connected()) {
        if (mqtt.send(topic, logger_buffer))
            if (buffer_full())
                create_overflow_message();
            else
                clear_buffer();
        else
            WARN("MQTT send failed");
    }
}
