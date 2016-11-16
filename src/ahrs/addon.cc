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

        name = "Mahony AHRS";

        if (options->IsObject() ) {
          v8::Local<v8::Value> name_ = options->Get(New<v8::String>("name").ToLocalChecked());
          if ( name_->IsString() ) {
            v8::String::Utf8Value s(name_);
            name = *s;
          }
        }
      }

    void send_data(const AsyncProgressWorker::ExecutionProgress& progress, float roll, float pitch, float yaw) {
      json sample;
      sample["sensor"] = name;
      sample["position"]["roll"] = roll;
      sample["position"]["pitch"] = pitch;
      sample["position"]["yaw"] = yaw;
      Message tosend("position_sample", sample.dump());
      writeToNode(progress, package);
    }

    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {

      //
      //
      // I do NOT like ow deep these references go.
      // Fix this shit.
      //
      //
      float roll;
      float pitch;
      float yaw;

      this->ahrs.imuSetup();
      while (!closed()) {
        // Get it
        this->ahrs.imuLoop(&roll, &pitch, &yaw);
        // Send it
        send_data(progress, roll, pitch, yaw);
        // Good things come to those who wait
        std::this_thread::sleep_for(chrono::milliseconds(10));
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
