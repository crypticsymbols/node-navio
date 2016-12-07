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
          '../ardupilot/ardupilot.gyp:ardupilot'
        ],
      },
      ]
    }]
  ]
}
