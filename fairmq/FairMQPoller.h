/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
/**
 * FairMQPoller.h
 *
 * @since 2014-01-23
 * @author A. Rybalchenko
 */

#ifndef FAIRMQPOLLER_H_
#define FAIRMQPOLLER_H_

#include <string>

class FairMQPoller
{
  public:
    virtual void Poll(const int timeout) = 0;
    virtual bool CheckInput(const int index) = 0;
    virtual bool CheckOutput(const int index) = 0;
    virtual bool CheckInput(const std::string channelKey, const int index) = 0;
    virtual bool CheckOutput(const std::string channelKey, const int index) = 0;

    virtual ~FairMQPoller() {};
};

#endif /* FAIRMQPOLLER_H_ */