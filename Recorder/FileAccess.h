#ifndef FILEACCESS_H
#define FILEACCESS_H

#include<stdlib.h>
#include<vector>
#include<string>
#include<ctime>
#include<list>
#include<RecorderFile.h>
#include<iostream>
#include<io.h>
#include<cstring>
#include<File.h>
#include<fstream>

using namespace std;

class FileAccess {
public:
    static const int FILELENGTH_UNIT = 1024;
    static void getFileList(string strPath, vector<string> &fileList, vector<string> &ownname, vector<string> nameCondition, vector<string> extention, time_t start, time_t end);
    static vector<RecorderFile> fileListToRecorderFileList(vector<string> fileList, vector<string> ownname, string delimiter);
    //        static list<list<object>> findAllFieldsAndValues();
    static string getReplayProperties(string fileName, string key);
    static vector<vector<VARIANT>> findAllFieldsAndValues(VARIANT variant);

};

#endif // FILEACCESS_H


