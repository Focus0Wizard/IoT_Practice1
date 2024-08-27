class LED {
  private:
    const unsigned char OFF = 0;
    const unsigned char ON = 1;
    unsigned char pin;
    unsigned int interval;
    unsigned long previousMillis;
    unsigned char state;
    unsigned char isBlinking;

  public:
    LED(unsigned char pin) {
      this->pin = pin;
      previousMillis = 0;
      pinMode(pin, OUTPUT);
      off();
    }

    void off() {
      state = OFF;
      isBlinking = 0;
      digitalWrite(pin, state);
    }

    void on() {
      state = ON;
      isBlinking = 0;
      digitalWrite(pin, state);
    }

    void blink(unsigned int interval) {
      this->interval = interval;
      isBlinking = 1;
      state = OFF;
      digitalWrite(pin, state);
    }

    void touch() {
      if (isBlinking) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
          previousMillis = currentMillis;
          state = (state == OFF) ? ON : OFF;
          digitalWrite(pin, state);
        }
      }
    }
};
