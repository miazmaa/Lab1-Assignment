// Lab1 Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ALLEGRO_COLOR makeColor();
void draw_random_pixel(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

int main(int argc, char **argv) {

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
	}

}
