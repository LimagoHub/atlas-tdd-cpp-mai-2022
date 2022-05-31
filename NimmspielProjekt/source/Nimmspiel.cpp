// Nimmspiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "takegame_impl.h"
#include "game_client.h"
#include "human_player.h"
#include "computer_player.h"
#include "consolen_writer.h"
int main()
{
	consolen_writer my_writer;
	
    takegame_impl game{my_writer};

	
	human_player human{ "Spieler" };
	computer_player computer{ "Computer" };

	game.add_player(&human);
	game.add_player(&computer);
	
	game_client client{ game };
	client.go();
}

