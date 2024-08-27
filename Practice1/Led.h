class LED {
  private:
    int pin;

  public:
    LED(int pin) {
      this->pin = pin;
      pinMode(pin, OUTPUT);
    }

    void on() {
      digitalWrite(pin, HIGH);
    }

    void off() {
      digitalWrite(pin, LOW);
    }
};
