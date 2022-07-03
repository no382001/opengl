#include <stdio.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 400, HEIGHT = 600;

int main(){
    //init glfw
    if(!glfwInit()){
        printf("GLFW init failed");
        glfwTerminate();
        return 1; //seg error
    }

    //setup glfw windiw properties
    //opengl version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    //no backwards compat
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //allow forward compatible
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    
    //null = mode, null = shared window
    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH,HEIGHT,"testwindow",NULL,NULL);

    if(!mainWindow){
        printf("GLFW win create failed");
        glfwTerminate();
        return 1;
    }

    //get buffer size info
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow,&bufferWidth,&bufferHeight);

    //set context for glew to use
    glfwMakeContextCurrent(mainWindow);

    //allow modern extension features
    glewExperimental = GL_TRUE;

    //init glew
    if(glewInit() != GLEW_OK){
        printf("glew init failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    //set viewport size
    glViewport(0,0,bufferWidth,bufferHeight);

    //loop until window closed

    while(!glfwWindowShouldClose(mainWindow)){
        //get + handle user input events
        glfwPollEvents();
        
        //clear window (r,g,b,a)
        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);

    }





    return 0;
}