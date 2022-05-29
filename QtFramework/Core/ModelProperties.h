#ifndef MODELPROPERTIES_H
#define MODELPROPERTIES_H

#include <GL/glew.h>
#include "DCoordinates3.h"
#include <fstream>
#include "Materials.h"

using namespace cagd;
using namespace std;

enum MatTypes {Brass,
               Gold,
               Silver,
               Emerald,
               Pearl,
               Ruby,
               Turquoise};

struct ModelProperties
{
    GLuint       id;        // identifies a model, i.e., _model[id]
    DCoordinate3 position;  // new position of the middle point of the model's bounding box
    GLdouble     angle[3];  // rotational angles
    GLdouble     scale[3];  // scaling parameters
    int    matID;
};

inline istream& operator >>(istream& lhs, ModelProperties& rhs){
    lhs >> rhs.id;
    lhs >> rhs.position;
    for(GLint i = 0; i < 3; i++){
        lhs >> rhs.angle[i];
    }
    for(GLint i = 0; i < 3; i++){
        lhs >> rhs.scale[i];
    }
    lhs >> rhs.matID;
    return lhs;
}

inline ostream& operator <<(ostream& lhs, const ModelProperties& rhs){
    lhs << rhs.id << endl;
    lhs << rhs.position << endl;
    for(GLint i = 0; i < 3; i++){
        lhs << rhs.angle[i] << " ";
    }
    lhs << endl;
    for(GLint i = 0; i < 3; i++){
        lhs << rhs.scale[i] << " ";
    }
    lhs << endl;
    return lhs;
}

inline void applyMaterial(const ModelProperties& mat){
    switch(mat.matID){
        case Brass:
            MatFBBrass.Apply();
            break;
        case Gold:
            MatFBGold.Apply();
            break;
        case Silver:
            MatFBSilver.Apply();
            break;
        case Emerald:
            MatFBEmerald.Apply();
            break;
        case Pearl:
            MatFBPearl.Apply();
            break;
        case Ruby:
            MatFBRuby.Apply();
            break;
        case  Turquoise:
            MatFBTurquoise.Apply();
            break;
    }
}

#endif // MODELPROPERTIES_H
