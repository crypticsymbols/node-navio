{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ardupilot",
          "sources": [
            "libraries/AP_AHRS/examples/AHRS_Test/AHRS_Test.cpp"
          ],
          "defines": [
              "CONFIG_HAL_BOARD=7",
              "CONFIG_HAL_BOARD_SUBTYPE=1003",
              'SKETCHNAME="ardupilot"',
              'SKETCH="ardupilot"',
              'SKETCHBOOK="ardupilot"',
              "_GNU_SOURCE"
            ],
            'include_dirs': [
              "<(module_root_dir)/src/ardupilot/libraries",
            ],
        }
      ]
    }]
  ]
}
