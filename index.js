var bindings = require('bindings');

// var pwm = 

// var obj = new addon;
// console.log( obj.setPWM(1.1, 1.1, 1.1, 1.1) );
// console.log( obj.setPWM(1.2, 1.2, 1.2, 1.2) );
// console.log( obj.setPWM(0.9, 0.9, 0.9, 0.9) );

module.exports = {
  pwmController: function(){
    return new bindings('pwm.node').PWM();
  }
}
