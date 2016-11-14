#ifndef IMU_H
#define IMU_H

#include <node.h>
#include <node_object_wrap.h>

#include <MPU9250.h>
#include "mahony.hpp"

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
    float roll, pitch, yaw;
    float offset[3];
    struct timeval tv;
    float dt, maxdt;
    float mindt;
    unsigned long previoustime, currenttime;
    float dtsumm;
    int isFirst;
  private:
    explicit IMU();
    ~IMU();
    MPU9250 imu;
    MAHONY ahrs;
    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void getData(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;
    // void getCurrentAHRSOutput();
};

#endif
