//
// Created by james on 2019-02-18.
//

#ifndef TESTPOCO_EVENT_H
#define TESTPOCO_EVENT_H

#include <pthread.h>
#include <errno.h>


namespace Suk{
	class Event {
	public:
		Event(bool autoRest);
		~Event();
		void set();
		void wait();
		bool wait(long millisecounds);
		void reset();
	private:
		bool     		_auto;
		volatile bool 	_state;
		pthread_mutex_t _mutex;
		pthread_cond_t	_cond;
	};

	inline void Event::set() {
		if (pthread_mutex_lock(&_mutex))
			throw
	}

}



#endif //TESTPOCO_EVENT_H
