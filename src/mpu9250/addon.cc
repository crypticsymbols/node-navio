#include <functional>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "streaming-worker.h"
#include "json.hpp" //https://github.com/nlohmann/json
#include "MPU9250.h" // Main AHRS class

using namespace std;
using json = nlohmann::json;

class MPU9250_Interface : public StreamingWorker {
  public:
    MPU9250_Interface(Callback *data, Callback *complete, Callback *error_callback,  v8::Local<v8::Object> & options) 
      : StreamingWorker(data, complete, error_callback){
        name = "MPU9250";
        if (options->IsObject() ) {
          v8::Local<v8::Value> name_ = options->Get(New<v8::String>("name").ToLocalChecked());
          if ( name_->IsString() ) {
            v8::String::Utf8Value s(name_);
            name = *s;
          }
        }
      }

    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {

      float ax, ay, az = 0;
    float gx, gy, gz = 0;
    float mx, my, mz = 0;

      this->imu.initialize();

      int sendInterval = 10; // Interval results are sent in ms

      while (!closed()) {
        std::this_thread::sleep_for(chrono::milliseconds(sendInterval));
        this->imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
        json sensorData;
        sensorData["sensor"] = name;
        sensorData["ax"] = &ax;
        sensorData["ay"] = &ay;
        sensorData["az"] = &az;
        sensorData["gx"] = &gx;
        sensorData["gy"] = &gy;
        sensorData["gz"] = &gz;
        sensorData["mx"] = &mx;
        sensorData["my"] = &my;
        sensorData["mz"] = &mz;
        Message message("imuData", sensorData.dump());
        writeToNode(progress, message);
      }
    }
  private:
    string name;
    
    MPU9250 imu;
};

StreamingWorker * create_worker(Callback *data
    , Callback *complete
    , Callback *error_callback, v8::Local<v8::Object> & options) {
  return new MPU9250_Interface(data, complete, error_callback, options);
}

NODE_MODULE(sensor_sim, StreamWorkerWrapper::Init)
