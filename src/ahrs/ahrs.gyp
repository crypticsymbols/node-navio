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
        "defines": [
          "CONFIG_HAL_BOARD=HAL_BOARD_LINUX",
          "CONFIG_HAL_BOARD_SUBTYPE=HAL_BOARD_SUBTYPE_LINUX_NAVIO"
        ],
        "libraries": [
          "-lm",
          "-lpthread",
          "-lrt"
        ],
        "include_dirs": [
          "<(module_root_dir)/src/ardupilot/libraries/AC_AttitudeControl",
          "<(module_root_dir)/src/ardupilot/libraries/AC_Fence",
          "<(module_root_dir)/src/ardupilot/libraries/AC_PID",
          "<(module_root_dir)/src/ardupilot/libraries/AC_Sprayer",
          "<(module_root_dir)/src/ardupilot/libraries/AC_WPNav",
          "<(module_root_dir)/src/ardupilot/libraries/APM_Control",
          "<(module_root_dir)/src/ardupilot/libraries/APM_OBC",
          "<(module_root_dir)/src/ardupilot/libraries/APM_PI",
          "<(module_root_dir)/src/ardupilot/libraries/AP_ADC",
          "<(module_root_dir)/src/ardupilot/libraries/AP_ADC_AnalogSource",
          "<(module_root_dir)/src/ardupilot/libraries/AP_AHRS",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Airspeed",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Arming",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Baro",
          "<(module_root_dir)/src/ardupilot/libraries/AP_BattMonitor",
          "<(module_root_dir)/src/ardupilot/libraries/AP_BoardConfig",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Buffer",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Camera",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Common",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Compass",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Curve",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Declination",
          "<(module_root_dir)/src/ardupilot/libraries/AP_EPM",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Frsky_Telem",
          "<(module_root_dir)/src/ardupilot/libraries/AP_GPS",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL/utility",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_AVR",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_Empty",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_FLYMAPLE",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_Linux",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_PX4",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_SITL",
          "<(module_root_dir)/src/ardupilot/libraries/AP_HAL_VRBRAIN",
          "<(module_root_dir)/src/ardupilot/libraries/AP_InertialNav",
          "<(module_root_dir)/src/ardupilot/libraries/AP_InertialSensor",
          "<(module_root_dir)/src/ardupilot/libraries/AP_L1_Control",
          "<(module_root_dir)/src/ardupilot/libraries/AP_LandingGear",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Limits",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Math",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Menu",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Mission",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Motors",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Mount",
          "<(module_root_dir)/src/ardupilot/libraries/AP_NavEKF",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Navigation",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Notify",
          "<(module_root_dir)/src/ardupilot/libraries/AP_OpticalFlow",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Parachute",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Param",
          "<(module_root_dir)/src/ardupilot/libraries/AP_PerfMon",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Progmem",
          "<(module_root_dir)/src/ardupilot/libraries/AP_RCMapper",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Rally",
          "<(module_root_dir)/src/ardupilot/libraries/AP_RangeFinder",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Relay",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Scheduler",
          "<(module_root_dir)/src/ardupilot/libraries/AP_SerialManager",
          "<(module_root_dir)/src/ardupilot/libraries/AP_ServoRelayEvents",
          "<(module_root_dir)/src/ardupilot/libraries/AP_SpdHgtControl",
          "<(module_root_dir)/src/ardupilot/libraries/AP_TECS",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Terrain",
          "<(module_root_dir)/src/ardupilot/libraries/AP_Vehicle",
          "<(module_root_dir)/src/ardupilot/libraries/DataFlash",
          "<(module_root_dir)/src/ardupilot/libraries/Filter",
          "<(module_root_dir)/src/ardupilot/libraries/GCS_Console",
          "<(module_root_dir)/src/ardupilot/libraries/GCS_MAVLink",
          "<(module_root_dir)/src/ardupilot/libraries/PID",
          "<(module_root_dir)/src/ardupilot/libraries/RC_Channel",
          "<(module_root_dir)/src/ardupilot/libraries/SITL",
          "<(module_root_dir)/src/ardupilot/libraries/StorageManager",
          "<(module_root_dir)/src/ardupilot/libraries/doc",
          "<!(node -e \"require('nan')\")",
          "<!(node -e \"require('streaming-worker-sdk')\")" 
        ],
        "dependencies" : [
          '../Navio/navio.gyp:navio'
        ],
        "cflags": ['-D_GNU_SOURCE', "-Wall", "-std=gnu++11", "-ffunction-sections", "-fdata-sections", "-fsigned-char"],
        "cflags!": [ '-fno-exceptions' ],
        "cflags_cc!": [ '-D_GNU_SOURCE', '-stdlib=libc++', '-std=gnu++11', '-fno-exceptions', "-ffunction-sections", "-fdata-sections", "-fsigned-char" ],
      },
      ]
    }]
  ]
}
