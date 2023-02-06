#include <RaKsRemoteControl.h>

/**
 * @brief Constructeur de la classe RaKsRemoteControl.
 * 
 * @param pin le numéro de la broche du récepteur infrarouge.
 */
RaKsRemoteControl::RaKsRemoteControl(int pin)
{
  debug = false;
  irReceiver = new IRrecv(pin);
}

void RaKsRemoteControl::init()
{
  irReceiver->enableIRIn();
}

void RaKsRemoteControl::setDebug(bool dbg)
{
  debug = dbg;
}

void RaKsRemoteControl::playground()
{

}

void RaKsRemoteControl::checkRemoteControl()
{
  if(irReceiver->decode(&irCode))
  {
    Serial.println(irCode.value, HEX);
    irReceiver->resume();
  }
  delay(100);
}

bool RaKsRemoteControl::hasSignal()
{
  return irReceiver->decode(&irCode);
}

void RaKsRemoteControl::resume()
{
  irReceiver->resume();
}

decode_results RaKsRemoteControl::getSignal()
{
  return irCode;
}

bool RaKsRemoteControl::isArrow()
{
  return (isArrowUp() || isArrowDown() || isArrowLeft() || isArrowRight());
}

bool RaKsRemoteControl::isArrowUp()
{
  return (irCode.value == KS_RC_ARROW_UP);
}

bool RaKsRemoteControl::isArrowDown()
{
  return (irCode.value == KS_RC_ARROW_DOWN);
}

bool RaKsRemoteControl::isArrowLeft()
{
  return (irCode.value == KS_RC_ARROW_LEFT);
}

bool RaKsRemoteControl::isArrowRight()
{
  return (irCode.value == KS_RC_ARROW_RIGHT);
}

bool RaKsRemoteControl::isKeyOk()
{
  return (irCode.value == KS_RC_OK);
}

bool RaKsRemoteControl::isKey0()
{
  return (irCode.value == KS_RC_KEY_0);
}

bool RaKsRemoteControl::isKey1()
{
  return (irCode.value == KS_RC_KEY_1);
}

bool RaKsRemoteControl::isKey2()
{
  return (irCode.value == KS_RC_KEY_2);
}

bool RaKsRemoteControl::isKey3()
{
  return (irCode.value == KS_RC_KEY_3);
}

bool RaKsRemoteControl::isKey4()
{
  return (irCode.value == KS_RC_KEY_4);
}

bool RaKsRemoteControl::isKey5()
{
  return (irCode.value == KS_RC_KEY_5);
}

bool RaKsRemoteControl::isKey6()
{
  return (irCode.value == KS_RC_KEY_6);
}

bool RaKsRemoteControl::isKey7()
{
  return (irCode.value == KS_RC_KEY_7);
}

bool RaKsRemoteControl::isKey8()
{
  return (irCode.value == KS_RC_KEY_8);
}

bool RaKsRemoteControl::isKey9()
{
  return (irCode.value == KS_RC_KEY_9);
}

bool RaKsRemoteControl::isKeyStar()
{
  return (irCode.value == KS_RC_STAR);
}

bool RaKsRemoteControl::isKeySharp()
{
  return (irCode.value == KS_RC_SHARP);
}

bool RaKsRemoteControl::isKeyNumber()
{
  return (isKey0() || isKey1() || isKey2() || isKey3() || isKey4() || isKey5() || isKey6() || isKey7() || isKey8() || isKey9());
}

bool RaKsRemoteControl::isKeyNumber(int num)
{
  switch(num)
  {
    case 0:
      return isKey0();
    case 1:
      return isKey1();
    case 2:
      return isKey2();
    case 3:
      return isKey3();
    case 4:
      return isKey4();
    case 5:
      return isKey5();
    case 6:
      return isKey6();
    case 7:
      return isKey7();
    case 8:
      return isKey8();
    case 9:
      return isKey9();
    default:
      return false;
  }
}