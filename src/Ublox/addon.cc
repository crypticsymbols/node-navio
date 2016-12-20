#include <functional>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "streaming-worker.h"
#include "json.hpp" //https://github.com/nlohmann/json
#include "Ublox.h"

using namespace std;
using json = nlohmann::json;

class Ublox_Interface : public StreamingWorker {
  public:
    Ublox_Interface(Callback *data, Callback *complete, Callback *error_callback,  v8::Local<v8::Object> & options) 
      : StreamingWorker(data, complete, error_callback){
        name = "Ublox GPS";
        if (options->IsObject() ) {
          v8::Local<v8::Value> name_ = options->Get(New<v8::String>("name").ToLocalChecked());
          if ( name_->IsString() ) {
            v8::String::Utf8Value s(name_);
            name = *s;
          }
        }
      }

    void Execute (const AsyncProgressWorker::ExecutionProgress& progress) {

      if(gps.testConnection()){
        printf("Ublox test OK\n");
      }

      int sendInterval = 10; // Interval results are sent in ms

      while (!closed()) {
        std::this_thread::sleep_for(chrono::milliseconds(sendInterval));
        if (gps.decodeSingleMessage(Ublox::NAV_POSLLH, pos_data) == 1){
          gpsClock, pos_data[0]/1000;
          lng = pos_data[1]/10000000;
          lat = pos_data[2]/10000000;
          altWGS84 = pos_data[3]/1000;
          altMSL = pos_data[4]/1000;
          accuracyH = pos_data[5]/1000;
          accuracyV = pos_data[6]/1000;
        }
        if (gps.decodeSingleMessage(Ublox::NAV_STATUS, pos_data) == 1){
          gpsHealthy = ((bool)pos_data[1] & 0x01);
          gpsStatusCode = ((int)pos_data[0]);
          switch(gpsStatusCode){
              case 0x00:
                  gpsStatusName = "no fix";
                  break;
              case 0x01:
                  gpsStatusName = "dead reckoning only";
                  break;
              case 0x02:
                  gpsStatusName = "2D-fix";
                  break;
              case 0x03:
                  gpsStatusName = "3D-fix";
                  break;
              case 0x04:
                  gpsStatusName = "GPS + dead reckoning combined";
                  break;
              case 0x05:
                  gpsStatusName = "Time only fix";
                  break;
              default:
                  gpsStatusName = "Reserved value. Current state unknown";
                  break;
                }
        }
        json sensorData;
        sensorData["sensor"] = name;
        sensorData["gpsClack"] = gpsClock;
        sensorData["lat"] = lat;
        sensorData["long"] = lng;
        sensorData["altitudeWGS84"] = altWGS84;
        sensorData["altitudeMSL"] = altMSL;
        sensorData["accuracyHorizontal"] = accuracyH;
        sensorData["accuracyVertical"] = accuracyV;
        sensorData["healthStatus"] = gpsHealthy;
        sensorData["gpsStatusCode"] = gpsStatusCode;
        sensorData["gpsStatus"] = gpsStatusName;
        Message message("gpsData", sensorData.dump());
        writeToNode(progress, message);
      }
    }
  private:
    string name;
    std::vector<double> pos_data;
    float gpsClock, lat, lng, altWGS84, altMSL, accuracyH, accuracyV;
    bool gpsHealthy;
    int gpsStatusCode;
    char gpsStatusName;
    Ublox gps;
};

StreamingWorker * create_worker(Callback *data
    , Callback *complete
    , Callback *error_callback, v8::Local<v8::Object> & options) {
  return new Ublox_Interface(data, complete, error_callback, options);
}

NODE_MODULE(sensor_sim, StreamWorkerWrapper::Init)
