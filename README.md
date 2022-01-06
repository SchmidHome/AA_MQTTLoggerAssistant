# Serial logger for Arduino env

# USAGE
```c++
SerialLoggerAssistant logger(Serial, 9600); // sets logger as default as third argument is true per default
//! not yet possible: SerialLoggerAssistant logger2(Serial2, 0, false); // second logger which is not set up per default

void some_function_to_be_logged(int a_value){
    LOG("TESTMESSAGE " + (String)a_value + " that will land on the default logger");
    WARN("TESTWARNING which starts with 'WARN: '");
    ERR("TESTERROR which starts with 'ERR: '");
    ASSERT_ERR(a_value == 0, "ERRORMESSAGE that will show if a_value is not 0");
    ASSERT_WARN(a_value == 0, "WARNMESSAGE that will show if a_value is not 0 and automatically set it to 0", a_value = 0);
}

void setup() {
    logger.setup();
    //! logger2.setup();
    // or just use Assistant::setupAll();
    Serial2.begin(115200); // this has to be done only for logger2, as second argument is 0 (so no automatic setup)
}
void loop() {
    logger.loop();
    //! logger2.loop();
    // or just use Assistant::loopAll();

}

```
