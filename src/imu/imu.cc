#include "imu.h"
#include <MPU9250.h>
#include <Util.h>
#include <stdlib.h>

using namespace v8;

Persistent<Function> IMU::constructor;

IMU::IMU() {
  MPU9250 imuDevice;
  this->imu = imuDevice;
  imu.initialize();
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
    IMU* obj = new IMU();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `IMU(...)`, turn into construct call.
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    args.GetReturnValue().Set(cons->NewInstance());
  }
}

void IMU::getCurrentData() {
  this->imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
}

void IMU::getIMU(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  IMU* obj = ObjectWrap::Unwrap<IMU>(args.Holder());
  Local<Object> ret = Object::New(isolate); 

  obj->getCurrentData();

  ret->Set(String::NewFromUtf8(isolate, "ax"), Number::New(isolate, obj->ax));
  ret->Set(String::NewFromUtf8(isolate, "ay"), Number::New(isolate, obj->ay));
  ret->Set(String::NewFromUtf8(isolate, "az"), Number::New(isolate, obj->az));
  ret->Set(String::NewFromUtf8(isolate, "gx"), Number::New(isolate, obj->gx));
  ret->Set(String::NewFromUtf8(isolate, "gy"), Number::New(isolate, obj->gy));
  ret->Set(String::NewFromUtf8(isolate, "gz"), Number::New(isolate, obj->gz));
  ret->Set(String::NewFromUtf8(isolate, "mx"), Number::New(isolate, obj->mx));
  ret->Set(String::NewFromUtf8(isolate, "my"), Number::New(isolate, obj->my));
  ret->Set(String::NewFromUtf8(isolate, "mz"), Number::New(isolate, obj->mz));

  args.GetReturnValue().Set(ret);
}
