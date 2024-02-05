class button {
  public:
    button () {}
    button (byte pin) {
      _pin = pin;
      pinMode(_pin, INPUT); // _PULLUP
    }
    bool click() {
      bool btnState = digitalRead(_pin);

      if (btnState && !_flag) {  // обработчик нажатия
         _flag = true;
         return true;
         //Serial.println("press");
      }
      if (!btnState && _flag) {  // обработчик отпускания
         _flag = false;  
         //Serial.println("release");
      }
      
      /*if (!btnState && !_flag && millis() - _tmr >= 100) {
        _flag = true;
        _tmr = millis();
        return true;
      }
      if (!btnState && _flag && millis() - _tmr >= 500) {
        _tmr = millis ();
        return true;
      }
      if (btnState && _flag) {
        _flag = false;
        _tmr = millis();
      }*/
      return false;
    }
  private:
    byte _pin;
    //uint32_t _tmr;
    bool _flag;
};

button btn(sets.devs.btn.pin);

void btn_begin() {
  btn=button(sets.devs.btn.pin);
}

void btn_tick() {
  if(btn.click()) bb=!bb;
}
