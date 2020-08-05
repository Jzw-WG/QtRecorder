#ifndef RECORDERFILE_H
#define RECORDERFILE_H
#include<string>
using namespace std;

class RecorderFile {
public:
    string absolutelyFileName;
    string fileName;
    string extName;
    long fileLength;
    time_t createTime;
    time_t lastModifyTime;
    string prefix;
    string withoutPrefix;
    string directory;
};

#endif // RECORDERFILE_H

