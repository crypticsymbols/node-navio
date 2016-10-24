var bindings = require('bindings');

module.exports = {
  pwmController: function(){
    return new bindings('pwm.node').PWM();
  }
}
