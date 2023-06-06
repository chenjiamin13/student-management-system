#ifndef SIMS_PUBLIC_H
#define SIMS_PUBLIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 20
#define PASS_LEN 20
#define DATE_LEN 12

#include "admin.h"
#include "teacher.h"
#include "student.h"
#include "viewer.h"

#define DEBUG_ERROR

#ifdef DEBUG_ERROR
#define Print_Error printf("Error:in %s at %d--",__FILE__,__LINE__);printf
#else
#define Print_Error(...) 
#endif



#define DEBUG_WARNING

#ifdef DEBUG_WARNING
#define Print_Warning printf("Warning:in %s at %d--",__FILE__,__LINE__);printf
#else
#define Print_Warning(...)
#endif


#define DEBUG_INFO

#ifdef DEBUG_INFO
#define Print_Info printf("Info:in %s at %d--",__FILE__,__LINE__);printf
#else
#define Print_Info(...) 
#endif


#endif

