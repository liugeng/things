例:
```
#include "Things/Utils/FileUtil.h"
void test14() {
	printf("%d\n", util::File::exists("Err_06-19_408D5C8C98E3.log"));
	
	util::Data* d = util::File::loadData("Err_06-19_408D5C8C98E3.log");
	if (d) {
		printf("%s\n", d->data);
		
		//util::File::saveToFile("test.txt", d->data, d->size);
		
		d->release();
	}
}

#include "Things/Utils/TimeUtil.h"
void test15() {
	std::string t = util::Time::format("%H %M %S", util::Time::getSecond());
	printf("%s\n", t.c_str());
}

#include "Things/Utils/PathUtil.h"
void test16() {
	enum {
		ROOT_APP,
		ROOT_RES
	};
	util::Path::setRootWithKey(ROOT_APP, "./");
	util::Path::setRootWithKey(ROOT_RES, "./res");
	enum {
		DIR_NONE,
		DIR_IMAGE,
		DIR_MAP
	};
	util::Path::setDirWithKey(DIR_NONE, "");
	util::Path::setDirWithKey(DIR_IMAGE, "image");
	util::Path::setDirWithKey(DIR_MAP, "map");
	
	printf("%s\n", util::Path::getFullPath("TEXT.log", DIR_IMAGE, ROOT_RES).c_str());
	printf("%s\n", util::Path::getDir("./dir1/dir2/dir3/file.txt").c_str());
	util::Path::assure("./dir1/dir2/dir3/");
}

#include "Things/Utils/StrUtil.h"
void test17() {
	std::string s = "abcdefg";
	printf("%d\n", util::Str::startsWith(s, "abc"));
	printf("%d\n", util::Str::endsWith(s, "fg"));
	
	std::vector<std::string> v;
	std::string s1 = "aa/bb/cc";
	util::Str::split(s1, "/", v);
	for (auto& i : v) {
		printf("%s\n", i.c_str());
	}
	
	std::string s2 = "7";
	printf(	"%d\n"
			"%g\n"
			"%s\n"
			"%s\n"
			"%d\n"
			, util::Str::to<int>("3")
			, util::Str::to<float>("1.2")
			, util::Str::to<std::string>(4).c_str()
			, util::Str::to<std::string>(5.6).c_str()
			, util::Str::to<int>(s2)
		);
}

#include "Things/Utils/MathUtil.h"
void test19() {
	int64_t n1 = 1;
	for (int i = 0; i < 10; i++) {
		printf("%s\n", util::Math::formatNumber(n1).c_str());
		n1 *= 10;
	}
	
	/*
		1
		10
		100
		1,000
		10,000
		100,000
		1,000,000
		10,000,000
		100,000,000
		1,000,000,000
	*/
}

#include "Things/Utils/DelaySimulator.h"
void test22() {
	while(true) {
		SIMULATE_DELAY(100, continue)

		int t1 = util::Time::getMsecPassed();
		static int t0 = 0;
		printf("%d\n", t1 - t0);
		t0 = t1;
	}
}
```
