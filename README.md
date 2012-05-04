# Upy

`upy` is a easy to use machine uptime module for node.js build C++.
Have been tested under Mac and Linux system. Don't have any Windows support.

# installation
1. install npm `curl http://npmjs.org/install.sh | sh`
2. `npm install upy`

# build
	node-waf configure build

# test the installation
1. `npm install vows`
2. `node test/value.js`

# usage
Quick example using `upy`,

	var upy = require('./upy');
	
	console.log( upy.uptime() ); // Uptime x day(s), x hour(s), x minute(s), x second(s)

# functions
	upy.uptime()			// returns a string telling you the uptime
	upy.days()				// returns days
	upy.hours()				// returns hours
	upy.minutes()			// returns minute
	upy.seconds()			// returns seconds
	upy.timestamp()		// returns timestamp in seconds


# copyright and license 
`upy` is release under [MIT license](http://frozzare.mit-license.org/).

Copyright 2011 [Fredrik Forsmo](http://forsmo.me)
