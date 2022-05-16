/******************************** StateMachine.h *********************
* *******************************************************************/
#pragma once

#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum class stm_state{
    ST_IDLE,
    ST_READY,
    ST_ACTIVE,
    ST_PROCESSING,
    ST_INACTIVE
};

enum class stm_event{
    EV_INIT,
    EV_START_OK,
    EV_START_NOK,
    EV_RUN_OK,
    EV_RUN_NOK,
    EV_PROCESS_OK,  // This event can be split in two parts (1. The process is completely finish and no new one is ready, 2. The process is completely finish and a new one is ready). TBD
    EV_PROCESS_NOK,
    EV_ERROR_ACK    // This event occurs only with some authorization. TBD
};

typedef void (*CallBackAction)(string, stm_state);
void Do_Action(string actionName, stm_state st);
 
class StateMachine{
 
    public:
        StateMachine(){
            this->m_currentState = stm_state::ST_IDLE;
            this->CallBackFunc = Do_Action;
        }

        void setState(stm_state state);
        void setEvent(stm_event event);
        stm_state getState(void);
        stm_event getEvent(void);

        string getStateString(void);
        void gotoState(stm_state state);

        void CallAction(string action, stm_state st);
        void setCallBackFunc(CallBackAction callback){
            this->CallBackFunc = callback;
        }
        void execute(StateMachine& stMachine);
    private:
        stm_state m_currentState;
        stm_event m_event;
        CallBackAction CallBackFunc;
};

// Prototype
void StateMachine_Run(StateMachine& stMachine);