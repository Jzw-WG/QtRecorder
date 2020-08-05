#ifndef FILE_H
#define FILE_H

#endif // FILE_H
#include<string>
#include<Windows.h>
#include<vector>
#include <direct.h>
#include <io.h>
#include<time.h>
const int BUFSIZE = 4096, EXIST = 0,READABLE = 2,WRITEABLE=4,EXECUTABLE=6;
struct Time {
    int year, month, day, hour, minute, second;
};

//class File {
//private:
//    _finddata_t fileInfo;
//    std::string absolute_path,path,name;
//    void updata(std::string);  //更新数据
//    Time getTime(time_t tm);
//public:
//    File(std::string pathname);
//    ~File();
//    std::string getName();    //获取文件名
//    std::string getParent();  //获取父路径
//    File getParentFile();	  //获取父路径的一个File对象
//    std::string getPath();    //获取路径
//    bool isAbsolute();        //判断是否为绝对路径
//    std::string getAbsolutePath();   //获取绝对路径
//    File getAbsoluteFile();          //获取绝对路径的一个File对象
//    Time getCreateTime();            //获取创建日期
//    Time getAccessTime();            //获取最后访问日期
//    Time getWriteTime();             //获取最后修改日期
//    bool canRead();					 //判断是否可读
//    bool canWrite();                 //判断是否可写
//    bool canRun();                   //判断是否可执行
//    bool exists();					 //判断是否存在
//    bool isDirectory();              //判断是否为目录
//    bool isFile();					 //判断是否为文档
//    bool isHidden();                 //判断是否隐藏
//    long long length();              //获取文件字节大小
//    bool Delete();                   //删除文件
//    std::vector<std::string> list(); //获取子文件列表
//    std::vector<File> listFile();    //获取子文件的File对象列表
//    bool mkdir();                    //创建新目录
//    bool renameTo(std::string newName);  //重命名
//};

////File::File(std::string pathname) {
////    updata(pathname);
////}
////void File::updata(std::string pathname) {
////    path = pathname;
////    LPSTR  buffer[BUFSIZE] = TEXT("");
////    LPSTR* lppPart = { NULL };

////    GetFullPathNameA(pathname.c_str(), BUFSIZE, buffer, &lppPart);
////    if (lppPart != NULL)
////        name = lppPart;
////    absolute_path = buffer;
////    long hFile=_findfirst(absolute_path.c_str(), &fileInfo);
////    _findclose(hFile);
////}
//std::string File::getName() {
//    return name;
//}
//std::string File::getAbsolutePath() {
//    return absolute_path;
//}
//std::string File::getPath() {
//    return path;
//}
//std::string File::getParent() {
//    return absolute_path.substr(0, absolute_path.rfind("\\"));
//}
//bool File::isAbsolute() {
//    return path == absolute_path;
//}
//bool File::isDirectory() {
//    if(exists())
//        return fileInfo.attrib==_A_SUBDIR;
//    return 0;
//}
//bool File::isHidden() {
//    if (exists())
//        return fileInfo.attrib == _A_HIDDEN;
//    return 0;
//}
//bool File::exists() {
//    return !_access(path.c_str(),EXIST);
//}
//bool File::canRead() {
//    if (exists())
//        return !_access(path.c_str(), READABLE);
//    return 0;
//}
//bool File::canWrite() {
//    if (exists())
//        return !_access(path.c_str(), WRITEABLE);
//    return 0;
//}
//bool File::canRun() {
//    if (exists())
//        return !_access(path.c_str(), EXECUTABLE);
//    return 0;
//}
//bool File::isFile() {
//    if (exists())
//        return fileInfo.attrib == _A_ARCH;
//    return 0;
//}
//bool File::mkdir() {
//    if (_mkdir(absolute_path.c_str())) {
//        updata(absolute_path);
//        return 1;
//    }
//    return 0;
//}
//bool File::renameTo(std::string newName) {
//    std::string newPath = getParent() + "\\" + newName;
//    if (exists()&&rename(absolute_path.c_str(), newPath.c_str())) {
//        updata(newPath);
//        return 1;
//    }
//    return 0;
//}
//bool File::Delete() {
//    if (exists() && remove(absolute_path.c_str())) {
//        return 1;
//    }
//    return 0;
//}
//long long File::length() {
//    return fileInfo.size;
//}
//Time File::getTime(time_t tt) {
//    tm t;   //tm结构指针
//    localtime_s(&t, &tt);
//    return { t.tm_year + 1900,t.tm_mon + 1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec };
//}
//Time File::getCreateTime() {
//    if (exists())
//        return getTime(fileInfo.time_create);
//    return {};
//}
//Time File::getAccessTime() {
//    if (exists())
//        return getTime(fileInfo.time_access);
//    return {};
//}
//Time File::getWriteTime() {
//    if (exists())
//        return getTime(fileInfo.time_write);
//    return {};
//}
//File File::getParentFile() {
//    return File(getParent());
//}
//File File::getAbsoluteFile() {
//    return File(getAbsoluteFile());
//}
//std::vector<std::string> File::list() {
//    std::vector<std::string> list;
//    if (isDirectory()) {
//        _finddata_t temp;
//        long find = _findfirst((absolute_path+"\\*").c_str(), &temp);
//        _findnext(find, &temp); //去除2个超链接
//        _findnext(find, &temp);
//        do {
//            list.push_back(temp.name);
//        } while (_findnext(find, &temp) == 0);
//        _findclose(find);
//    }
//    return list;
//}
//std::vector<File> File::listFile() {
//    std::vector<File> listFile;
//    if (isDirectory())
//        for (auto &it : list())
//            listFile.push_back(File(absolute_path + "\\" + it));
//    return listFile;
//}
//File::~File() {}

