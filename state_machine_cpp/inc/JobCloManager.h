/*
  JobCloManager.h

*/

#pragma once
#include "../inc/CloManager.h"
#include "../inc/IJobCloManager.h"
#include "../inc/Job.h"

 
class JobCloManager :
    public CloManager, public IJobCloManager
{

public:
    JobCloManager(){
        m_moduleName = "JOB_CLO";
    }
    bool registerJob(shared_ptr<Job>& job) { cout<<"demo registered job"<<endl; return true; }
    bool deregisterJob(shared_ptr<Job>& job) { cout<<"demo de-registered job"<<endl; return true; }

    bool startJob(shared_ptr<Job>& job) { cout<<"demo start job"<<endl; return true; }
    bool stopJob(shared_ptr<Job>& job) { cout<<"demo stop job"<<endl; return true; }
    bool resetJob(shared_ptr<Job>& job) { cout<<"demo reset job"<<endl; return true; }
    bool isJobRegistered(shared_ptr<Job>& job){ cout<<"demo is job registered?"<<endl; return true;}
/*
    bool init(IGpfCore &gpfCore) {
        cout << "job" << endl;
        return true;
    }
*/
 
    void enterSafeState() {
        cout <<"Job is in safe state"<<endl;
    }

    void enterResetState() {
        cout <<"Job is in reset state"<<endl;
    }
};
