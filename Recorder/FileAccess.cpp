#include<FileAccess.h>

void FileAccess::getFileList(string strPath, vector<string> &fileList, vector<string> &ownname, vector<string> nameCondition, vector<string> extention, time_t start, time_t end) {
    /*files存储文件的路径及名称(eg.   C:\Users\WUQP\Desktop\test_devided\data1.txt)
         ownname只存储文件的名称(eg.     data1.txt)*/

    //文件句柄
    long   hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if((hFile = _findfirst(p.assign(strPath).append("\\*").c_str(),&fileinfo)) != -1)
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if((fileinfo.attrib &  _A_SUBDIR))
            {
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                {
                    getFileList( p.assign(strPath).append("\\").append(fileinfo.name), fileList, ownname, nameCondition, extention, start, end);
                }
            }
            else
            {
                fileList.push_back(strPath +"\\" + fileinfo.name);
                ownname.push_back(fileinfo.name);
            }
        }while(_findnext(hFile, &fileinfo)  == 0);
        _findclose(hFile);
    }
}

vector<RecorderFile> FileAccess::fileListToRecorderFileList(vector<string> fileList, vector<string> ownname, string delimiter) {
    vector<RecorderFile> recorderFileList;

    for(int i = 0; i < (int)fileList.size(); i++)
    {
        long hFile = 0;
        struct _finddata_t fileinfo;
        string p;
        string fileName;
        string absolutelyFileName;
        RecorderFile recorderFile;

        if((hFile = _findfirst(p.assign(fileList[i]).c_str(),&fileinfo)) != -1)
        {
            absolutelyFileName = fileList[i];
            fileName = ownname[i];
            recorderFile.absolutelyFileName = absolutelyFileName;
            recorderFile.fileName = fileName;
            if(fileName.find(delimiter) != string::npos)
            {
                size_t pos = 0;
                size_t found = fileName.find(delimiter, pos);
                recorderFile.prefix = string(fileName, pos, found - pos);
                recorderFile.withoutPrefix = string(fileName, found + 1, fileName.size());
                found = recorderFile.withoutPrefix.find_last_of(".");
                recorderFile.createTime = fileinfo.time_create;
                recorderFile.extName = string(recorderFile.withoutPrefix, found, fileName.size());
                recorderFile.lastModifyTime = fileinfo.time_write;
                recorderFile.fileLength = fileinfo.size/FILELENGTH_UNIT;
                recorderFile.directory = absolutelyFileName.erase(absolutelyFileName.find(fileName), fileName.size());
            }

        }
        recorderFileList.push_back(recorderFile);
    }
    return recorderFileList;
}

vector<vector<VARIANT>> FileAccess::findAllFieldsAndValues(VARIANT variant) {

}

string FileAccess::getReplayProperties(string fileName, string key) {
    ifstream inFile(fileName);
    vector<string> fileStrings;
    string fileString;
    string property = "";
    while(!inFile.eof()) {
        inFile>>fileString;
        fileStrings.push_back(fileString);
    }

    for (int i = 0; i < (int)fileStrings.size(); i++) {
        if(fileStrings.at(i).find("=") != string::npos)
        {
            size_t pos = 0;
            size_t found = fileStrings.at(i).find("=", pos);
            string lkey = string(fileStrings.at(i), pos, found - pos);
            if (lkey == key) {
                property = string(fileStrings.at(i), found + 1, fileStrings.at(i).size());
            }
        }
    }
    return property;
}
