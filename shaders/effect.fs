#version 130
struct LightSource
{
    vec3 pos;
    vec3 amb;
    vec3 dif;
    vec3 spec;
};

struct Material
{
    vec3 amb;
    vec3 dif;
    vec3 spec;
    float shininess;
};

uniform vec4 eye;

uniform Material material;

uniform LightSource light[12];
uniform int numLights;

uniform mat4 view;
uniform mat3 normalMatrix;

in vec3 frag_position;
in vec3 frag_normal;

out vec4 fragColor;

void main(void) {
    float nAir = 1.0;
    float nWater = 1.333;
    vec3 normal = normalize(frag_normal);
    vec3 pos = frag_position;
    vec3 vdir = normalize(pos-eye.xyz);
    vec4 color = vec4(0.0,0.0,0.0,1.0);
    float R0 = ((nAir-nWater)/(nAir+nWater))*((nAir-nWater)/(nAir+nWater));
    for(int i=0;i<numLights;i++)
    {
        vec3 ldir = normalize(pos - vec3((vec4(light[i].pos,1.0)).xyz));
        vec3 halfDir = reflect(ldir,normal);

        float F = 0.0;
        F = min(1.0,max(0.0,R0 + (1.0-R0) * pow(dot(vdir,halfDir),5)));
        color += vec4((1.0-F)*vec3(0.0,0.3,0.7)+F*(vec3(0.7,0.7,0.7)),mix(0.8,0.4,1.0-F));

    }
    fragColor = vec4(color);
}
