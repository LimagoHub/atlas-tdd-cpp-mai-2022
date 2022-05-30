#pragma once
#include "euro_to_dollar_presenter.h"
#include "../view/euro_to_dollar_view.h"


class euro_to_dollar_presenter_impl :
	public euro_to_dollar_presenter
{
private:
	euro_to_dollar_view* view_{ nullptr };
	euro_to_dollar_calculator* model_{ nullptr };
public:
	euro_to_dollar_presenter_impl() = default;

	void set_model(euro_to_dollar_calculator* model) override
	{
		model_ = model;
	}

	void set_view(euro_to_dollar_view* view) override
	{
		view_ = view;
		populate_items();
	}

	void populate_items() const override
	{

	}

	void rechnen() const override
	{

	}

	void beenden() const override
	{
        view_->dispose();
	}

	void update_rechnen_action_state() const override
	{

	}
};

