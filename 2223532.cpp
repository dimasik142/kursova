#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>
#include <string>
#include "fparser.hh"

using namespace std;

#define X_SIZE 640
#define Y_SIZE 640
#define TEXT_FONT_FILE_PATH "../arial.ttf"

double func(double x)
{
	return x;
}

map<double, double> getFunctionPoints(double a, double b, function<double(double)> func, char name_char_form[256], int n = 10000) {
	if (!(b > a)) {
		throw exception("Bad interval");
	}
	double step = (b - a) / n;
	map<double, double> pairs;
	FunctionParser fp;
	fp.Parse(name_char_form, "x");
	for (double xIter = a; xIter <= b; xIter += step) {
		double variables[1] = { xIter };
		double result = fp.Eval(variables);
		pairs[xIter] = result;
	}
	return pairs;
}

sf::Vector2f pointToPixel(pair<double, double> point, unsigned int x_scale = 1, unsigned int y_scale = 1) {
	float x, y;
	x = (int)(x_scale * (point.first) + X_SIZE / 2);
	y = (int)(y_scale * (-point.second) + Y_SIZE / 2);
	return sf::Vector2f(x, y);
}

void writing_system_kordynat_x(sf::RenderTarget& drawArea, sf::Color color, int x_scale, int y_scale)
{
	char string[256] = "";
	float j;
	int scolse = 20;
	sf::Font font;
	font.loadFromFile(TEXT_FONT_FILE_PATH);
	sf::Text text;
	sf::VertexArray graph_x_1(sf::PrimitiveType::Lines);
	sf::VertexArray graph_x_2(sf::PrimitiveType::Lines);
	for (int i = 0; i < X_SIZE / 2; i += 25) {
		graph_x_1.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) - i, (Y_SIZE / 2) - 5), color));
		graph_x_1.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) - i, (Y_SIZE / 2) + 5), color));
		graph_x_2.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) + i, (Y_SIZE / 2) - 5), color));
		graph_x_2.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) + i, (Y_SIZE / 2) + 5), color));
		if (i != 0){
			if (i < 100){
				text.setFont(font);
				if (i % 2 == 0)
					scolse = -20;
				if (i % 2 != 0)
					scolse = 0;
				text.setPosition((X_SIZE / 2) - i - 8, (Y_SIZE / 2) + 5 + scolse);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)((i * (-1)) / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
			else {
				text.setFont(font);
				if (i % 2 == 0)
					scolse = -20;
				if (i % 2 != 0)
					scolse = 0;
				text.setPosition((X_SIZE / 2) - i - 13, (Y_SIZE / 2) + 5 + scolse);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)((i * (-1)) / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
		}
		if (i != 0){
			if (i < 100){
				text.setFont(font);
				if (i % 2 == 0)
					scolse = -20;
				if (i % 2 != 0)
					scolse = 0;
				text.setPosition((X_SIZE / 2) + i - 8, (Y_SIZE / 2) + 5 + scolse);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)(i / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
			else {
				text.setFont(font);
				if (i % 2 == 0)
					scolse = -20;
				if (i % 2 != 0)
					scolse = 0;
				text.setPosition((X_SIZE / 2) + i - 13, (Y_SIZE / 2) + 5 + scolse);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)(i / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
		}
	}
	drawArea.draw(graph_x_1);
	drawArea.draw(graph_x_2);
}

void writing_system_kordynat_y(sf::RenderTarget& drawArea, sf::Color color, int x_scale, int y_scale)
{
	char value[256] = "";
	float j;
	sf::Font font;
	font.loadFromFile(TEXT_FONT_FILE_PATH);
	sf::Text text;
	sf::VertexArray graph_y_1(sf::PrimitiveType::Lines);
	sf::VertexArray graph_y_2(sf::PrimitiveType::Lines);
	for (int i = 0; i < X_SIZE / 2; i += 25) {
		graph_y_2.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) - 5, Y_SIZE / 2 + i), color));
		graph_y_2.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) + 5, Y_SIZE / 2 + i), color));
		graph_y_1.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) - 5, Y_SIZE / 2 - i), color));
		graph_y_1.append(sf::Vertex(sf::Vector2f((X_SIZE / 2) + 5, Y_SIZE / 2 - i), color));
		if (i != 0){
			if (i < 100){
				text.setFont(font);
				text.setPosition((X_SIZE / 2) + 5, (Y_SIZE / 2) + i  - 5 );
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = ((i * (-1)) / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
			else {
				text.setFont(font);
				text.setPosition((X_SIZE / 2) + 5 , (Y_SIZE / 2) + i  - 5);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = ((i * (-1)) / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
		}
		if (i != 0){
			if (i < 100){
				text.setFont(font);
				text.setPosition((X_SIZE / 2) + 5, (Y_SIZE / 2) - i - 5);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)(i / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
			else {
				text.setFont(font);
				text.setPosition((X_SIZE / 2) + 5, (Y_SIZE / 2) - i - 5);
				text.setCharacterSize(10);
				text.setColor(sf::Color::Red);
				ostringstream out;
				j = (float)(i / (float)x_scale);
				out << setprecision(3) << j;
				text.setString(out.str());
				drawArea.draw(text);
			}
		}
	}
	drawArea.draw(graph_y_1);
	drawArea.draw(graph_y_2);
}

void drawCoordinatesSystem(sf::RenderTarget& drawArea, sf::Color color , int x_scale, int y_scale) {
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(0, Y_SIZE/2), color),
		sf::Vertex(sf::Vector2f(X_SIZE, Y_SIZE / 2), color)
	};
	drawArea.draw(line1, 2, sf::Lines);
	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(X_SIZE / 2,0), color),
		sf::Vertex(sf::Vector2f(X_SIZE/2, Y_SIZE ), color)
	};
	drawArea.draw(line2, 2, sf::Lines);
	sf::Vertex line3[] =
	{
		sf::Vertex(sf::Vector2f(X_SIZE / 2, 0), color),
		sf::Vertex(sf::Vector2f(X_SIZE / 2 - 5, 10), color)
	};
	drawArea.draw(line3, 2, sf::Lines);
	sf::Vertex line4[] =
	{
		sf::Vertex(sf::Vector2f(X_SIZE / 2, 0), color),
		sf::Vertex(sf::Vector2f(X_SIZE / 2 +5, 10), color)
	};
	drawArea.draw(line4, 2, sf::Lines);
	sf::Vertex line5[] =
	{
		sf::Vertex(sf::Vector2f(X_SIZE , Y_SIZE/2), color),
		sf::Vertex(sf::Vector2f(X_SIZE - 5, 315), color)
	};
	drawArea.draw(line5, 2, sf::Lines);
	sf::Vertex line6[] =
	{
		sf::Vertex(sf::Vector2f(X_SIZE , Y_SIZE/2), color),
		sf::Vertex(sf::Vector2f(X_SIZE - 5, 325), color)
	};
	drawArea.draw(line6, 2, sf::Lines);
	writing_system_kordynat_x(drawArea, color, x_scale, y_scale);
	writing_system_kordynat_y(drawArea, color, x_scale, y_scale);

}

