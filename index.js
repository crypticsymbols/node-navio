if (process.platform == 'linux'){
  // Is there a better way to target Raspberry Pi?
  var bindings = require('bindings');
  var p = require('bindings')('pwm.node')
  var i = require('bindings')('imu.node')
}

module.exports = {

  pwmController: function(){
    try {
      return new p.PWM();
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
      return new i.IMU();
    } catch(e){
      return {
        getIMU: function(){
          return 'If this were a Navio, I would be getting IMU data.'
        }
      }
    }
  }

}
