#include <node.h>
#include "imu.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  IMU::Init(exports);
}

NODE_MODULE(imu, InitAll)
