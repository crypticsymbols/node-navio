#include <AP_RangeFinder.h>
#include <AP_InertialSensor.h>
#include <AP_Baro.h>
#include <AP_GPS.h>
#include <AP_AHRS.h>
#include <AP_Compass.h>
#include <AP_NavEKF.h>
#include <AP_BattMonitor.h>
#include <AP_SerialManager.h>
#include <AP_AHRS_NavEKF.h>

class AHRS {
  public:
    void setup () {

      ins.init(AP_InertialSensor::COLD_START, 
          AP_InertialSensor::RATE_100HZ);
      ahrs.init();
      serial_manager.init();
      if( compass.init() ) {
        ahrs.set_compass(&compass);
      // } else {
        // ???
      }
      gps.init(NULL, serial_manager);

    };

    struct Location current_loc;

    float heading = 0;

    void update() {

      ahrs.update();
      gps.update();

      if (compass.read()) {
        heading = compass.calculate_heading(ahrs.get_dcm_matrix());
      }

    };

    void getData(std::function<void(float roll, float pitch, float yaw)> outputCallback, int callbackInterval) {

      ahrs.get_position(current_loc);
      Vector3f drift  = ahrs.get_gyro_drift();
      outputCallback(ahrs.roll, ahrs.pitch, ahrs.yaw);

    };

    RangeFinder rng;

    AP_GPS gps;

    AP_InertialSensor ins;

    AP_Baro baro;

    Compass compass;

    AP_SerialManager serial_manager;

    NavEKF EKF{&ahrs, baro, rng};

    AP_AHRS_NavEKF ahrs{ins, baro, gps, rng, EKF};

};

