// This is the main DLL file.

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

#include "ThreadHelper.h"

unsigned int CBoostSemaphore::Count() 
{
    //The "lock" object locks the mutex when it's constructed,
    //and unlocks it when it's destroyed.
    boost::unique_lock<boost::mutex> lock(m_mutex);
    return m_nCount;
}

void CBoostSemaphore::Signal() 
{
    boost::unique_lock<boost::mutex> lock(m_mutex);

    ++m_nCount;

    //Wake up any waiting threads. 
    //Always do this, even if m_nCount wasn't 0 on entry. 
    //Otherwise, we might not wake up enough waiting threads if we 
    //get a number of Signal() calls in a row.
    m_condition.notify_one(); 
}

void CBoostSemaphore::Wait() 
{
    boost::unique_lock<boost::mutex> lock(m_mutex);
    while (m_nCount == 0)
    {
         m_condition.wait(lock);
    }
    --m_nCount;
}

bool CBoostSemaphore::Wait(const bool & bStopApplication, const int & nApplicationStopCode){
	boost::unique_lock<boost::mutex> lock(m_mutex);
    while (m_nCount == 0)
    {
		if(bStopApplication && nApplicationStopCode < 0){
			return false;
		}
         m_condition.wait(lock);
    }
    --m_nCount;
	//
	return true;
}

void CBoostThreadBase::operator()() {
}

CBoostThreadBase::CBoostThreadBase(){
}

CBoostThreadBase::~CBoostThreadBase(){
}

