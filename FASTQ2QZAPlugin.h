#ifndef FASTQ2QZAPLUGIN_H
#define FASTQ2QZAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class FASTQ2QZAPlugin : public Plugin
{
public: 
 std::string toString() {return "FASTQ2QZA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
