//
// Created by Shinan on 2019/1/27.
//

#include "Connection.h"
#include "Stream.h"

Connection::Connection(const SpStream &spStream, const WpNetWorkService &wpNetWorkService)
    : spStream_(spStream), wpNetWorkService_(wpNetWorkService)
{
  handle_ = spStream->getFd();
  assert(handle_ > 0);
}

Connection::~Connection()
{
  LOG(ERROR) << "DES";
}

int Connection::getHandle() const
{
  return handle_;
}

SpNetWorkService Connection::getSpNetWorkService()
{
  return wpNetWorkService_.lock();
}

void Connection::destroy()
{
  auto sp = wpNetWorkService_.lock();
  sp->removeConnection(handle_);
}

void Connection::startReadOrWriteInService()
{

}

void Connection::onMessage(const SpConnectionMessage &spConnectionMessage)
{

}


