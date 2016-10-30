{
  'targets': [
    {
      'target_name': 'build_all',
      'type': 'none',
      'dependencies': [
        'src/pwm/pwm.gyp:*',
        'src/imu/imu.gyp:*'
      ],
    }
  ]
}