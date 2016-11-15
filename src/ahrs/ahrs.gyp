{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ahrs",
          "include_dirs": [ 
            "<!(node -e \"require('nan')\")", 
            "<!(node -e \"require('streaming-worker-sdk')\")", 
          ],
          "sources": [
            "addon.cc",
          ],
          "dependencies" : [
            '../Navio/navio.gyp:navio'
          ],
        },
      ]
    }]
  ]
}
