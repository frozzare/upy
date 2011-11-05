var upy = require('../build/Release/upy');

console.log( 'upy uptime values' );
console.log( '----------------' );
console.log( 'Days: ' + upy.days() );
console.log( 'Hours: ' + upy.hours() );
console.log( 'Minutes: ' + upy.minutes() );
console.log( 'Seconds: ' + upy.seconds() );
console.log( 'Timestamp: ' + upy.timestamp() );
console.log( upy.uptime() );
