#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else
#include <GL/glut.h>
#endif

#include <string>
#include <cmath>

using namespace std;

class igvInterfaz {
protected:
    // Atributos
    int ancho_ventana; // ancho inicial de la ventana de visualizacion
    int alto_ventana;  // alto inicial de la ventana de visualizacion
    bool ejes;
    bool circulo;
    
public:
    // Constructores por defecto y destructor
    igvInterfaz();
    ~igvInterfaz();
    
    // Metodos est�ticos
    // callbacks de eventos
    // metodo para control de eventos del teclado
    static void set_glutKeyboardFunc(unsigned char key, int x, int y);
    // m�todo que define la camara de vision y el viewport
    static void set_glutReshapeFunc(int w, int h);
    // se llama autom�ticamente cuando se cambia el tama�o de la ventana
    // m�todo para visualizar la escena
    static void set_glutDisplayFunc();
    
    
    // Metodos
    // inicializa todos los par�metros para crear una ventana de visualizaci�n
    // parametros del main
    void configura_entorno(int argc, char** argv,
                           // ancho y alto de la ventana de visualizaci�n
                           int _ancho_ventana, int _alto_ventana,
                           // posicion inicial de la ventana de visualizaci�n
                           int _pos_X, int _pos_Y,
                           // t�tulo de la ventana de visualizaci�n
                           string _titulo
    );
    void inicializa_callbacks(); // inicializa todas los callbacks
    
    // visualiza la escena y espera a eventos sobre la interfaz
    void inicia_bucle_visualizacion();
    // m�todos get_ y set_ de acceso a los atributos
    int get_ancho_ventana(){return ancho_ventana;};
    int get_alto_ventana(){return alto_ventana;};
    
    void set_ancho_ventana(int _ancho_ventana){ancho_ventana = _ancho_ventana;};
    void set_alto_ventana(int _alto_ventana){alto_ventana = _alto_ventana;};
};

#endif
