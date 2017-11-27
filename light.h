#ifndef LIGHT_H
#define LIGHT_H
#include<glm/glm.hpp>
#include<QList>

class Light
{
public:
    Light();
    Light(glm::vec3& pos);
    Light(glm::vec3& pos,glm::vec3& ambient,glm::vec3& diffuse,glm::vec3& specular);

    void setPosition(glm::vec3& pos);
    void setAmbient(glm::vec3& ambient);
    void setDiffuse(glm::vec3& diffuse);
    void setSpecular(glm::vec3& specular);

    const glm::vec3& getPosition();
    const glm::vec3& getAmbient();
    const glm::vec3& getDiffuse();
    const glm::vec3& getSpecular();

    static void addLight(Light*);
    static void removeLight(Light*);
    static void getLight(int index);
    static void clearLights();
    static QList<Light*>& getLights();

private:
    static QList<Light*> lights;
    glm::vec3 pos;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

#endif // LIGHT_H
