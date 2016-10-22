// #####################
// Placeholder for prototype
#define FREQUENCY 50
// ######################

#include "pwm.h"
#include <gpio.h>
#include <Util.h>

using namespace v8;
using namespace Navio;

Persistent<Function> PWM::constructor;

PWM::PWM() {
  static const uint8_t outputEnablePin = RPI_GPIO_27;
  Pin pin(outputEnablePin);
  if (pin.init()) {
      pin.setMode(Pin::GpioModeOutput);
      pin.write(0); /* drive Output Enable low */
  } else {
      fprintf(stderr, "Output Enable not set. Are you root?\n");
  }

  PCA9685 pwm;
  pwm.initialize();
  pwm.setFrequency(FREQUENCY);
  this->pwmInterface = pwm;
}

PWM::~PWM() {
}

void PWM::Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "PWM"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "setPWM", setPWM);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "PWM"),
               tpl->GetFunction());
}

void PWM::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new PWM(...)`
    // double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    PWM* obj = new PWM();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `PWM(...)`, turn into construct call.
    // const int argc = 1;
    // Local<Value> argv[argc] = { args[0] };
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    args.GetReturnValue().Set(cons->NewInstance());
  }
}

void PWM::reallySetPWM(double channel, double ms) {
  this->pwmInterface.setPWMuS(channel, ms);
}

void PWM::setPWM(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  PWM* obj = ObjectWrap::Unwrap<PWM>(args.Holder());

  float channel = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  float ms = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
  // float ms_3 = args[2]->IsUndefined() ? 0 : args[2]->NumberValue();
  // float ms_4 = args[3]->IsUndefined() ? 0 : args[3]->NumberValue();

  // printf("values %f ## %f ## %f ## %f", ms_1, ms_2, ms_3, ms_4);

  obj->reallySetPWM(channel, ms);

  args.GetReturnValue().Set(Boolean::New(isolate, true));
}
