#pragma once

#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vulkan/vulkan_core.h>


class TriangleApplication {
    public:
        void run(){
            
            initVulkan();
            mainLoop();
            cleanUp();
        }
        
    private:
        VkInstance instance;
        

        void initVulkan(){
            
            creatInstance();
        }
        
        void creatInstance(){
            
        }

        void mainLoop(){

        
        }
        
        void cleanUp(){

        }

            
};