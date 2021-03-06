/* 
 * File:   Property.h
 * Author: liugeng
 *
 * Created on 2017年6月22日, 下午3:46
 */

#ifndef PROPERTY_H
#define PROPERTY_H

#include <stdio.h>
#include <string>
#include <map>
#include <vector>

/** INI file, format: \w+=\w+
 */
class Ini {
public:
	static void create(const std::string name, const std::string filepath);
	static void purge();
	static Ini& m (const std::string name);
	
	Ini(std::string filepath);
	virtual ~Ini();
	
	void set(std::string key, std::string val);
	const std::string& get(std::string key);
	void remove(std::string key);
	
private:
	FILE* _fp;
	
	struct Line { std::string val; int pos; int length; };
	std::map<std::string, Line> _prop;
	std::vector<Line> _emptylines;
	static std::string _emptyProp;
	static std::map<std::string, Ini*> _m;
	
	void load();
	void addEmptyLine(const Line& el);
	void writeProp(const std::string& key, const std::string& val);
};

#endif /* PROPERTY_H */

