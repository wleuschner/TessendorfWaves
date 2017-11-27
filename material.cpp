#include "material.h"

Material::Material(const glm::vec3& ambient,const glm::vec3& diffuse,const glm::vec3& specular,float shininess)
{
    this->ambient=ambient;
    this->diffuse=diffuse;
    this->specular=specular;
    this->shininess=shininess;
}

Material::Material()
{
    this->ambient=glm::vec3(0.2f,0.2f,0.2f);
    this->diffuse=glm::vec3(0.4f,0.4f,0.4f);
    this->specular=glm::vec3(0.8f,0.8f,0.8f);
    this->shininess=16.0f;
}

glm::vec3 Material::getSpecular() const
{
    return specular;
}

void Material::setSpecular(const glm::vec3 &value)
{
    specular = value;
}

glm::vec3 Material::getDiffuse() const
{
    return diffuse;
}

void Material::setDiffuse(const glm::vec3 &value)
{
    diffuse = value;
}

glm::vec3 Material::getAmbient() const
{
    return ambient;
}

void Material::setAmbient(const glm::vec3 &value)
{
    ambient = value;
}

float Material::getShininess() const
{
    return shininess;
}

void Material::setShininess(float value)
{
    shininess = value;
}


