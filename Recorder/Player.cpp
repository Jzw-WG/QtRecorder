#include "Player.h"

Player::Player()
{
    printf("[%d] construct\n",this->currentThreadId());
}

void Player::run()
{

    printf("[%d] sub thread start\n",this->currentThreadId());

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timedone()),Qt::DirectConnection);
    timer->start(2000);

    exec();
}


void Player::timedone()
{
    printf("[%d] test...\n",this->currentThreadId());
    sleep(1);
}

Player::~Player()
{
    delete timer;
}
