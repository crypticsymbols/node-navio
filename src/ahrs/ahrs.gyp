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
        "include_dirs": [
          "<!(node -e \"require('nan')\")",
          "<!(node -e \"require('streaming-worker-sdk')\")" 
        ],
        "dependencies" : [
          '../Navio/navio.gyp:navio'
        ],
        "cflags": [ "-fsigned-char", "-Wall", "-std=c++11" ],
        "cflags_cc": [ "-fsigned-char", "-Wall", "-std=c++11", '-O3', '-g' ],
        "cflags!": [ '-fno-exceptions' ],
        "cflags_cc!": [ '-fno-exceptions' ],
      },
      ]
    }]
  ]
}
