#pragma once
#include "blacklist_service.h"
#include "personen_repository.h"
#include "personen_service_exception.h"
class personen_service_impl
{

    blacklist_service &blacklists_service_;
	personen_repository& personen_repository_;

public:
    personen_service_impl(blacklist_service &blacklistsService, personen_repository &personenRepository)
            : blacklists_service_(blacklistsService), personen_repository_(personenRepository) {}

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
        try {
            speichern_impl(person_);

        } catch(const personen_service_execption &p) {
            throw p;
        } catch (...) {
            throw personen_service_execption("Unerwarteter Fehler im Reposervice");
        }

	}

    void speichern_impl(const person &person_) const {
        pruefe_person(person_);
        personen_repository_.saveOrUpdate(person_);
    }

    void pruefe_person(const person &person_) const {
        validate_person(person_);
        business_check(person_);
    }

    void business_check(const person &person_) const {
        if (blacklists_service_.is_blacklisted(person_))
            throw personen_service_execption("Person ist Antipath!");
    }

    void validate_person(const person &person_) const {
        if (person_.get_vorname().length() < 3)
            throw personen_service_execption{"Vorname zu kurz!"};

        if (person_.get_nachname().length() < 3)
            throw personen_service_execption{"Nachname zu kurz!"};
    }
};
