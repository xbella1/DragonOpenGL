#include "particles.h"
#include "texturingtools.h"

Particles::Particles()
{

}

Particles::~Particles()
{

}

//void Particles::init(Viewer&)
//{
//    static const GLfloat g_vertex_buffer_data[] = {
//     -0.5f, -0.5f, 0.0f,
//     0.5f, -0.5f, 0.0f,
//     -0.5f, 0.5f, 0.0f,
//     0.5f, 0.5f, 0.0f,
//    };
//    GLuint billboard_vertex_buffer;
//    glGenBuffers(1, &billboard_vertex_buffer);
//    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

//    // The VBO containing the positions and sizes of the particles
//    GLuint particles_position_buffer;
//    glGenBuffers(1, &particles_position_buffer);
//    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
//    // Initialize with empty (NULL) buffer : it will be updated later, each frame.
//    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);

//    // The VBO containing the colors of the particles
//    GLuint particles_color_buffer;
//    glGenBuffers(1, &particles_color_buffer);
//    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
//    // Initialize with empty (NULL) buffer : it will be updated later, each frame.
//    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);

//}

// void Particles::draw()
// {
//     glEnableVertexAttribArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
//     glVertexAttribPointer(
//      0, // attribute. No particular reason for 0, but must match the layout in the shader.
//      3, // size
//      GL_FLOAT, // type
//      GL_FALSE, // normalized?
//      0, // stride
//      (void*)0 // array buffer offset
//     );

//     // 2nd attribute buffer : positions of particles' centers
//     glEnableVertexAttribArray(1);
//     glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
//     glVertexAttribPointer(
//      1, // attribute. No particular reason for 1, but must match the layout in the shader.
//      4, // size : x + y + z + size => 4
//      GL_FLOAT, // type
//      GL_FALSE, // normalized?
//      0, // stride
//      (void*)0 // array buffer offset
//     );

//     // 3rd attribute buffer : particles' colors
//     glEnableVertexAttribArray(2);
//     glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
//     glVertexAttribPointer(
//      2, // attribute. No particular reason for 1, but must match the layout in the shader.
//      4, // size : r + g + b + a => 4
//      GL_UNSIGNED_BYTE, // type
//      GL_TRUE, // normalized? *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
//      0, // stride
//      (void*)0 // array buffer offset
//     );

//     glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
//     glVertexAttribDivisor(1, 1); // positions : one per quad (its center) -> 1
//     glVertexAttribDivisor(2, 1); // color : one per quad -> 1


//    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, ParticlesCount);
// }

 void Particles::animate()
 {
//     glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
//     glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
//     glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLfloat) * 4, g_particule_position_size_data);

//     glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
//     glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
//     glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLubyte) * 4, g_particule_color_data);
}

void Particles::keyPressEvent(QKeyEvent*, Viewer&)
{

}

void Particles::mouseMoveEvent(QMouseEvent*, Viewer&)
{

}


void Particles::createDispList()
{
    this->partDispList = glGenLists(1);

    glNewList(partDispList,GL_COMPILE);

    glPushMatrix();

    glBegin(GL_QUADS);

   // glNormal3f(1,0,0);

    glVertexAttrib2f(texCoords, 0,0);
    glVertex3f(-0.5,0,-0.5);

    glVertexAttrib2f(texCoords, 0,1);
    glVertex3f(-0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,1);
    glVertex3f(0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,0);
    glVertex3f(0.5,0,-0.5);

    glRotatef(90,0,1,0);

    glVertexAttrib2f(texCoords, 0,0);
    glVertex3f(-0.5,0,-0.5);

    glVertexAttrib2f(texCoords, 0,1);
    glVertex3f(-0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,1);
    glVertex3f(0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,0);
    glVertex3f(0.5,0,-0.5);

    glRotatef(90,0,0,1);
    glVertexAttrib2f(texCoords, 0,0);
    glVertex3f(-0.5,0,-0.5);

    glVertexAttrib2f(texCoords, 0,1);
    glVertex3f(-0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,1);
    glVertex3f(0.5,0,0.5);

    glVertexAttrib2f(texCoords, 1,0);
    glVertex3f(0.5,0,-0.5);

    glEnd();

    glPopMatrix();
    glEndList();
}

void Particles::draw()
{
    if(!loaded)
    {
        createDispList();
        loaded = true;
    }
    GLCHECK(glUseProgram( (GLint)program ));

    GLCHECK(glActiveTexture(GL_TEXTURE0));

    GLCHECK(glBindTexture(GL_TEXTURE_2D, textureId));

    GLCHECK(glUniform1i(texture, 0));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glRotatef(0,0,1,0);
            glCallList(partDispList);
        glPopMatrix();

    GLCHECK(glUseProgram( 0 ));
}

void Particles::init(Viewer&)
{
    Texturing::init(filename,&program,&textureId,&texture,&texCoords);
}