void begin1()
{
	system("cls");
	cout << "             ***************************************************\n";
	cout << "             *                    Coursework                   *\n";
	cout << "             *                Plotting functions               *\n";
	cout << "             *            Performed by Dima Iwanow             *\n";
	cout << "             *                     KM-43                       *\n";
	cout << "             *          Press any key to go to menu...         *\n";
	cout << "             ***************************************************\n";
	system(" pause ");
}

void input_fuction(char * name_function){
	system("cls");
	cout << "\n\n\n\n\n\n\n " << "    Введiть функцiю, яку хочете побудувати ->  y = ";
	cin >> name_function;
}

int main() { 
	setlocale(LC_ALL, "Russian");
	begin1();
	char char_string_name[256] ;
	int variant = 4;
	while (variant != 2){
		input_fuction(char_string_name);
		sf::RenderWindow window(sf::VideoMode(X_SIZE, Y_SIZE), "SFML works!", sf::Style::Close + sf::Style::Titlebar);
		unsigned int x_scale = 25;
		unsigned int y_scale = 25;
		sf::Vector2f textPos(100, 200);
		float x_text_step = 0.7;
		float y_text_step = -1.9;
		int x_text_move_direction = 1;
		int y_text_move_direction = 1;
		auto points = getFunctionPoints(-320, 320, func, char_string_name);
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
					if (x_scale > 1)
						x_scale--;
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
					x_scale++;
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
					if (y_scale > 1)
						y_scale--;
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
					y_scale++;
				}       
				else if (event.type == sf::Event::MouseWheelScrolled) {
					if (event.mouseWheelScroll.delta > 0) {
						x_scale++;
						y_scale++;
					}
					else if (event.mouseWheelScroll.delta < 0) {
						if (x_scale > 1)
							x_scale--;
						if (y_scale > 1)
							y_scale--;
					}
				}
			}

			sf::VertexArray graph(sf::PrimitiveType::LinesStrip);
			for (auto pair : points) {
				graph.append(sf::Vertex(pointToPixel(pair, x_scale, y_scale), sf::Color::Black));
			}
			window.clear(sf::Color::White);
			drawCoordinatesSystem(window, sf::Color::Green, x_scale, y_scale);
			window.draw(graph);
			window.display();
		}
		system("cls"); 
		cout << "\n\n\n\n\n\n\n " << "    Введiть функцiю, яку хочете побудувати ->  y = " << char_string_name << endl << endl;;
		cout << "                    Продовжити побудову ? Так - 1 | Нi - 2 " << endl;
		cin >> variant;
	}
	return 0;
}