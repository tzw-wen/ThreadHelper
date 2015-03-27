// ThreadHelper.h

/*
 * Copyright 2015 ZHIHUI WEN (tzw.wen@gmail.com)

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __THREADHELPER_H__
#define __THREADHELPER_H__

#pragma once

#include "StringHelper.h"

#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>



///////////////////////////////////////////////////////
#include "THREADHELPER_Export.h"

class CBoostSemaphore
{
    //The current CBoostSemaphore count.
    unsigned int m_nCount;

    //m_mutex protects m_nCount.
    //Any code that reads or writes the m_nCount data must hold a lock on
    //the mutex.
    boost::mutex m_mutex;

    //Code that increments m_nCount must notify the condition variable.
    boost::condition_variable m_condition;

public:
    explicit CBoostSemaphore(unsigned int nCount)
       : m_nCount(nCount),
         m_mutex(),
         m_condition()
    {
    }

    unsigned int Count();

    void Signal();

    void Wait();

	bool Wait(const bool & bStopApplication, const int & nApplicationStopCode);

};
///////////////////////////////////////////////////////
#include "THREADHELPER_Deport.h"



///////////////////////////////////////////////////////
#include "THREADHELPER_Export.h"
class CBoostThreadBase{
public:
	CBoostThreadBase();
	virtual void operator()();
	virtual ~CBoostThreadBase();
};
///////////////////////////////////////////////////////
#include "THREADHELPER_Deport.h"

#endif //!__THREADHELPER_H__


