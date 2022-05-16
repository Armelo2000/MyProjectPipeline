/*
   IJobCloManager.h

*/

#pragma once

#include "../inc/Job.h"
#include "../inc/utils.h"
#include <deque>

class IJobCloManager
{
public:
    virtual bool registerJob(shared_ptr<Job>& job) = 0;
    virtual bool deregisterJob(shared_ptr<Job>& job) = 0;
    virtual bool startJob(shared_ptr<Job>& job) = 0;
    virtual bool stopJob(shared_ptr<Job>& job) = 0;
    virtual bool resetJob(shared_ptr<Job>& job) = 0;
    virtual bool isJobRegistered(shared_ptr<Job>& job) = 0;

private:
    deque<shared_ptr<Job>> m_jobs{};
};