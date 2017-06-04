//
//  main.cpp
//  Test_SDL
//
//  Created by YiffyCupcake on 24/05/2017.
//  Copyright © 2017 YiffyCupcake. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#define HEIGHT 480
#define WIDTH 640




#undef main


struct personnage
{
    int x;
    int y;
    
};

// Variables
SDL_Window* window; //pointeur fenetre
SDL_Renderer* renderer;


void pause()
{
    int continuer = 1;
    SDL_Event event;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void initSDL()
{
    // Démarrage de SDL vidéo
    std::cout << "CheckInit : OK\n";
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        std::cout << "Erreur d'initialisation!" <<  SDL_GetError() << std::endl;
        exit(-1);
    }
    
    else
        
    {
        std::cout << "Chargement SDL vodeo : OK\n";
        
        // INITIALISATION
        SDL_Init(SDL_INIT_VIDEO);
    }
    
}


void createWindow()
{
    // FENETRE
    window = SDL_CreateWindow(
                              "Fenetre test",                     // window title
                              SDL_WINDOWPOS_UNDEFINED,            // initial x position
                              SDL_WINDOWPOS_UNDEFINED,            // initial y position
                              WIDTH,                                // width, in pixels
                              HEIGHT,                                // height, in pixels
                              SDL_WINDOW_SHOWN                    // flags - see below
                              
                              
                              );
}



void myRender()
{
    //RENDERER
    renderer = SDL_CreateRenderer(window, -1, 0);                  // appel au ceaterenderer pour pouvoir dessiner
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);          // On choisit la couleur
    
    SDL_RenderClear(renderer);                                     // on clear le précédent render
    
    
    
    // RECRTANGLE
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;
    
    
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );             //  bleu
    
    SDL_RenderDrawRect( renderer, &r );                             // dessin du rectangle
    
    
    // RECRTANGLE
    SDL_Rect r2;
    r2.x = 150;
    r2.y = 150;
    r2.w = 150;
    r2.h = 150;
    
    
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );             //  rouge
    
    SDL_RenderDrawRect( renderer, &r2 );                             // dessin du rectangle
    
    
    
    
    SDL_RenderPresent(renderer);                                   // on affiche le nouveau render
    

}


void checkWindow()
{
    if (window == NULL)
    {
        std::cout << "Erreur de creation de la fenetre!" <<  SDL_GetError() << std::endl;
    }

}


void loadImage(personnage perso)
{
    
    SDL_Texture  *text;
    SDL_Renderer *renderer2 = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer2, 255, 255, 255, 255);
    
    
    SDL_RenderClear(renderer2);
    
    SDL_Surface *image = NULL;
    image=IMG_Load("/Users/yiffycupcake/Documents/Code/Test_SDL/images/sanstitre.png");
    int imageW = 50, imageH = 50;       //Dimentions de l'image
    
    if(!image) {
        std::cout << "Chargement image : %s\n" << IMG_GetError() << std::endl;
    }
    else std::cout << "Chargement image : OK\n";
    
    text = SDL_CreateTextureFromSurface(renderer2, image);
    
    SDL_FreeSurface(image);
    
    
    // On centre le rectangle
    SDL_Rect dest = {(perso.x)-(imageW/2), (perso.y)-(imageH/2), 50, 50};
    
    
    
    SDL_RenderCopy(renderer2, text, NULL, &dest);
    SDL_RenderPresent(renderer2);
    
    SDL_RenderClear(renderer2);
}

void testInput ()
{
    SDL_Event event;
    
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            switch( event.type )
            {
                    
                
                /* Clavier*/
                case SDL_KEYDOWN:
                    
                    switch (event.key.keysym.sym)
                {
                        case SDLK_UP:
                        
                            std::cout << "Fleche du haut\n";
                            break;
                            
                        case SDLK_DOWN:
                            std::cout << "Fleche du bas\n";
                            break;
                        
                        case SDLK_RIGHT:
                            std::cout << "Fleche de droite\n";
                            break;
                        
                        case SDLK_LEFT:
                            std::cout << "Fleche de gauche\n";
                        
                        case SDLK_p:
                            std::cout << "Quitte avec p\n";
                            exit(12);
                        
                        
                        
                }
            }
            
                    
                    
                //case SDL_KEYUP:
        }
        
    }
}





int main(int argc, const char * argv[])
{
    
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    initSDL();
    
    personnage perso;
    perso.x = HEIGHT/2;
    perso.y = HEIGHT/2;
    
    
    
    createWindow();
    checkWindow();
    
    loadImage(perso);
    
    //testInput();
    //myRender();
    
    
    SDL_Event event;
    
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            switch( event.type )
            {
                    
                    
                    /* Clavier*/
                case SDL_KEYDOWN:
                    
                    switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        
                        perso.x++;
                        
                        std::cout << perso.x;
                        break;
                        
                    case SDLK_DOWN:
                        std::cout << "Fleche du bas\n";
                        break;
                        
                    case SDLK_RIGHT:
                        std::cout << "Fleche de droite\n";
                        break;
                        
                    case SDLK_LEFT:
                        std::cout << "Fleche de gauche\n";
                        
                    case SDLK_p:
                        std::cout << "Quitte avec p\n";
                        exit(12);
                        
                        
                        
                }
            }
            
            
            
            //case SDL_KEYUP:
        }
        
    }


    
    pause();        //on pause pour que ça ne quitte pas tout de suite la fenetre
    
    SDL_Quit();
    
    std::cout << "Exit : OK\n";
    return 0;
}
