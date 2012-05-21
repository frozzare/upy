/*
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

#ifndef UPY_VERSION
#define UPY_VERSION "v2.0.3"

#include <v8.h>
#include <node.h>

#if _POSIX_TIMERS > 0
#	include <time.h>
#else
#	include <sys/types.h>
#	include <sys/sysctl.h>
#endif

namespace upy {                    
	void Initialize(v8::Handle<v8::Object> target);
	void get_time();
	v8::Handle<v8::Value> Uptime(const v8::Arguments& args);
	v8::Handle<v8::Value> Days(const v8::Arguments& args);
	v8::Handle<v8::Value> Hours(const v8::Arguments& args);
	v8::Handle<v8::Value> Minutes(const v8::Arguments& args);
	v8::Handle<v8::Value> Seconds(const v8::Arguments& args);
	v8::Handle<v8::Value> Timestamp(const v8::Arguments& args);
};

#endif
