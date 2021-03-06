#include <irrlicht.h>
#include <iostream>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main() {

    IrrlichtDevice *device = createDevice(
        video::EDT_SOFTWARE, core::dimension2d<u32>(640, 480),
        16,
        false,
        false,
        false,
        0
    );

    if (!device) {
        return 1;
    }

    device->setWindowCaption(L"Hello world! - IrrLicht Engine Demo");

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();
    IGUIEnvironment *guienv = device->getGUIEnvironment();

    guienv->addStaticText(
        L"Hello world! This is the Irrlicht Software renderer!", 
        rect<s32>(10, 10, 260, 45), 
        true
    );

    IAnimatedMesh *mesh = smgr->getMesh("media/sydney.md2");
    if ( !mesh ) {
        device->drop();
        return 1;
    }

    IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);

    if (node) {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture( 0, driver->getTexture("media/sydney.bmp") );
    }

    smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

    while ( device->run() ) {
        driver->beginScene(true, true, SColor(255, 100, 101, 140)); 

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
    }

    device->drop();

    return 0;
}
