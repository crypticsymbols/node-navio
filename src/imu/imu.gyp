{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "imu",
          "sources": [ 
            "imu_wrapper.cc", 
            "imu.cc" 
          ],
          "dependencies" : [
            '../Navio/navio.gyp:navio'
          ],
        },
      ]
    }]
  ]
}
