import os
import shutil
import subprocess

PROJECT_FOLDERS = ["include", "src", "config", "build"]

def cleandir(path):
    # because this has to be cross-platform, we cant just call rm -rf ./* and thus have to implmenet it in python
    # I know this is a hack but it is the easiest to implement and the less likely to fail
    shutil.rmtree(path)
    os.mkdir(path)

def build(buildpath):
    buildpath = os.path.realpath(buildpath)
    name = os.path.split(buildpath)[-1]

    enginepath = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..")

    os.chdir(os.path.join(buildpath, "build"))
    
    subprocess.run(["cmake .. -DPROJECT_NAME=" + str(name) +" -DENGINE_PATH=" + str(enginepath) ], shell=True, cwd=os.path.join(buildpath, "build"))
    subprocess.run(["make"], shell=True, cwd=os.path.join(buildpath, "build"))
    shutil.move(os.path.join(buildpath, "build", name), os.path.join(buildpath, name))

    

def create_project(projectname, projectpath):
    # Create the project folder
    fullpath = os.path.join(projectpath, projectname)
    enginepath = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..")

    if not os.path.exists(fullpath):
        os.mkdir(fullpath)
    
    # Create the necesairy folders for a project
    for folder in PROJECT_FOLDERS:
        if not os.path.exists(os.path.join(fullpath, folder)):
            os.mkdir(os.path.join(fullpath, folder))
    
    # Copy all the files in the config folder to the newly created config folder
    for filename in os.listdir(os.path.join(enginepath, "config")):
        shutil.copy(os.path.join(enginepath, "config", filename), os.path.join(fullpath, "config", filename))
    
    # Copy the CMakeLists.txt
    shutil.copy(os.path.join(enginepath, "build", "CMakeLists.txt"), os.path.join(fullpath, "CMakeLists.txt"))

