//#include <AP_RangeFinder.h>
//#include <AP_Scheduler.h>
//#include <StorageManager.h>
//#include <Filter.h>
//#include <AP_Buffer.h>
//#include <AP_Notify.h>
//#include <AP_Vehicle.h>
//#include <DataFlash.h>
//#include <AP_ADC.h>
//#include <AP_Declination.h>
//#include <AP_ADC_AnalogSource.h>
//#include <AP_Progmem.h>
//#include <AP_Math.h>
//#include <AP_Param.h>
// #include <AP_HAL.h>
#include <AP_Common.h>
#include <AP_InertialSensor.h>
#include <AP_Baro.h>            // ArduPilot Mega Barometer Library
#include <AP_GPS.h>
#include <AP_AHRS.h>
#include <AP_Compass.h>
#include <AP_Airspeed.h>
#include <AP_Baro.h>
#include <AP_NavEKF.h>
#include <AP_HAL_Linux.h>
#include <AP_BattMonitor.h>
#include <AP_SerialManager.h>
#include <AP_AHRS_NavEKF.h>

// const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;

class AHRS {
  public: 
    void setup () {

      ins.init(AP_InertialSensor::COLD_START, 
          AP_InertialSensor::RATE_100HZ);
      ahrs.init();
      serial_manager.init();

      if( compass.init() ) {
        // hal.console->printf("Enabling compass\n");
        ahrs.set_compass(&compass);
      } else {
        // hal.console->printf("No compass detected\n");
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
// #if WITH_GPS
        // g_gps->update();
// #endif
      }
    };
    void getData(std::function<void(float roll, float pitch, float yaw)> outputCallback, int callbackInterval) {
      ahrs.get_position(current_loc);
      Vector3f drift  = ahrs.get_gyro_drift();
      outputCallback(ahrs.roll, ahrs.pitch, ahrs.yaw);
      // hal.console->printf_P(
          // PSTR("r:%4.1f  p:%4.1f y:%4.1f "
            // "drift=(%5.1f %5.1f %5.1f) hdg=%.1f lat=%d\n"),
          // ToDeg(ahrs.roll),
          // ToDeg(ahrs.pitch),
          // ToDeg(ahrs.yaw),
          // ToDeg(drift.x),
          // ToDeg(drift.y),
          // ToDeg(drift.z),
          // compass.use_for_yaw() ? ToDeg(heading) : 0.0f,
          // current_loc.lat);
    };
    NavEKF EKF{&ahrs, baro, rng};
    RangeFinder rng;
    AP_GPS gps;
    AP_InertialSensor ins;
    AP_Baro baro;
    Compass compass;
    AP_SerialManager serial_manager;
    AP_AHRS_NavEKF ahrs{ins, baro, gps, rng, EKF};

};

// AHRS instance = AHRS();

// #define HIGH 1
// #define LOW 0

// void setup(void)
// {

  // instance.setup();

// }

// void loop(void)
// {
  // static uint16_t counter;
  // static uint32_t last_t, last_print, last_compass;
  // uint32_t now = hal.scheduler->micros();

  // instance.update();
  // counter++;

  // if (now - last_print >= 100000 [> 100ms : 10hz <]) {
    // instance.getData();
    // last_print = now;
    // counter = 0;
  // }
// }

// AP_HAL_MAIN();
