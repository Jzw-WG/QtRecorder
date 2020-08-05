#ifndef PLAYER_H
#define PLAYER_H
#include<QThread>
#include<QTimer>
class Player: public QThread
{
    Q_OBJECT
public slots:
    void timedone();
public:
    static const int NEXTFRAME = 0;
    static const int PREVFRAME = 1;
    static const int AUTOFRAME = -1;
    static const int REPLAY_RATE = 1000;
    QTimer *timer;
    Player();
    ~Player();
protected:
    void run();
private:
    int targetFilePosition;
    int imageFilePosition;
};

#endif // PLAYER_H
