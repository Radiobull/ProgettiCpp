#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main() {

	// creazioni di non estetici
	Event evento;
	Vector2f assi;
	int punteggio = 0;
	int difficolta = 0;

	// creazione di estetici
	Texture nerdEmoji;
	nerdEmoji.loadFromFile("immagini\\nerdEmoji.jpg");
	Sprite giocatore;
	giocatore.setTexture(nerdEmoji);
	giocatore.setScale(0.2, 0.2);
	giocatore.setPosition(Vector2f(100, 200));

	Texture astolfo;
	astolfo.loadFromFile("immagini\\astolfo.jpg");
	Sprite nemico;
	nemico.setTexture(astolfo);

	Font cascadiaCode;
	cascadiaCode.loadFromFile("font\\CascadiaCode.ttf");
	Text testo;
	testo.setFont(cascadiaCode);

	// render della finestra
    RenderWindow finestra(VideoMode(700, 500), "Scappa Da astolfo", sf::Style::Titlebar | sf::Style::Close);
	finestra.setFramerateLimit(60);

	// codice della finestra
	while (finestra.isOpen()) {

		// eventi
		while (finestra.pollEvent(evento)) {

			if (evento.type == Event::Closed) finestra.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) finestra.close();
			if (Keyboard::isKeyPressed(Keyboard::Num1) and difficolta == 0) difficolta = 1;
			if (Keyboard::isKeyPressed(Keyboard::Num2) and difficolta == 0) difficolta = 5;
			if (Keyboard::isKeyPressed(Keyboard::Num3) and difficolta == 0) difficolta = 7;
			if (Keyboard::isKeyPressed(Keyboard::Enter) and difficolta != 0) {

				difficolta = 0;
				punteggio = 0;
				giocatore.setPosition(Vector2f(100, 200));
				nemico.setPosition(Vector2f(0, 0));
				testo.setPosition(0, 0);

			}


		}

		if (difficolta == 0) {

			testo.setString("MENU:\nscegliere una difficolta tra:\n1- facile\n2- media\n3- difficile");

			// rendering di entita
			finestra.clear();
			finestra.draw(testo);
			finestra.display();

		}

		else if (!giocatore.getGlobalBounds().intersects(nemico.getGlobalBounds())) {
			
			// scritta
			testo.setString("muovi il mouse per scappare da astolfo,\nse ti prende sei morto!!!\npunteggio: " + to_string(punteggio++));

			// movimento con il mouse

			giocatore.setPosition(Vector2f(Mouse::getPosition().x - 690, Mouse::getPosition().y - 400));

			if (giocatore.getPosition().x < 0) {

				giocatore.setPosition(Vector2f(0, Mouse::getPosition().y - 400));

				if (giocatore.getPosition().y < 0)
					giocatore.setPosition(Vector2f(0, 0));

				if(giocatore.getPosition().y > 400)
					giocatore.setPosition(Vector2f(0, 400));

			}

			if (giocatore.getPosition().x > 600) {

				giocatore.setPosition(Vector2f(600, Mouse::getPosition().y - 400));

				if (giocatore.getPosition().y < 0)
					giocatore.setPosition(Vector2f(600, 0));

				if (giocatore.getPosition().y > 400)
					giocatore.setPosition(Vector2f(600, 400));

			}

			if (giocatore.getPosition().y < 0)
				giocatore.setPosition(Vector2f(Mouse::getPosition().x - 690, 0));

			if (giocatore.getPosition().y > 400)
				giocatore.setPosition(Vector2f(Mouse::getPosition().x - 690, 400));

			// nemico che segue il giocatore
			if (nemico.getPosition().x < giocatore.getPosition().x)
				nemico.move(assi.x + difficolta, assi.y);

			if (nemico.getPosition().x > giocatore.getPosition().x)
				nemico.move(assi.x - difficolta, assi.y);

			if (nemico.getPosition().y < giocatore.getPosition().y)
				nemico.move(assi.x, assi.y + difficolta);

			if (nemico.getPosition().y > giocatore.getPosition().y)
				nemico.move(assi.x, assi.y - difficolta);

			// rendering di entita
			finestra.clear();
			finestra.draw(giocatore);
			finestra.draw(testo);
			finestra.draw(nemico);
			finestra.display();

		}

		else {

			testo.setPosition(190, 250);
			testo.setString("hai perso!!! :(\npunteggio: " + to_string(punteggio) + "\npremere invio per riavviare");

			// rendering di entita
			finestra.clear();
			finestra.draw(testo);
			finestra.display();

		}
		

	}

}