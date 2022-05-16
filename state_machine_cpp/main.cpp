#include <iostream>
#include "inc/StateMachine.h"
#include "inc/Job.h"
#include "inc/JobCloManager.h"
#include <vector>


using namespace std;

int main()
{
    JobCloManager JobClo;
    //vector<int&>x{};
    
    cout<<"Dummy Code With boost..."<<endl;
    Job demo("demoJob", "testOwner", EJobMode::E_TimeBased);
    
    shared_ptr<Job> job = make_shared<Job>("hello", "world", EJobMode::E_EventBased );
    shared_ptr<Job> job1 = make_shared<Job>("bonjour", "monde", EJobMode::E_EventBased );
    job.get()->m_stateMachine.CallAction("Dummy", job.get()->m_stateMachine.getState());
    JobClo.IJobCloManager::registerJob(job);
    JobClo.IJobCloManager::registerJob(job1);
    JobClo.IJobCloManager::registerJob(job);
    job.get()->m_stateMachine.setEvent(stm_event::EV_INIT);
    job.get()->m_stateMachine.execute(job.get()->m_stateMachine);
    job.get()->m_stateMachine.setEvent(stm_event::EV_START_OK);
    job.get()->m_stateMachine.execute(job.get()->m_stateMachine);
    job.get()->m_stateMachine.setEvent(stm_event::EV_START_OK);
    job.get()->m_stateMachine.execute(job.get()->m_stateMachine);
    //JobClo.registerJob(job);ssss
    JobClo.enterSafeState();
    
    
    /*
    cout<<"The job name: "<<job.get()->getJobName()<<endl;
    cout<<"The job owner: "<<job.get()->getJobOwner()<<endl;
    cout<<"The name of Clo Manager: "<<JobClo.m_moduleName<<endl;
    */
    return 0;
}