#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FASTQ2QZAPlugin.h"

void FASTQ2QZAPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void FASTQ2QZAPlugin::run() {
   
}

void FASTQ2QZAPlugin::output(std::string file) { 
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime tools import --type \'SampleData[PairedEndSequencesWithQuality]\' --input-path "+std::string(PluginManager::prefix())+"/"+parameters["manifest"]+" --output-path "+file+" --input-format "+parameters["format"]+"; ";

//qiime tools import \
  --type 'SampleData[PairedEndSequencesWithQuality]' \
  --input-path AlphaFinal1.manifest \
  --output-path AlphaFinal1-paired-end-demux.qza \
  --input-format PairedEndFastqManifestPhred33V2
 //std::cout << command << std::endl;
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;


 system(command.c_str());
}

PluginProxy<FASTQ2QZAPlugin> FASTQ2QZAPluginProxy = PluginProxy<FASTQ2QZAPlugin>("FASTQ2QZA", PluginManager::getInstance());
