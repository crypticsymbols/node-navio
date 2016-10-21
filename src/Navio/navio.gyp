{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "navio",
          'type': 'shared_library',
          'direct_dependent_settings': {
            'include_dirs': [
              './',
            ],
            'link_settings': {
              'libraries': [
                '-Wl,-rpath=\$$ORIGIN',
                '-Wl,-rpath-link=\$(builddir)'
              ],
            },
          },
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