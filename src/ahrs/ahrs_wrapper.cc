#include <node.h>
#include "ahrs.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  AHRS::Init(exports);
}

NODE_MODULE(ahrs, InitAll)
