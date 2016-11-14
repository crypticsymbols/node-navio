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
            "mahony.hpp" 
          ],
          "dependencies" : [
            '../Navio/navio.gyp:navio'
          ],
        },
      ]
    }]
  ]
}
