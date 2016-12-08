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
              "<!@(cd <(module_root_dir)/src/ardupilot && find libraries -type d -maxdepth 2)",
            ],
            'link_settings': {
              'libraries': [
                '-Wl,-rpath=\$$ORIGIN',
                '-Wl,-rpath-link=\$(builddir)'
              ],
              'ldflags': [
                "<!@(cd <(module_root_dir)/src/ardupilot && find built -type d | awk '{print \"-L\"$0}')",
              ],
            },
          },
        }
      ]
    }]
  ]
}
