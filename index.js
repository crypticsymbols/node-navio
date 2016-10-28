if (process.platform == 'linux' && process.env.NODE_ENV == 'production'){
  // Is there a better way to target Raspberry Pi?
  var bindings = require('bindings');
}

module.exports = {

  pwmController: function(){
    try {
      return new bindings('pwm.node').PWM();
    } catch(e){
      return {
        setPWM: function(){
          console.log('not on OSX :)')
        }
      }
    }
  }
}
