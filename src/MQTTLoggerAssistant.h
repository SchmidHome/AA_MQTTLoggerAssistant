#pragma once

#include <Assistant.h>
#include <Logger.h>
#include <MQTTassistant.h>

class MQTTLoggerAssistant : public Logger, public Assistant {
   public:
    /**
     * @brief Construct a new Serial Logger Assistant object
     * 
     * @param serial serial port to use
     * @param setup_serial if >0, then serial.begin(setup_serial) is called on setup
     * @param set_default if true, then deflogger is set to this object
     */
    MQTTLoggerAssistant(MQTTassistant& mqtt, String topic, bool set_as_default = true);
    void _setup();
    void _loop();

   private:
    MQTTassistant& mqtt;
    String topic;
};
