{
  'targets': [
    {
      'target_name': 'build_all',
      'type': 'none',
      'dependencies': [
        'src/mpu9250/mpu9250.gyp:*',
        'src/mpu9250/Ublox.gyp:*',
      ],
    }
  ]
}
