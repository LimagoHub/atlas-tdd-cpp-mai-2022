#pragma once
#include "personen_repository.h"
#include "personen_service_exception.h"
class personen_service_impl
{

	personen_repository& personen_repository_;

public:
	personen_service_impl(personen_repository& personen_repository)
		: personen_repository_(personen_repository)
	{
	}
	/// <summary>
	/// vorname nicht lang genug -> PSE
	/// nachname nicht lang genug -> PSE
	/// vorname darf nicht Attila ->PSE
	/// Wenn Exception im Repo -> PSE
	/// alles ok -> person passed to repo
	/// </summary>
	/// <param name="person"></param>
	void speichern(person person_)
	{
        if(person_.get_vorname().length() < 3)
            throw personen_service_execption{"Vorname zu kurz!"};

        throw personen_service_execption{"Nachname zu kurz!"};
	}
};
