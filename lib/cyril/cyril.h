//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef CFW_CYRIL_H
#define CFW_CYRIL_H

#include <CyrilRuntime.h>
#include "Mesh.h"
#include "Camera.h"



#define CYRIL_MAIN(APP, WIDTH, HEIGHT) \
int main() {\
    try\
    {\
        CyrilRuntime<APP> app;\
        app(WIDTH, HEIGHT);\
    }\
    catch (const char* error)\
    {\
        cerr << error << endl;\
        exit(EXIT_FAILURE);\
    }\
\
    exit(EXIT_SUCCESS);\
}\



#endif //CFW_CYRIL_H
