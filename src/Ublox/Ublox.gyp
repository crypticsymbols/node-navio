{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
      {
        "target_name": "Ublox",
        "sources": [
          "addon.cc",
          "Ublox.cc",
        ],
        "include_dirs": [ 
          "<!(node -e \"require('nan')\")", 
          "<!(node -e \"require('streaming-worker-sdk')\")",
        ],
        "cflags": ["-Wall", "-std=c++11"],
        "cflags!": [ '-fno-exceptions' ],
        "cflags_cc!": [ '-fno-exceptions' ],
      },
      ]
    }]
  ]
}
