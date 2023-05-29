#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main() {

	// creazioni di non estetici
	Event evento;
	Vector2f assi;
	int punteggio = 0;
	// creazione di estetici
	Texture nerdEmoji;
	nerdEmoji.loadFromFile("immagini\\nerdEmoji.jpg");
	Sprite giocatore;
	giocatore.setTexture(nerdEmoji);
	giocatore.setScale(0.2, 0.2);
	giocatore.setPosition(Vector2f(100, 100));

	Texture astolfo;
	astolfo.loadFromFile("immagini\\astolfo.jpg");
	Sprite nemico;
	nemico.setTexture(astolfo);

	Font cascadiaCode;
	cascadiaCode.loadFromFile("font\\CascadiaCode.ttf");
	Text testo;
	testo.setFont(cascadiaCode);

	Image icona;

	// render della finestra
    RenderWindow finestra(VideoMode(700, 500), "Scappa Da astolfo");
	finestra.setFramerateLimit(60);

	// codice della finestra
	while (finestra.isOpen()) {

		// eventi
		while (finestra.pollEvent(evento)) {

			if (evento.type == Event::Closed) finestra.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) finestra.close();

		}

		if (nemico.getPosition().x != giocatore.getPosition().x or nemico.getPosition().y != giocatore.getPosition().y) {
			
			// scritta
			testo.setString("muovi il mouse per scappare da astolfo,\nse ti prende sei morto!!!\npunteggio: " + to_string(punteggio++));

			// movimento con il mouse
			giocatore.setPosition(Vector2f(Mouse::getPosition().x - 690, Mouse::getPosition().y - 400));

			// nemico che segue il giocatore
			if (nemico.getPosition().x < giocatore.getPosition().x)
				nemico.move(assi.x + 1, assi.y);

			else if (nemico.getPosition().x > giocatore.getPosition().x)
				nemico.move(assi.x - 1, assi.y);

			if (nemico.getPosition().y < giocatore.getPosition().y)
				nemico.move(assi.x, assi.y + 1);

			else if (nemico.getPosition().y > giocatore.getPosition().y)
				nemico.move(assi.x, assi.y - 1);

			// rendering di entita
			finestra.clear();
			finestra.draw(giocatore);
			finestra.draw(testo);
			finestra.draw(nemico);
			finestra.display();

		}

		else {

			testo.setPosition(240, 500 / 2);
			testo.setString("hai perso!!! :(\npunteggio: " + to_string(punteggio));

			// rendering di entita
			finestra.clear();
			finestra.draw(testo);
			finestra.display();

		}
		

	}

}