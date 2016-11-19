//
//
//
// Many many MANY thanks to Scott Frees for the awesome library
// and code examples!
//
// https://github.com/freezer333/streaming-worker
//
//
//
#include <functional>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "streaming-worker.h"
#include "json.hpp" //https://github.com/nlohmann/json
#include "ahrs.cc" // Main AHRS class

using namespace std;
using json = nlohmann::json;


class AHRSInterface : public StreamingWorker {
  public:
    AHRSInterface(Callback *data, Callback *complete, Callback *error_callback,  v8::Local<v8::Object> & options) 
      : StreamingWorker(data, complete, error_callback){

        name = "Mahony Algorithm AHRS";
        
        if (options->IsObject() ) {
          v8::Local<v8::Value> name_ = options->Get(New<v8::String>("name").ToLocalChecked());
          if ( name_->IsString() ) {
            v8::String::Utf8Value s(name_);
            name = *s;
          }
        }
      }

    void sendData(const AsyncProgressWorker::ExecutionProgress& progress, float roll, float pitch, float yaw) {
      json ahrsState;
      ahrsState["sensor"] = name;
      ahrsState["position"]["roll"] = roll;
      ahrsState["position"]["pitch"] = pitch;
      ahrsState["position"]["yaw"] = yaw;
      Message message("position_sample", ahrsState.dump());
      writeToNode(progress, message);
    }
    
    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {

      auto callback = [this, &progress](float roll, float pitch, float yaw) { 
        this->sendData(progress, roll, pitch, yaw);
      };

      this->ahrs.imuSetup();

      int ahrsLoopInterval = 1; // Interval calucaltions are performed in ms
      int callbackInterval = 10; // Interval results are sent in ms

      while (!closed()) {

        this->ahrs.imuLoop(callback, callbackInterval);

        std::this_thread::sleep_for(chrono::milliseconds(ahrsLoopInterval));
      }
    }
  private:
    string name;
    AHRS ahrs;
};

StreamingWorker * create_worker(Callback *data
    , Callback *complete
    , Callback *error_callback, v8::Local<v8::Object> & options) {
  return new AHRSInterface(data, complete, error_callback, options);
}

NODE_MODULE(sensor_sim, StreamWorkerWrapper::Init)
