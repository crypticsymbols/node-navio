{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ardupilot",
          'type': 'none',
          'direct_dependent_settings': {
            "cflags": [ "-fsigned-char", "-Wall", "-std=c++11" ],
            "cflags_cc": [ "-fsigned-char", "-Wall", "-std=c++11", '-O3', '-g' ],
            "cflags!": [ '-fno-exceptions', '-Wmissing-field-initializers' ],
            "cflags_cc!": [ '-fno-exceptions', '-Wmissing-field-initializers' ],
            "defines": [
              "CONFIG_HAL_BOARD=7",
              "CONFIG_HAL_BOARD_SUBTYPE=1003",
              'SKETCHNAME="ardupilot"',
              'SKETCH="ardupilot"',
              'SKETCHBOOK="ardupilot"',
              "_GNU_SOURCE"
            ],
            "libraries": [
              "-lm",
              "-lpthread",
              "-lrt"
            ],
            'include_dirs': [
              "<(module_root_dir)/src/ardupilot/libraries",
            ],
            'link_settings': {
              'libraries': [
                '-Wl,-rpath=\$$ORIGIN',
                '-Wl,-rpath-link=\$(builddir)',
                "<!@(cd <(module_root_dir)/src/ardupilot && find built -type f -name *.o)"
              ],
            },
          },
        }
      ]
    }]
  ]
}
