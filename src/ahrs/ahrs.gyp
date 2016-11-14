{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "ahrs",
          "sources": [ 
            "ahrs_wrapper.cc", 
            "ahrs.cc", 
          ],
          "dependencies" : [
            '../Navio/navio.gyp:navio'
          ],
        },
      ]
    }]
  ]
}
