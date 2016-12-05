{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
      {
        "target_name": "ahrs",
        "sources": [
          "addon.cc",
        ],
        "include_dirs": [
          "<(module_root_dir)/src/ardupilot/libraries/AP_Common",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Common",
          "<(module_root_dir)/src/ardupilot/libraries/AP_InertialSensor",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Baro",
          "<(module_root_dir)/src/ardupilot/libraries/AP_GPS",
          "<(module_root_dir)/src/ardupilot/libraries/AP_AHRS",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Compass",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Airspeed",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Baro",
          "<(module_root_dir)/src/ardupilot/libraries/AP_NavEKF",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_Linux",
          "<(module_root_dir)/src/ardupilot/libraries/AP_BattMonitor",
          "<(module_root_dir)/src/ardupilot/libraries/AP_SerialManager",
          "<(module_root_dir)/src/ardupilot/libraries/AP_AHRS_NavEKF",
          "<(module_root_dir)/src/ardupilot/libraries/*",
          "<!(node -e \"require('nan')\")",
          "<!(node -e \"require('streaming-worker-sdk')\")" 
        ],
        "dependencies" : [
          '../Navio/navio.gyp:navio'
        ],
        "cflags": ["-Wall", "-std=c++11"],
        "cflags!": [ '-fno-exceptions' ],
        "cflags_cc!": [ '-fno-exceptions' ],
      },
      ]
    }]
  ]
}
