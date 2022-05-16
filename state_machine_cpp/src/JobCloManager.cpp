/*

   JobCloManager.cpp

*/
#include "../inc/Job.h"
#include "../inc/JobCloManager.h"
#include <any>
#include <utility>

bool IJobCloManager::registerJob(shared_ptr<Job>& job) {
    if(m_jobs.empty()){
        // first job in the list
        cout<<"The Job: "<<job.get()->getJobName()<<" with the owner: "<<job.get()->getJobOwner()<<" is registered"<<endl;
        m_jobs.push_back(job);
    }else{
        string currJobOwner = job.get()->getJobOwner();
        string currJobName = job.get()->getJobName();
        for(auto &myJob : m_jobs){
            if((myJob.get()->getJobOwner() == currJobOwner) && (myJob.get()->getJobName() == currJobName)){
                //avoid registration with same identifier
                //each Job is identified with its Owner and its name

                cout<<"Job "<<currJobName<<" with the owner "<<currJobOwner<<" already exist "<<endl;
                return false;
            }
        }
        //The same identifier is not found. The Job can be registered
        cout<<"The Job: "<<currJobName<<" with the owner: "<<currJobOwner<<" is registered"<<endl;
        m_jobs.push_back(job);
    }
   return true;
}

bool IJobCloManager::deregisterJob(shared_ptr<Job>& job){

    if(m_jobs.empty()){
        // no registered job found
        return false;
    }else{
        string currJobOwner = job.get()->getJobOwner();
        string currJobName = job.get()->getJobName();
        int index = 0;
        for(auto myJob : m_jobs){
            if((myJob.get()->getJobOwner() == currJobOwner) && (myJob.get()->getJobName() == currJobName)){
                //Job to de-register found
                m_jobs.erase(m_jobs.begin()+index);
                cout<<"Job "<<currJobName<<" with the owner "<<currJobOwner<<" is de-register "<<endl;

                return true;
            }
            index++;
        }
        cout<<"The Job "<<currJobName<<" with the owner "<<currJobOwner<<" is not found "<<endl;
    }
    return false;
}

bool IJobCloManager::startJob(shared_ptr<Job>& job) {
    //check first if the job exist
    if(isJobRegistered(job)){
        //start the job here (TBD)
        return true;
    }
    return false;
}

bool IJobCloManager::stopJob(shared_ptr<Job>& job) {
    //check first if the job exist
    if(isJobRegistered(job)){
        //stop condition come here (TBD)

        return true;
    }
    return false;
}

bool IJobCloManager::resetJob(shared_ptr<Job>& job) {
    //check first if the job exist
    if(isJobRegistered(job)){
        //reset condition come here (TBD)
        return true;
    }
    return false;
}

 

bool IJobCloManager::isJobRegistered(shared_ptr<Job>& job){
    string currJobOwner = job.get()->getJobOwner();
    string currJobName = job.get()->getJobName();
    for(auto &myJob : m_jobs){

        if((myJob.get()->getJobOwner() == currJobOwner) && (myJob.get()->getJobName() == currJobName)){
            //avoid registration with same identifier
            //each Job is identified with its Owner and its name

            cout<<"Job "<<currJobName<<" with the owner "<<currJobOwner<<" exist "<<endl;

            return true;
        }
    }
    return false;
}