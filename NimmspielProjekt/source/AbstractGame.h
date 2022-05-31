#pragma once
#include "player.h"
#include "game.h"
#include "writer.h"
template<class BOARD, class MOVE>
class AbstractGame: public game
{

private:

	std::vector<player<BOARD, MOVE>*> players;
	player<BOARD, MOVE>* current_player;
	Writer& writer;
	

	void do_moves()
	{
		for (auto player : players) {
			prepare_single_move(player);
		}
		
	}
	
	void prepare_single_move(player<BOARD, MOVE>* player)
	{
		set_current_player(player);
		do_single_move();
	}
	
	void do_single_move()
	{
		if (init_move()) return;
		execute_move();
		terminate_move();

	}

	bool init_move()
	{
		if (is_gameover()) return true;
		do_something();
		return false;
	}

	void execute_move()
	{
		do players_move(); while (move_is_not_valid());


	}
	void players_move()
	{
		move = current_player->do_move(board);
	}

	bool move_is_not_valid() const
	{
		if (is_valid()) return false;
		print("Ungueltiger Zug!");
		return true;
	}

	void terminate_move()
	{
		update_game_state();
		show_gameover_message_when_game_is_over();
	}

	void show_gameover_message_when_game_is_over()
	{
		if (is_gameover())
		{
			print(current_player->get_name() + " hat verloren");
		}
	}

public:
	void set_current_player(player<BOARD, MOVE>* const current_player)
	{
		this->current_player = current_player;
	}


	

protected:
	BOARD board;
	MOVE move;

	player<BOARD, MOVE>* get_current_player() const
	{
		return current_player;
	}
	
	std::vector<player<BOARD, MOVE>*> get_players() const
	{
		return players;
	}
	void print(const std::string& message) const
	{
		writer.write(message);
	}

	virtual void do_something()
	{
		// OK
	}
	virtual bool is_gameover() const = 0;
	virtual bool is_valid() const = 0;
	virtual void update_game_state() = 0;

public:


	AbstractGame(Writer & w)
		:  writer(w)
	{
	}
	/// <summary>
	/// 
	/// </summary>
	void play() override
	{
		while (!is_gameover())
		{
			do_moves();
		}
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="player">hj  jjhgkjhg </param>
	void add_player(player<BOARD, MOVE>* player)
	{
		players.push_back(player);
	}
};

