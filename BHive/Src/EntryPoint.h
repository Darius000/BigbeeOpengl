#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H


#include "Core/Application.h"
#include "Core/World.h"

#ifdef BHIVE_WINDOWS

BHive::Application* CreateApplication();

int main(int argc, char** argv);

#endif
#endif