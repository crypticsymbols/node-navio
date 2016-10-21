{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        # {
        #   "target_name": "pwm",
        #   "sources": [ 
        #     "src/pwm/pwm_wrapper.cc", 
        #     "src/pwm/pwm.cc" 
        #   ],
        #   "dependencies" : [
        #     './Navio/navio.gyp:navio'
        #   ],
        #   # 'link_settings': {
        #   #   'libraries': [
        #   #     "-Wl,-rpath=$ORIGIN,-rpath-link=<(PRODUCT_DIR),./navio.so"
        #   #   ]
        #   # }
        # },
        {
          "target_name": "navio",
          'type': 'shared_library',
          'include_dirs': [
            './',
          ],
          "sources": [
            "MPU9250.cpp",
            "MB85RC04.cpp",
            "gpio.cpp",
            "ADS1115.cpp",
            "MS5611.cpp",
            "Ublox.cpp",
            "MB85RC256.cpp",
            "I2Cdev.cpp",
            "PCA9685.cpp",
            "Util.cpp"
          ]
        }
      ]
    }]
  ]
}