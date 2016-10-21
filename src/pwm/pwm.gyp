{
  "targets": [],
  'conditions': [
    ['OS=="linux"', {
      'targets': [
        {
          "target_name": "pwm",
          "sources": [ 
            "pwm_wrapper.cc", 
            "pwm.cc" 
          ],
          "dependencies" : [
            '../Navio/navio.gyp:navio'
          ],
        },
      ]
    }]
  ]
}
