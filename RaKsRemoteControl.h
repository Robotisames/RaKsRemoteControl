#include <Arduino.h>
#include <IRremote.h>

#define KS_RC_ARROW_UP 0xFF629D
#define KS_RC_ARROW_DOWN 0xFFA857
#define KS_RC_ARROW_LEFT 0xFF22DD
#define KS_RC_ARROW_RIGHT 0xFFC23D
#define KS_RC_OK 0xFF02FD
#define KS_RC_KEY_0 0xFF4AB5
#define KS_RC_KEY_1 0xFF6897
#define KS_RC_KEY_2 0xFF9867
#define KS_RC_KEY_3 0xFFB04F
#define KS_RC_KEY_4 0xFF30CF
#define KS_RC_KEY_5 0xFF18E7
#define KS_RC_KEY_6 0xFF7A85
#define KS_RC_KEY_7 0xFF10EF
#define KS_RC_KEY_8 0xFF38C7
#define KS_RC_KEY_9 0xFF5AA5
#define KS_RC_STAR 0xFF42BD
#define KS_RC_SHARP 0xFF52AD

class RaKsRemoteControl
{
private:
  bool debug;
  IRrecv* irReceiver;
  decode_results irCode;
  int pin;

public:
  RaKsRemoteControl(int pin);

  // Init
  void init();

  // Debug
  void setDebug(bool dbg);
  void playground();

  void checkRemoteControl();
  bool hasSignal();
  decode_results getSignal();
  void resume();

  bool isArrow();
  bool isArrowUp();
  bool isArrowDown();
  bool isArrowLeft();
  bool isArrowRight();
  bool isKeyOk();
  bool isKey0();
  bool isKey1();
  bool isKey2();
  bool isKey3();
  bool isKey4();
  bool isKey5();
  bool isKey6();
  bool isKey7();
  bool isKey8();
  bool isKey9();
  bool isKeyStar();
  bool isKeySharp();
  bool isKeyNumber();
  bool isKeyNumber(int num);
};
