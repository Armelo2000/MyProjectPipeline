#include "../inc/StateMachine.h"

 
/******************************** StateMachine.cpp *********************
* *********************************************************************/ 

string StateMachine::getStateString(void){
    string statestr="";
    switch(this->m_currentState)
    {
        case stm_state::ST_IDLE:
            statestr = "IDLE";

            break;
        case stm_state::ST_READY:
            statestr = "READY";
            break;
        case stm_state::ST_ACTIVE:
            statestr = "ACTIVE";
            break;
        case stm_state::ST_PROCESSING:
            statestr = "PROCESSING";
            break;
        case stm_state::ST_INACTIVE:
            statestr = "INACTIVE";
            break;
        default:
            statestr = "";
            break;
    }
    return statestr;
}

 

void StateMachine::setState(stm_state state){
    this->m_currentState =  state;
}

void StateMachine::setEvent(stm_event event){
    this->m_event = event;
}

stm_state StateMachine::getState(void){
    return this->m_currentState;
}

stm_event StateMachine::getEvent(void){
    return this->m_event;
}

void StateMachine::gotoState(stm_state state){
    this->setState(state);
}

void StateMachine::CallAction(string action, stm_state st){
    this->CallBackFunc(action, st);
}

void StateMachine_Run(StateMachine& stMachine){
    stm_state currentState = stMachine.getState();
    stm_event event = stMachine.getEvent();

    switch (currentState) {
        case stm_state::ST_IDLE:
            // do something in the idle state
            // Check the event before going to the next state (TBD)
            if(event == stm_event::EV_INIT)
                stMachine.gotoState(stm_state::ST_READY);
        break;
        case stm_state::ST_READY:
            // do something in the ready state
            stMachine.CallAction("action for ready state", stm_state::ST_READY);
            if(event == stm_event::EV_START_OK)
                stMachine.gotoState(stm_state::ST_ACTIVE);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_ACTIVE:
            // do something in the active state
            stMachine.CallAction("action for active state", stm_state::ST_ACTIVE);
            if(event == stm_event::EV_RUN_OK)
                stMachine.gotoState(stm_state::ST_PROCESSING);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_PROCESSING:
            // do something in the processing state
            stMachine.CallAction("run process", stm_state::ST_PROCESSING);
            if(event == stm_event::EV_PROCESS_OK)
                stMachine.gotoState(stm_state::ST_IDLE);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_INACTIVE:  //Error state
            // do something in the Error state
            stMachine.CallAction("Error handling", stm_state::ST_INACTIVE);
            if(event == stm_event::EV_ERROR_ACK)
                stMachine.gotoState(stm_state::ST_IDLE);  // TBD
        break;
        default:
            //do Nothing
            stMachine.gotoState(stm_state::ST_IDLE);
        break;
        // etc...
    }
}
void StateMachine::execute(StateMachine& stMachine){
    stm_state currentState = stMachine.getState();
    stm_event event = stMachine.getEvent();

    switch (currentState) {
        case stm_state::ST_IDLE:
            // do something in the idle state
            // Check the event before going to the next state (TBD)
            if(event == stm_event::EV_INIT)
                stMachine.gotoState(stm_state::ST_READY);
        break;
        case stm_state::ST_READY:
            // do something in the ready state
            stMachine.CallAction("action for ready state", stm_state::ST_READY);
            if(event == stm_event::EV_START_OK)
                stMachine.gotoState(stm_state::ST_ACTIVE);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_ACTIVE:
            // do something in the active state
            stMachine.CallAction("action for active state", stm_state::ST_ACTIVE);
            if(event == stm_event::EV_RUN_OK)
                stMachine.gotoState(stm_state::ST_PROCESSING);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_PROCESSING:
            // do something in the processing state
            stMachine.CallAction("run process", stm_state::ST_PROCESSING);
            if(event == stm_event::EV_PROCESS_OK)
                stMachine.gotoState(stm_state::ST_IDLE);
            else
                stMachine.gotoState(stm_state::ST_INACTIVE);
        break;
        case stm_state::ST_INACTIVE:  //Error state
            // do something in the Error state
            stMachine.CallAction("Error handling", stm_state::ST_INACTIVE);
            if(event == stm_event::EV_ERROR_ACK)
                stMachine.gotoState(stm_state::ST_IDLE);  // TBD
        break;
        default:
            //do Nothing
            stMachine.gotoState(stm_state::ST_IDLE);
        break;
        // etc...
    }
}

void Do_Action(string actionName, stm_state st){
    //cout<<"The Action name: "<<actionName<<" is executed"<<endl;
    switch (st)
    {
    case stm_state::ST_IDLE:
        /* code */
        cout <<"execute the action for IDLE state"<<endl;

        break;
    case stm_state::ST_READY:
        /* code */

        cout <<"execute the action for READY state"<<endl;
        break;
    case stm_state::ST_ACTIVE:
        /* code */

        cout <<"execute the action for ACTIVE state"<<endl;
        break;
    case stm_state::ST_PROCESSING:
        /* code */

        cout <<"execute the action for PROCESSING state"<<endl;
        break;
    case stm_state::ST_INACTIVE:
        /* code */
            //enter to safe state

        cout <<"execute the action for INACTIVE state"<<endl;
        break;
   default:
        cout <<"The state machine is in default state"<<endl;
        break;
    }
}