#ifndef PWM_H
#define PWM_H

#include <node.h>
#include <node_object_wrap.h>

#include <PCA9685.h>

class PWM : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);

 private:
  explicit PWM();
  ~PWM();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void setPWM(const v8::FunctionCallbackInfo<v8::Value>& args);
  static v8::Persistent<v8::Function> constructor;
  PCA9685 pwmInterface;
  void reallySetPWM(double channel, double ms);
};

#endif
