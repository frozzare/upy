# node-upy

`node-upy` is a easy to use uptime module for node.js build with c++. 

# installation
1. install npm `curl http://npmjs.org/install.sh | sh`
2. `npm install upy`

# build
	node-waf configure build

# test the installation
	1. `npm install vows`
	2. `node test/value.js`

# usage
a quick example using `node-upy`,
Your .js files and upy.node have to bee in the same directory or with hard links. 

	var upy = require('./upy');
	
	console.log( upy.uptime() ); // Uptime x day(s), x hour(s), x minute(s), x second(s)

# functions
	upy.uptime()		// returns a string telling you the uptime
	upy.days()			// returns days
	upy.hours()			// returns hours
	upy.minutes()		// returns minute
	upy.seconds()		// returns seconds
	upy.timestamp()		// returns timestamp in seconds


# copyright and license 
`node-upy` is release under MIT license.

Copyright 2011 [Fredrik Forsmo](http://forsmo.me), [Duofy team](http://duofy.com)
