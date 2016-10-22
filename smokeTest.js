var navio = require('bindings');

var obj = new navio('pwm').PWM();

console.log( obj.setPWM(1, 1.1) );