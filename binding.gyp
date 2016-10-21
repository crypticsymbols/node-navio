{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "pwm",
          "sources": [ 
            "src/pwm/pwm_wrapper.cc", 
            "src/pwm/pwm.cc" 
          ],
          "dependencies" : [
            'navio'
          ],
          'include_dirs': [
            'src/Navio',
          ],
          # 'link_settings': {
          #   'libraries': [
          #     "-Wl,-rpath=$ORIGIN,Release/navio.so"
          #   ]
          # }
        },
        {
          "target_name": "navio",
          'type': 'shared_library',
          # 
          # 
          # 
          'direct_dependent_settings': {
            'include_dirs': ['.'],  # dependents need to find cruncher.h.
            'link_settings': {
              'libraries': [
                "-WL,-rpath=\$ORIGIN,./build/Release",
              ],  # cruncher.cc does math.
            },
          },
          # 
          # 
          # 
          "sources": [
            "src/Navio/MPU9250.cpp",
            "src/Navio/MB85RC04.cpp",
            "src/Navio/gpio.cpp",
            "src/Navio/ADS1115.cpp",
            "src/Navio/MS5611.cpp",
            "src/Navio/Ublox.cpp",
            "src/Navio/MB85RC256.cpp",
            "src/Navio/I2Cdev.cpp",
            "src/Navio/PCA9685.cpp",
            "src/Navio/Util.cpp"
          ]
        }
      ]
    }]
  ]
}