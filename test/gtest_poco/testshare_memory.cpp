//
// Created by james on 2019-04-12.
//

#include <Poco/SharedMemory.h>
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/Exception.h"
#include <gtest.h>

using Poco::SharedMemory;

Poco::Path findDataFile(const std::string& afile)
{
	Poco::Path root;
	root.makeAbsolute();
	Poco::Path result;
	while (!Poco::Path::find(root.toString(), "data", result))
	{
		root.makeParent();
		if (root.toString().empty() || root.toString() == "/" || root.toString() == "\\")
			throw Poco::FileNotFoundException("Didn't find data subdir");
	}
	result.makeDirectory();
	result.setFileName(afile);
	Poco::File aFile(result.toString());
	if (!aFile.exists() || (aFile.exists() && !aFile.isFile()))
		throw Poco::FileNotFoundException("Didn't find file " + afile);

	return result;
}


TEST(SharedMemoryTest,testCreate)
{
	SharedMemory mem("hi", 4096, SharedMemory::AM_WRITE);
	assert (mem.end()- mem.begin() == 4096);
	mem.begin()[0] = 'A';
	mem.end()[-1] = 'Z';
}


TEST( SharedMemoryTest,testCreateFromFile)
{
	Poco::Path p = findDataFile("hello");
	Poco::File f(p);
	assert (f.exists() && f.isFile());
	SharedMemory mem(f, SharedMemory::AM_READ);
	assert (mem.end() > mem.begin()); // valid?
	assert (mem.end() - mem.begin() == f.getSize());
	assert (mem.begin()[0] == 'A');
	assert (mem.end()[-5] == 'Z');
}


