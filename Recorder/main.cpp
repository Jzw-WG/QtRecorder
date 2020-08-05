#include <iostream>
#include<list>
#include<FileAccess.h>
#include<Player.h>
#include<QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    cout << "Hello World!" << endl;
    vector<string> files;
    vector<string> names;
    vector<string> condition;
    vector<string> extension;
    time_t start;
    time_t end;
    FileAccess::getFileList("D:\\SourceCode\\CPPCode\\qt\\data", files, names, condition, extension, start, end);
    vector<RecorderFile> recorderFileList = FileAccess::fileListToRecorderFileList(files, names, "_");
    char str[30];
    for (int i = 0;i < files.size();i++)
    {
        cout<<files[i].c_str()<<endl;
    }
    /* //test getReplayProperties
    string key = FileAccess::getReplayProperties("D:\\SourceCode\\CPPCode\\qt\\data\\2019\\11\\index_2019-11-19-152306.txt", "duration");
    */

    Player player;
    player.start();
    return app.exec();
}
