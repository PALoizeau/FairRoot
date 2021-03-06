/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// WARNING : pragma commands to hide boost warning
// TODO : remove these pragma commands when boost will fix this issue in future release

#if defined(__clang__)
    _Pragma("clang diagnostic push") 
    _Pragma("clang diagnostic ignored \"-Wshadow\"") 
    #include "logger.h"
    _Pragma("clang diagnostic pop")
#elif defined(__GNUC__) || defined(__GNUG__)
    _Pragma("GCC diagnostic push")
    _Pragma("GCC diagnostic ignored \"-Wshadow\"")
    #include "logger.h"
    _Pragma("GCC diagnostic pop")
#endif
    
 void test_logger()
 {
    LOG(TRACE) << "this is a trace message";
    LOG(DEBUG) << "this is a debug message";
    LOG(RESULTS) << "this is a results message";
    LOG(INFO) << "this is a info message";
    LOG(WARN) << "this is a warning message";
    LOG(ERROR) << "this is an error message";
    LOG(STATE) << "this is a state message";
 }
 
 void test_set_level()
 {
    std::cout<<"********* test logger : SET_LOG_LEVEL(lvl) *********"<<std::endl;
    SET_LOG_LEVEL(TRACE);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(DEBUG);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(RESULTS);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(INFO);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(WARN);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(ERROR);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
    
    SET_LOG_LEVEL(STATE);
    test_logger();
    std::cout << "----------------------------"<<std::endl;
 }
 

  
int main() 
{
    INIT_LOG_FILE_FILTER("test_log_file",GREATER_EQ_THAN,ERROR);// init and add one sink to the core
    test_set_level();
    INIT_LOG_FILE_FILTER("test_another_log_file",EQUAL,INFO);// init and add another sink to the core
    test_set_level();
    reinit_logger(false);
    test_set_level();
    return 0;
}


