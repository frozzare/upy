var upy = require('../build/Release/upy'),
	vows = require('vows'),
    assert = require('assert');

vows.describe('function-test').addBatch({
    'uptime equal string': {
        topic: function () { return typeof(upy.uptime()) },

        'we get string': function (topic) {
            assert.equal (topic, "string");
        }
    },
    'days equal number': {
        topic: function () { return typeof(upy.days()) },

        'we get number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'hours equal number': {
        topic: function () { return typeof(upy.hours()) },

        'we get number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'minutes equal number': {
        topic: function () { return typeof(upy.minutes()) },

        'we get number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'seconds equal number': {
        topic: function () { return typeof(upy.seconds()) },

        'we get number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'timestamp equal number': {
        topic: function () { return typeof(upy.timestamp()) },

        'we get number': function (topic) {
            assert.equal (topic, "number");
        }
    }
}).run(); 
