{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ardupilot",
          'type': 'none',
          'direct_dependent_settings': {
            "cflags": [ "-fsigned-char", "-Wall", "-std=c++11", '-O3' ],
            "cflags_cc": [ "-fsigned-char", "-Wall", "-std=c++11", '-O3' ],
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
            'include_dirs': [
              "<(module_root_dir)/src/ardupilot/libraries",
            ],
            'libraries' : [
            '<(module_root_dir)/src/ardupilot/built/arducopter.so',
            ],
            'link_settings': {
            "defines": [
              "CONFIG_HAL_BOARD=7",
              "CONFIG_HAL_BOARD_SUBTYPE=1003",
              'SKETCHNAME="ardupilot"',
              'SKETCH="ardupilot"',
              'SKETCHBOOK="ardupilot"',
            ],
              'libraries': [
                '-Wl,-rpath=\$$ORIGIN',
                '-Wl,-rpath-link=\$(builddir)',
                '-Wl,--gc-sections',
                "-D_GNU_SOURCE",
              ],
            },
          },
        }
      ]
    }]
  ]
}
