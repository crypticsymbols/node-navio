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
        "libraries" : [
          "../ardupilot/"
        ]
        "include_dirs": [
          "<!(node -e \"require('nan')\")", 
          "<!(node -e \"require('streaming-worker-sdk')\")" 
        ],
        "dependencies" : [
          '../Navio/navio.gyp:navio'
        ],
        "cflags": ["-Wall", "-std=c++11"],
        "cflags!": [ '-fno-exceptions' ],
        "cflags_cc!": [ '-fno-exceptions' ],
      },
      ]
    }]
  ]
}
