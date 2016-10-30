if (process.platform == 'linux' && process.env.NODE_ENV == 'production'){
  // Is there a better way to target Raspberry Pi?
  var bindings = require('bindings');
  var pwm = bindings('pwm.node')
  var imu = bindings('imu.node')
}

module.exports = {

  pwmController: function(){
    try {
      return new pwm.PWM();
    } catch(e){
      return {
        setPWM: function(channel, uS){
          console.log('PWM Command: Channel '+channel+' set to '+uS+'uS')
        }
      }
    }
  },

  imuReader: function(){
    try {
      return new imu.IMU();
    } catch(e){
      return {
        getIMU: function(){
          return 'If this were a Navio, I would be getting IMU data.'
        }
      }
    }
  }

}
