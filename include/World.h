#ifndef WORLD_H
#define WORLD_H

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include <stdlib.h>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <tuple>
#include "include/Particle.h"

/**
 * @brief The Scene class
 */
class World
{
public:
    /// A constructor, called when this class is instanced in the form of an object
    World();

    /// A virtual destructor, in case we want to inherit from this class
    virtual ~World();

    /// Initialises the scene, called before render().
    virtual void init();

    /// Called when the window size changes (for example, if the user maximises the window).
    virtual void resize(int w, int h);

    /// Called frequently, used if you are using some form of animation
    virtual void update();

    /// Called most frequently, redraws the scene.
    virtual void draw();

    void hashParticles();

    Vec3 getGridColumnRow(int k);

    Vec3 getRenderGridxy(int h, int w);
    Vec3 getRenderGridColumnRow(int k);
    Vec3 getRenderGridxyfromIndex(int k);

    bool isLeftButtonPressed();

    void mouseDraw(int x, int y);
    void mouseDrag(int x, int y);
    void mouseErase(int x, int y);

    std::vector<Particle *> getSurroundingParticles(int thiscell,int numsur, bool withwalls) const;

    void mouseDragEnd(int x, int y);
    void selectDraggedParticles(int x, int y);

    void getbackhere(Particle * p);

    void handleKeys(char i);

    void vectorvslist();

    void drawMenu();

    void deleteSpring(int s);
    int insertSpring(Particle::Spring spring);

    float getHalfHeight() const;
    float getHalfWidth() const;

    void toggleRain();
    void toggleGravity();
    void clearWorld();

    void drawWith(int type);

    void mouseMove(const int &x, const int &y, bool leftclick, bool rightclick);

protected: // Protected means that it is accessible to derived classes
    /// Keep track of whether this has been initialised - otherwise it won't be ready to draw!
    bool m_isInit;

    /// The time since the object was initialised, which is used for animation purposes
    double m_startTime;

    /// A member that is updated when update() is called indicating the elapsed time
    double m_elapsedTime;

    double m_timestep;

    // PARTICLES
    std::list<Particle> particles; // std::list keeps it's pointers when reallocated
    int particlesPoolSize;
    int firstFreeParticle;
    int lastTakenParticle;

    std::vector<std::vector<Particle *>> grid;
    std::vector<bool> cellsContainingParticles;
    std::vector<std::vector<float>> renderGrid;

    // WORLD SIZE ATTRIBUTES
    float halfwidth, halfheight;
    float interactionradius;
    float squaresize;
    int gridheight, gridwidth, griddepth;
    int pixelwidth, pixelheight;

    // RENDERING ATTRIBUTES
    float pointsize;
    float renderthreshold;
    int renderresolution;
    int renderwidth, renderheight;
    int renderoption;

    // SPRING ATTRIBUTES
    std::vector<Particle::Spring> springs;
    int firstFreeSpring;
    int springsize;

    std::vector<Particle *> draggedParticles;

    // Some input options
    bool rain;
    bool drawwall;
    bool gravity;

    int m_previousmousex, m_previousmousey;

    // FUN PARTICLE TYPES
    ParticleProperties water, poo, goo, oil, random;
    ParticleProperties *todraw;

    int howmanytimesrandomized;
    bool m_3d;

    float m_camerarotatey, m_camerarotatex, m_camerazoom;

};

#endif // WORLD_H
