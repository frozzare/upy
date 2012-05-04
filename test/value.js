var upy = require('../'),
    vows = require('vows'),
    assert = require('assert');

vows.describe('function-test').addBatch({
    'uptime equal string': {
        topic: function () { return typeof(upy.uptime()) },

        'is equal to string': function (topic) {
            assert.equal (topic, "string");
        }
    },
    'days equal number': {
        topic: function () { return typeof(upy.days()) },

        'is equal to number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'hours equal number': {
        topic: function () { return typeof(upy.hours()) },

        'is equal to number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'minutes equal number': {
        topic: function () { return typeof(upy.minutes()) },

        'is equal to number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'seconds equal number': {
        topic: function () { return typeof(upy.seconds()) },

        'is equal to number': function (topic) {
            assert.equal (topic, "number");
        }
    },
    'timestamp equal number': {
        topic: function () { return typeof(upy.timestamp()) },

        'is equal to number': function (topic) {
            assert.equal (topic, "number");
        }
    }
}).run(); 
