{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ardupilot",
          'type': 'shared_library',
          'direct_dependent_settings': {
            "cflags": [ "-fsigned-char", "-Wall", "-std=c++11" ],
            "cflags_cc": [ "-fsigned-char", "-Wall", "-std=c++11", '-O3', '-g' ],
            "cflags!": [ '-fno-exceptions' ],
            "cflags_cc!": [ '-fno-exceptions' ],
            "defines": [
              "CONFIG_HAL_BOARD=7",
              "CONFIG_HAL_BOARD_SUBTYPE=1003",
              'SKETCHNAME="ardupilot"',
              'SKETCH="ardupilot"',
              'SKETCHBOOK="ardupilot"',
              "_GNU_SOURCE"
            ],
            'include_dirs': [
              "<!@(cd <(module_root_dir)/src/ardupilot && find libraries -type d -maxdepth 2)",
            ],
            'link_settings': {
              'libraries': [
                '-Wl,-rpath=\$$ORIGIN',
                '-Wl,-rpath-link=\$(builddir)'
              ],
            },
          },
          "sources": [
            "<!@(cd <(module_root_dir)/src/ardupilot && find libraries -type f -name *.cpp -maxdepth 3)",
          ],
          "defines": [
            "CONFIG_HAL_BOARD=7",
            'SKETCHNAME="ardupilot"',
            'SKETCH="ardupilot"',
            'SKETCHBOOK="ardupilot"',
            "CONFIG_HAL_BOARD_SUBTYPE=1003",
            "_GNU_SOURCE"
          ],
          "libraries": [
            "-lm",
            "-lpthread",
            "-lrt"
          ],
          "cflags": [ "-fsigned-char", "-Wall", "-std=gnu++11" ],
          "cflags_cc": [ "-fsigned-char", "-Wall", "-std=gnu++11", '-O3', '-g' ],
          "cflags!": [ '-fno-exceptions' ],
          "cflags_cc!": [ '-fno-exceptions' ],
          "include_dirs" : [
            "<!@(cd <(module_root_dir)/src/ardupilot && find libraries -type d -maxdepth 2)",
          ]
        }
      ]
    }]
  ]
}
