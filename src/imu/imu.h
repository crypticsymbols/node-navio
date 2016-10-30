#ifndef IMU_H
#define IMU_H

#include <node.h>
#include <node_object_wrap.h>

#include <MPU9250.h>

class IMU : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
  float mx;
  float my;
  float mz;

 private:
  explicit IMU();
  ~IMU();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void getIMU(const v8::FunctionCallbackInfo<v8::Value>& args);
  static v8::Persistent<v8::Function> constructor;
  MPU9250 imu;
  void getCurrentData();
};

#endif
