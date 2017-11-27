#ifndef MATERIAL_H
#define MATERIAL_H
#include<glm/glm.hpp>

class Material
{
private:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
public:
    Material();
    Material(const glm::vec3& ambient,const glm::vec3& diffuse,const glm::vec3& specular,float shininess);
    glm::vec3 getSpecular() const;
    void setSpecular(const glm::vec3 &value);
    glm::vec3 getDiffuse() const;
    void setDiffuse(const glm::vec3 &value);
    glm::vec3 getAmbient() const;
    void setAmbient(const glm::vec3 &value);
    float getShininess() const;
    void setShininess(float value);
};

#endif // MATERIAL_H
