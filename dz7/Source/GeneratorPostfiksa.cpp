#include "GeneratorPostfiksa.h"
#include "BinarniOperator.h"

GeneratorPostfiksa* GeneratorPostfiksa::generator_postfiksa = nullptr;

GeneratorPostfiksa::GeneratorPostfiksa()
{
}

GeneratorPostfiksa* GeneratorPostfiksa::napravi_generator()
{
    if (generator_postfiksa == nullptr)
        generator_postfiksa = new GeneratorPostfiksa();
    return generator_postfiksa;
}

Izraz& GeneratorPostfiksa::operator()(const Izraz& i)
{
    Izraz izraz = *i.polimorfno_kopiraj();
    Izraz stack;
    Izraz* postfiks = new Izraz();
    while (izraz.dohvati_broj_podataka() > 0) {
        Element* el = *izraz;
        if (el->dohvati_vrstu() == '(') {
            // dodaj na stack svakako
            stack += *el;
        }
        else if (el->dohvati_vrstu() == ')') {
            // prazni stack sve do '('
            bool ok = false;
            while (stack.dohvati_broj_podataka() > 0) {
                Element* top = -stack;
                if (top->dohvati_vrstu() != '(') *postfiks += *top;
                else {
                    ok = true;
                    break;
                }
            }
            if (ok == false) throw exception("Izraz nepravilan.");
        }
        else if (el->dohvati_vrstu() == 'O') {
            // dodaj na stack samo ako je top '(' ili operator manjeg prioriteta
            bool ok = false;
            do {
                if (stack.dohvati_broj_podataka() > 0) {
                    Element* top = -stack;
                    if (top->dohvati_vrstu() == '(') {
                        stack += *top;
                        stack += *el;
                        ok = true;
                    }
                    else if (*dynamic_cast<BinarniOperator*>(el) > * dynamic_cast<BinarniOperator*>(top)) {
                        stack += *top;
                        stack += *el;
                        ok = true;
                    }
                    else {
                        *postfiks += *top;
                    }
                }
                else {
                    stack += *el;
                    ok = true;
                }
            } while (!ok);
        }
        else if (el->dohvati_vrstu() == 'D') {
            // dodaj u postfiks svakako
            *postfiks += *el;
        }
    }
    while (stack.dohvati_broj_podataka() > 0) {
        Element* top = *stack;
        *postfiks += *top;
    }
    return *postfiks;
}
