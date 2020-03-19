//
// Created by james on 2019-02-18.
//

#ifndef TESTPOCO_EXCEPTION_H
#define TESTPOCO_EXCEPTION_H

#include <stdexcept>

namespace Sku {
	class Exception : public std::exception {
	public:
		Exception(const std::string &msg, int code = 0);
		virtual const char* what() const throw();
	};

}


#endif //TESTPOCO_EXCEPTION_H
