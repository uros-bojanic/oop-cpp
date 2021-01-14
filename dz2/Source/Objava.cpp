#include "Objava.h"

Objava::Objava(Korisnik* korisnik, string s) : Obavestenje(korisnik)
{
	tekst = s;
}

Objava::Objava(Obavestenje o, string s) : Obavestenje(o)
{
	tekst = s;
}
