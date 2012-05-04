var upy = require('../'),
    should = require('should');
    
describe('Upy', function () {
  describe('uptime()', function () {
    it('should return a string', function () {
      upy.uptime().should.be.a('string');
    })
  });
  describe('days()', function () {
    it('should return a number', function () {
      upy.days().should.be.a('number');
    })
  });
  describe('hours()', function () {
    it('should return a number', function () {
      upy.hours().should.be.a('number');
    })
  });
  describe('minutes()', function () {
    it('should return a number', function () {
      upy.minutes().should.be.a('number');
    })
  });
  describe('seconds()', function () {
    it('should return a number', function () {
      upy.seconds().should.be.a('number');
    })
  });
  describe('timestamp()', function () {
    it('should return a number', function () {
      upy.timestamp().should.be.a('number');
    })
  });
});