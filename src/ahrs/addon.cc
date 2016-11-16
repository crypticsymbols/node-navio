#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "streaming-worker.h"
#include "json.hpp" //https://github.com/nlohmann/json
#include "ahrs.cc" // Main AHRS class

using namespace std;
using json = nlohmann::json;


class Sensor : public StreamingWorker {
  public:
    Sensor(Callback *data, Callback *complete, Callback *error_callback,  v8::Local<v8::Object> & options) 
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

    void send_sample(const AsyncProgressWorker::ExecutionProgress& progress, double roll, double pitch, double yaw) {
      json sample;
      sample["sensor"] = name;
      sample["position"]["roll"] = roll;
      sample["position"]["pitch"] = pitch;
      sample["position"]["yaw"] = yaw;
      Message tosend("position_sample", sample.dump());
      writeToNode(progress, package);
    }

    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {
      // std::random_device rd;
      // std::uniform_real_distribution<double> pos_dist(-1.0, 1.0);
      while (!closed()) {
        // Send it
        send_data(progress, roll, pitch, yaw);
        // Throttle here to prevent hammering node process
        std::this_thread::sleep_for(chrono::milliseconds(50));
      }
    }
  private:
    string name;
};

StreamingWorker * create_worker(Callback *data
    , Callback *complete
    , Callback *error_callback, v8::Local<v8::Object> & options) {
  return new Sensor(data, complete, error_callback, options);
}

NODE_MODULE(sensor_sim, StreamWorkerWrapper::Init)
