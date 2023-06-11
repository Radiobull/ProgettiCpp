#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

/*
non so perchè ma nella soluzione di visual studio posso riscrivere i file ma quando trasferisco i file no.
*/

int main() {

	// creazioni di non estetici
	Event evento;
	Vector2f assi;
	int punteggio = 0;
	int difficolta = 0;
	//string record;
	int record = 0;
	short suono = 50;
	//bool modalitaSpeciale = false;
	Music musica;
	musica.openFromFile("suoni\\music.ogg");
	musica.setLoop(true);
	musica.play();


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

	Texture tastiera;
	tastiera.loadFromFile("immagini\\commandi.png");
	Sprite commandi;
	commandi.setTexture(tastiera);
	commandi.setPosition(0, 250);
	commandi.setScale(0.3, 0.3);

	Font cascadiaCode;
	cascadiaCode.loadFromFile("font\\CascadiaCode.ttf");
	Text testoGenerico;
	testoGenerico.setFont(cascadiaCode);
	testoGenerico.setFillColor(Color::Black);

	Text testoSuono;
	testoSuono.setFont(cascadiaCode);
	testoSuono.setFillColor(Color::Black);

	Texture castello;
	castello.loadFromFile("immagini\\castello.jpg");
	Sprite sfondo;
	sfondo.setTexture(castello);
	sfondo.setPosition(Vector2f(0, 0));

	Texture castelloMenu;
	castelloMenu.loadFromFile("immagini\\castelloMenu.jpg");
	Sprite sfondoMenu;
	sfondoMenu.setTexture(castelloMenu);
	sfondoMenu.setPosition(Vector2f(0, 0));

	Texture scritta;
	scritta.loadFromFile("immagini\\titolo.png");
	Sprite titolo;
	titolo.setTexture(scritta);
	titolo.setPosition(Vector2f(170, 0));
	titolo.setScale(0.4, 0.4);

	Image icona;
	icona.loadFromFile("immagini\\icona.png");

	/*fstream fileLettura;
	fileLettura.open("punteggio.txt", ios::in);
	getline(fileLettura, record);
	fileLettura.close();*/

	// render della finestra
	RenderWindow finestra(VideoMode(700, 500), "Scappa Da Astolfo", sf::Style::Titlebar | sf::Style::Close);
	finestra.setFramerateLimit(60);
	finestra.setIcon(icona.getSize().x, icona.getSize().y, icona.getPixelsPtr());

	// codice della finestra
	while (finestra.isOpen()) {

		testoSuono.setString("volume: " + to_string(suono));

		// eventi
		while (finestra.pollEvent(evento)) {

			if (evento.type == Event::Closed) finestra.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) finestra.close();
			if (Keyboard::isKeyPressed(Keyboard::Num1) and difficolta == 0) difficolta = 1;
			if (Keyboard::isKeyPressed(Keyboard::Num2) and difficolta == 0) difficolta = 5;
			if (Keyboard::isKeyPressed(Keyboard::Num3) and difficolta == 0) difficolta = 7;
			if(Keyboard::isKeyPressed(Keyboard::Up) and suono < 100) musica.setVolume(suono++);
			if (Keyboard::isKeyPressed(Keyboard::Down) and suono > 0) musica.setVolume(suono--);
			if (Keyboard::isKeyPressed(Keyboard::Left)) musica.pause();
			if (Keyboard::isKeyPressed(Keyboard::Right)) musica.play();
			//if (Keyboard::isKeyPressed(Keyboard::Num9) and difficolta == 0) modalitaSpeciale = true;
			if (Keyboard::isKeyPressed(Keyboard::Enter) and difficolta != 0) {

				difficolta = 0;
				punteggio = 0;
				giocatore.setPosition(Vector2f(100, 200));
				nemico.setPosition(Vector2f(0, 0));
				testoGenerico.setPosition(0, 0);

			}


		}

		if (difficolta == 0) {

			//testoGenerico.setString("scegliere una difficolta tra:\n1- facile\n2- media\n3- difficile\nrecord: " + record);
			testoGenerico.setString("scegliere una difficolta tra:\n1- facile\n2- media\n3- difficile\nrecord della sessione: " + to_string(record));
			testoGenerico.setPosition(Vector2f(0, 55));
			testoSuono.setPosition(500, 450);

			// rendering di entita
			finestra.clear();
			finestra.draw(sfondoMenu);
			finestra.draw(testoGenerico);
			finestra.draw(titolo);
			finestra.draw(commandi);
			finestra.draw(testoSuono);
			finestra.display();

		}

		/*else if (modalitaSpeciale and !giocatore.getGlobalBounds().intersects(nemico.getGlobalBounds())) {

			testoGenerico.setString("Non ti spieghero il tutorial >:)\npunteggio: " + to_string(punteggio++));

		}*/

		else if (!giocatore.getGlobalBounds().intersects(nemico.getGlobalBounds())) {

			// scritta
			testoGenerico.setString("muovi il mouse per scappare da astolfo,\nse ti prende sei morto!!!\npunteggio: " + to_string(punteggio++));
			testoGenerico.setPosition(Vector2f(0, 0));
			testoSuono.setPosition(500, 450);

			// movimento con il mouse
			giocatore.setPosition(Vector2f(Mouse::getPosition(finestra).x - 50, Mouse::getPosition(finestra).y - 50));

			if (giocatore.getPosition().x < 0) {

				giocatore.setPosition(Vector2f(0, Mouse::getPosition(finestra).y - 50));

				if (giocatore.getPosition().y < 0)
					giocatore.setPosition(Vector2f(0, 0));

				if (giocatore.getPosition().y > 400)
					giocatore.setPosition(Vector2f(0, 400));

			}

			if (giocatore.getPosition().x > 600) {

				giocatore.setPosition(Vector2f(600, Mouse::getPosition(finestra).y - 50));

				if (giocatore.getPosition().y < 0)
					giocatore.setPosition(Vector2f(600, 0));

				if (giocatore.getPosition().y > 400)
					giocatore.setPosition(Vector2f(600, 400));

			}

			if (giocatore.getPosition().y < 0)
				giocatore.setPosition(Vector2f(Mouse::getPosition(finestra).x - 50, 0));

			if (giocatore.getPosition().y > 400)
				giocatore.setPosition(Vector2f(Mouse::getPosition(finestra).x - 50, 400));

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
			finestra.draw(sfondo);
			finestra.draw(giocatore);
			finestra.draw(nemico);
			finestra.draw(testoGenerico);
			finestra.draw(testoSuono);
			finestra.display();

		}

		else {

			testoGenerico.setPosition(135, 150);
			testoGenerico.setString("hai perso!!! :(\npunteggio: " + to_string(punteggio) + "\npremere invio per riavviare");
			testoSuono.setPosition(500, 450);

			if (record < punteggio)
				record = punteggio;

			// riscrive il file se e solo se il punteggio è piu alto in più riscrivo la variabile record cosi lo vedo subito invece di apsettare che si aggiorni dal file.txt
			/*if (stoi(record) < punteggio) {

				fstream fileScrittura("punteggio.txt", ios::out);
				fileScrittura << to_string(punteggio);
				fileScrittura.close();
				record = to_string(punteggio);

			}

			fileLettura.close();*/

			// rendering di entita
			finestra.clear();
			finestra.draw(sfondoMenu);
			finestra.draw(testoGenerico);
			finestra.draw(testoSuono);
			finestra.display();

		}

	}

}