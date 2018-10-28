#include <irrlicht.h>
#include <iostream>

using namespace irr;


int main() {

    video::E_DRIVER_TYPE driverType;
    
    std::cout << "Please select the driver you want for this example:\n";
    std::cout << " (a) OpenGL\n";
    std::cout << " (b) Burning Software Renderer\n";
    std::cout << " (c) Direct3D 9.0c\n";
    std::cout << " (other) exit\n" << std::endl;

    char i;
    std::cin >> i;
    
    switch(i) {
        case 'a': 
            driverType = video::EDT_OPENGL;
            break;
        case 'b':
            driverType = video::EDT_BURNINGSVIDEO;
            break;
        case 'c':
            driverType = video::EDT_DIRECT3D9;
            break;
        default:
            return 1;
    }


    IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(640,480));
    
    if (device == nullptr)
        return 1;

    video::IVideoDriver *driver = device->getVideoDriver();
    scene::ISceneManager *smgr = device->getSceneManager();

    device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");

    scene::IAnimatedMesh *mesh = smgr->getMesh("20kdm2.bsp");
    scene::ISceneNode *node = nullptr;

    if (mesh) {
        node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
        // node = smgr->addMeshSceneNode(mesh->getMesh(0)); // renders the whole damn thing (slow)
    }

    if (node) {
        node->setPosition(core::vector3df(-1300, -144, -1249)); // the map is not modelled around the origin hence the offset
    }

    smgr->addCameraSceneNodeFPS();
    
    device->getCursorControl()->setVisible(false);

    // GAME LOOP INCOMING!!

    int lastFPS = 1;
    
    while (device->run()) {
    
        if (device->isWindowActive()) {
            driver->beginScene(true, true, video::SColor(255,200,200,200));
            smgr->drawAll();
    
            driver->endScene();

            int fps = driver->getFPS();

            if ( lastFPS != fps ) {
                core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";

                str += driver->getName();
                str += "] FPS: ";
                str += fps;

                device->setWindowCaption(str.c_str());
                lastFPS = fps;

            }
        
        } else {
            device->yield();
        }
    
    }

    device->drop();
    return 0;
}


