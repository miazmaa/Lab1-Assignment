// Lab1 Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ALLEGRO_COLOR makeColor();
//draw_fish declaration. The paramaters, SCREEN_W and SCREEN_H, take in the dimensions of the screen the function will print onto. The function will draw a fish with an ellipse for a body, triangle for a tail, filled circle for an eye, and a rectangle for the mouth shape. The return type is void.
void draw_fish(const int SCREEN_W, const int SCREEN_H);

int main(int argc, char **argv) {
	//Everything in main is copied from the Primitive I and II videos available on Canvas to get the game loop functioning. I'm unfamiliar with Visual Studio, C++, and game programming, so if there's code here I could delete then I wouldn't be able to recognize it yet, sorry!
	ALLEGRO_DISPLAY* display = NULL;
	int width = 800;
	int height = 600;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro.\n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "failed to create display.");
		return -1;
	}
	al_init_primitives_addon();
	srand( time(NULL) );
	bool clear = false;

	bool done = false;


	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	al_install_keyboard();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//This is the only new statement. It calls the draw_fish function when the user inputs on the spacebar on their device.
		draw_fish(width, height);
		
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_SPACE:
					clear = true;
					break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		al_flip_display();
		if (clear == true) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			clear = false;
		}
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	return 0;
}

ALLEGRO_COLOR makeColor() {
	int red = rand() % 255;
	int green = rand() % 255;
	int blue = rand() % 255;

	return (al_map_rgb(red, green, blue));
}

void draw_fish(const int SCREEN_W, const int SCREEN_H) {

	//draw_fish is split into 4 different "sections," each labelling the variables used to create a body part per primitive added. The first section creates the width, height, and color of the body. I divided the screen width and height in 2 to print to the center of the screen.
	int x = SCREEN_W / 2;
	int y = SCREEN_H / 2;
	int body_width = 200;
	int body_height = 100;
	ALLEGRO_COLOR bodyColor = al_map_rgb(75, 0, 130);
	al_draw_filled_ellipse(x, y, body_width, body_height,bodyColor);

	//Code body for the triangle tail. 
	int tail_height = 150;
	int tail_width = 150;
	ALLEGRO_COLOR tail_color = bodyColor;
	al_draw_filled_triangle(x + body_width, y, x + body_width + tail_width, y - tail_height / 2, x + body_width + tail_width, y + tail_height / 2, tail_color);

	//Code body for the circle eye. 
	int eye_size = 20;
	ALLEGRO_COLOR eye_color = al_map_rgb(34, 139, 34);
	al_draw_filled_circle(body_width + x / 4, y-10, eye_size, eye_color);

	//Code body for the rectangle mouth.
	int mouth_width = 40;
	int mouth_height = 20;
	ALLEGRO_COLOR mouth_color = al_map_rgb(0, 0, 0);
	al_draw_filled_rectangle(x - body_width / 2 - mouth_width - 20, y - mouth_height / 2 + 40, x - body_width /2 - 20, y + mouth_height /2 + 40, mouth_color);

	//Code body for the triangle fin.
	int fin_width = 70;
	int fin_height = 60;
	ALLEGRO_COLOR fin_color = al_map_rgb(93, 63, 211);
	al_draw_filled_triangle(x + 5 , y, x + 5 + fin_width, y - fin_height / 2, x + 5 + fin_width, y + fin_height /2, fin_color);
}


