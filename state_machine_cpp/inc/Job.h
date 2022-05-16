/*
  Job.h

*/
#pragma once
#include <set>
#include <string>
#include <any>

#include "../inc/StateMachine.h"

/* Operating Mode of Job */
enum class EJobMode {E_TimeBased = 0, E_EventBased = 1, E_TriggerBased = 2};

class Job
{
public:
    Job(string name, string owner, EJobMode mode, CallBackAction callback=Do_Action)
        : m_name(name), m_owner(owner), m_mode(mode){
        this->m_stateMachine.setState(stm_state::ST_IDLE);

        this->m_stateMachine.setCallBackFunc(callback);
    }
    //Job(){}
    ~Job(){}

    string getJobName(){
        return this->m_name;
    }
    string getJobOwner(){
        return this->m_owner;
    }
    EJobMode getJobMode(){
        return this->m_mode;
    }
    StateMachine m_stateMachine;
private:
    string m_name;
    string m_owner;
    EJobMode m_mode;
    

};