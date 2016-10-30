#include "imu.h"
#include <MPU9250.h>
#include <Util.h>
#include <stdlib.h>

using namespace v8;

Persistent<Function> IMU::constructor;

IMU::IMU() {
  // static const uint8_t outputEnablePin = RPI_GPIO_27;
  // Pin pin(outputEnablePin);
  // if (pin.init()) {
  //     pin.setMode(Pin::GpioModeOutput);
  //     pin.write(0);  drive Output Enable low 
  // } else {
  //     fprintf(stderr, "Output Enable not set. Are you root?\n");
  // }
  MPU9250 imuDevice;
  this->imu = imuDevice;
  imu.initialize();
  // IMU.setFrequency(FREQUENCY);
  // this->IMUInterface = IMU;
}

IMU::~IMU() {
}

void IMU::Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "IMU"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "getIMU", getIMU);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "IMU"),
               tpl->GetFunction());
}

void IMU::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new IMU(...)`
    // double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    IMU* obj = new IMU();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `IMU(...)`, turn into construct call.
    // const int argc = 1;
    // Local<Value> argv[argc] = { args[0] };
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    args.GetReturnValue().Set(cons->NewInstance());
  }
}

float IMU::getCurrentData() {
  float ax, ay, az, gx, gy, gz, mx, my, mz;
  this->imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  printf("Acc: %+7.3f %+7.3f %+7.3f  ", ax, ay, az);
  printf("Gyr: %+8.3f %+8.3f %+8.3f  ", gx, gy, gz);
  printf("Mag: %+7.3f %+7.3f %+7.3f\n", mx, my, mz);
  return mx;
}

void IMU::getIMU(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  IMU* obj = ObjectWrap::Unwrap<IMU>(args.Holder());

  // float channel = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  // float ms = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
  // float ms_3 = args[2]->IsUndefined() ? 0 : args[2]->NumberValue();
  // float ms_4 = args[3]->IsUndefined() ? 0 : args[3]->NumberValue();

  Local<Array> ret = Array::New(isolate, 1); 
ret.Set(0, String::New("őúűáéöüó")); 

return scope.Close(ret); 

  // float derp;
  // derp = obj->getCurrentData();

  // args.GetReturnValue().Set(Number::New(isolate, derp));
}
