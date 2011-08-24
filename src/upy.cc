/*
Upy module by Duofy Team 
http://duofy.com

Copyright (C) 2011 by Fredrik Forsmo
http://forsmo.me

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "upy.h"
#include <cstring>
#include <sstream>
#include <iostream>

using namespace v8;
using namespace node;
using namespace std;

extern "C" 
	void init(Handle<Object> target) {
	  HandleScope scope;
	  upy::Initialize(target);
	}

namespace upy {
	static int _day;
	static int _minute;
	static int _hour;
	static int _time;

	void Initialize(Handle<Object> target) {
		HandleScope scope;

		_minute = 60;
		_hour = _minute * 60;
		_day = _hour * 24;

		#if _POSIX_TIMERS > 0

		// SEE: http://pubs.opengroup.org/onlinepubs/009695399/functions/clock_gettime.html

		clockid_t clockid = CLOCK_MONOTONIC;
		timespec uptime;
		clock_gettime(clockid, &uptime); // it's okay if it's 0
		_time = uptime.tv_sec;

		#else
		
		timeval time_now;
		gettimeofday(&time_now, NULL);

		int request[2] = { CTL_KERN, KERN_BOOTTIME };
		struct timeval result;
		size_t result_len = sizeof result;

		if (sysctl (request, 2, &result, &result_len, NULL, 0) >= 0)
			_time = time_now.tv_sec - result.tv_sec;
		
		#endif

		target->Set(String::NewSymbol("version"), String::New(UPY_VERSION));

		Local<FunctionTemplate> t1 = FunctionTemplate::New(Uptime);
		target->Set(String::NewSymbol("uptime"), t1->GetFunction());

		Local<FunctionTemplate> t2 = FunctionTemplate::New(Days);
		target->Set(String::NewSymbol("days"), t2->GetFunction());

		Local<FunctionTemplate> t3 = FunctionTemplate::New(Hours);
		target->Set(String::NewSymbol("hours"), t3->GetFunction());

		Local<FunctionTemplate> t4 = FunctionTemplate::New(Minutes);
		target->Set(String::NewSymbol("minutes"), t4->GetFunction());

		Local<FunctionTemplate> t5 = FunctionTemplate::New(Seconds);
		target->Set(String::NewSymbol("seconds"), t5->GetFunction());
		
		Local<FunctionTemplate> t6 = FunctionTemplate::New(Timestamp);
		target->Set(String::NewSymbol("timestamp"), t6->GetFunction());
	}

	const int get_days() 
	{
		return int( _time / _day );
	}
	
	const int get_hours()
	{
		return int( ( _time % _day ) / _hour );
	}

	const int get_minutes()
	{
		return int( ( _time % _hour ) / _minute );
	}
	
	const int get_seconds() 
	{
		return int( _time % _minute );
	}

	Handle<Value> Uptime(const Arguments &args) {	
		HandleScope scope;
		int days = get_days();
		int hours = get_hours();
		int minutes = get_minutes();
		int seconds = get_seconds();
		string s;
		stringstream out;

		out << "Uptime: " << days << " day" << ((int(days) != 1) ? "s, " : ", ") << hours << " hour" << ((int(hours) != 1) ? "s, " : ", ") << minutes << " minute" << ((int(minutes) != 1) ? "s, " : ", ") << seconds << " second" << ((int(seconds) != 1) ? "s" : "");
		s = out.str();
		
		return scope.Close(String::New(s.c_str()));
	}

	Handle<Value> Days(const Arguments &args) {
		int days = get_days();
		return Integer::New(days);
	}

	Handle<Value> Hours(const Arguments &args) {
		int hours = get_hours();
		return Integer::New(hours);
	}

	Handle<Value> Minutes(const Arguments &args) {
		int minutes = get_minutes();
		return Integer::New(minutes);
	}

	Handle<Value> Seconds(const Arguments &args) {
		int seconds = get_seconds();
		return Integer::New(seconds);
	}
	
	Handle<Value> Timestamp(const Arguments &args) {
		return Integer::New(_time);
	}
}
