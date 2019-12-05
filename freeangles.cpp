#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>

using namespace std;

vector<pair<double,int>> angulos(12); //Vector que guarda os ângulos que possuem obstáculos
vector<pair<int, string>> classificacao(12); //Ângulo, ID do Robô e String falando se o Robô é um aliado ou adversário
int angClas[12]; //Vetor que armazena os estados dos ângulos
int qtRobos = 3; //Quantidade de Robôs presentes no campo

void classificarAngulo(){
    for(int i = 0; i < qtRobos-1; i++){
        if(angulos[i].second%2 != 0){
            classificacao[i].second = "O robô do time adversario de ID: ";
            classificacao[i].first = angulos[i].second;
            angClas[i] = 0;
        }else{
            classificacao[i].second = "O robô do time aliado, de ID: ";
            classificacao[i].first = angulos[i].second;
            angClas[i] = 2;
        }
    }
}

void criarAngulo(vector<pair<pair<double, double>, pair<double, double>>> x, int idDoRobo, int idDoRobo1){
    double coefAng1, coefAng2, alfa, angulo;
    double y1i, y2i, x1i, x2i, y1f, y2f, x1f, x2f;
    int k = 1;

    angulos[0].second = idDoRobo;
    angulos[1].second = idDoRobo1;

    //cout<<"TAM DO VETOR: "<<x.size()<<endl;
    
    for(int i = 0; i < qtRobos-1; i++){
        
        cout<<"CASE "<<i<<endl<<endl;
        cout<<"Reta 1 || x1-> "<<x[k-1].first.first<<" y1-> "<<x[k-1].first.second<<"     x2-> "<<x[k-1].second.first<<" y2-> "<<x[k-1].second.second<<endl;
        cout<<"Reta 2 || x1-> "<<x[k].first.first<<" y1-> "<<x[k].first.second<<"     x2-> "<<x[k].second.first<<" y2-> "<<x[k].second.second<<endl<<endl;

        x1i = x[k-1].first.first; 
        x2i = x[k-1].second.first;
        y1i = x[k-1].first.second;
        y2i = x[k-1].second.second;
        x1f = x[k].first.first;
        x2f = x[k].second.first;
        y1f = x[k].first.second;
        y2f = x[k].second.second; 
       
        if(((x1i != 0) && (x2i != 0) && (y1i != 0) && (y2i != 0)) && ((x1f != 0) && (x2f != 0) && (y1f != 0) && (y2f != 0))){
            coefAng1 = (y2i-y1i)/(x2i-x1i); //Coeficiente Ângular da primeira reta
            coefAng2 = (y2f-y1f)/(x2f-x1f); //Coeficiente Ângular da segunda reta
            cout<<"COEFICIENTES ANGULARES 1 E 2: "<<coefAng1<<" "<<coefAng2<<endl;
            alfa = ((coefAng2-coefAng1)/(1+(coefAng2*coefAng1)));
            //cout<<"ALFA: "<<alfa<<endl<<endl;
            angulo = tan(alfa);
            //cout<<"ANGULO: "<<angulo<<endl;
            angulos[i].first = abs(angulo); //Armazenando o ângulo no meu vector que armazena todos os ângulos obstruídos
            cout<<"ÂNGULO: "<<angulos[i].first<<"º graus"<<endl<<endl;
        }

        k+=2;
    }  
}

int main(){

    sf::RenderWindow janela(sf::VideoMode(900, 600), "Free Angles");

    sf::RectangleShape background(sf::Vector2f(900,600));
    background.setFillColor(sf::Color(0,98,51));
    background.setPosition(0,0);

    sf::Vertex lateralEsq[] = {
        sf::Vertex(sf::Vector2f(20, 25)),
        sf::Vertex(sf::Vector2f(20, 575))
    };    

    sf::Vertex lateralDir[] = {
        sf::Vertex(sf::Vector2f(880, 25)),
        sf::Vertex(sf::Vector2f(880, 575))
    };  

    sf::Vertex fundoCim[] = {
        sf::Vertex(sf::Vector2f(19, 25)),
        sf::Vertex(sf::Vector2f(880, 25))
    };
    
    sf::Vertex fundoBaix[] = {
        sf::Vertex(sf::Vector2f(19, 575)),
        sf::Vertex(sf::Vector2f(880, 575))
    };

    sf::Vertex meioCamp[] = {
        sf::Vertex(sf::Vector2f(450, 25)),
        sf::Vertex(sf::Vector2f(450, 575))
    };

    sf::CircleShape centro(48);
    centro.setOutlineThickness(1);
    centro.setOutlineColor(sf::Color(255, 255, 255));
    centro.setFillColor(sf::Color::Transparent);
    centro.setOrigin(-402,-252);

    /*sf::CircleShape bola(7);
    bola.setFillColor(sf::Color::Red);
    bola.setPosition(443,293);*/ 

    sf::Vertex golCimE[] = {
        sf::Vertex(sf::Vector2f(20, 233)),
        sf::Vertex(sf::Vector2f(77, 233))
    };

    sf::Vertex golCimD[] = {
        sf::Vertex(sf::Vector2f(20, 363)),
        sf::Vertex(sf::Vector2f(77, 363))
    };

    sf::Vertex golCimB[] = {
        sf::Vertex(sf::Vector2f(77, 233)),
        sf::Vertex(sf::Vector2f(77, 363))
    };

    sf::Vertex golBaiE[] = {
        sf::Vertex(sf::Vector2f(823, 233)),
        sf::Vertex(sf::Vector2f(880, 233))
    };

    sf::Vertex golBaiD[] = {
        sf::Vertex(sf::Vector2f(823, 363)),
        sf::Vertex(sf::Vector2f(880, 363))
    };

    sf::Vertex golBaiB[] = {
        sf::Vertex(sf::Vector2f(823, 233)),
        sf::Vertex(sf::Vector2f(823, 363))
    };

    sf::Font asman;
    asman.loadFromFile("ASMAN.TTF");

    sf::Text r1T("1", asman);
    r1T.setCharacterSize(30);
    r1T.setFillColor(sf::Color::Black);

    sf::Text r2T("2", asman);
    r2T.setCharacterSize(30);
    r2T.setFillColor(sf::Color::Black);

    sf::Text r1M("1", asman);
    r1M.setCharacterSize(30);
    r1M.setFillColor(sf::Color::Black);

    sf::CircleShape robo1T(14);
    robo1T.setFillColor(sf::Color::Yellow);
    robo1T.setPosition(330, 286);
    robo1T.setOutlineThickness(1);
    robo1T.setOutlineColor(sf::Color(0, 0, 0));
    double x1T = 330, y1T = 286;
    int id1T = 0;

    sf::CircleShape robo2T(14);
    robo2T.setFillColor(sf::Color::Yellow);
    robo2T.setPosition(250, 286);
    robo2T.setOutlineThickness(1);
    robo2T.setOutlineColor(sf::Color(0, 0, 0));
    double x2T = 250, y2T = 286;
    int id2T = 2;

    sf::CircleShape robo1M(14);
    robo1M.setFillColor(sf::Color::Blue);
    robo1M.setPosition(530, 286);
    robo1M.setOutlineThickness(1);
    robo1M.setOutlineColor(sf::Color(0, 0, 0));
    double x1M = 530, y1M = 286; 
    int id1M = 1;

    vector<pair<double, double>> posicoes(12); //Vector que guardas as posições X e Y de cada Robô que está em campo
    vector<pair<pair<double, double>, pair<double, double>>> retas(12); //Vector que guarda o X inicial e o X final, juntamente com o Y inicial e o Y final de cada reta (x1, y1),(x2, y2) 
    bool check = true; //Booleano utilizado para fazer uma verificação

    posicoes[id1T].first = x1T; //330, posição X inicial do Robô 1 do time amarelo
    posicoes[id1T].second = y1T; //286, posição Y inicial do Robô 1 do time amarelo
    posicoes[id1M].first = x1M; //530, posição X inicial do Robô 1 do time azul
    posicoes[id1M].second = y1M; //286, posição Y inicial do Robô 1 do time azul
    posicoes[id2T].first = x2T; //250, posição X inicial do Robô 2 do time amarelo
    posicoes[id2T].second = y2T; //286, posição Y inicial do Robô 2 do time amarelo

    while(janela.isOpen()){
        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
                cout<<"Janela fechada com sucesso!"<<endl;
            }
        }
        
        janela.clear(sf::Color::Black);
    
        janela.draw(background);

        janela.draw(lateralEsq, 2, sf::Lines);
        janela.draw(lateralDir, 2, sf::Lines);
        
        janela.draw(fundoCim, 2, sf::Lines);
        janela.draw(fundoBaix, 2, sf::Lines);
        
        janela.draw(meioCamp, 2, sf::Lines);
        
        janela.draw(centro);
        
        janela.draw(golCimE, 2, sf::Lines);
        janela.draw(golCimD, 2, sf::Lines);
        janela.draw(golCimB, 2, sf::Lines);
        janela.draw(golBaiE, 2, sf::Lines);
        janela.draw(golBaiD, 2, sf::Lines);
        janela.draw(golBaiB, 2, sf::Lines);

        janela.draw(robo1T);
        janela.draw(robo2T);
        janela.draw(robo1M);

        r1T.setPosition(robo1T.getPosition().x+10, robo1T.getPosition().y-5);
        janela.draw(r1T);
        r2T.setPosition(robo2T.getPosition().x+8, robo2T.getPosition().y-5);
        janela.draw(r2T);   
        r1M.setPosition(robo1M.getPosition().x+10, robo1M.getPosition().y-5);
        janela.draw(r1M);

        //Comandos do Keyboard para movimentar o Robô 1 do time amarelo

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            x1T += 0.5;
            posicoes[id1T].first = x1T;
            robo1T.setPosition(x1T, y1T);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();

            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time amarelo foi movido para a direita"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            x1T -= 0.5;
            posicoes[id1T].first = x1T;
            robo1T.setPosition(x1T, y1T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time amarelo foi movido para a esquerda"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            y1T += 0.5;
            posicoes[id1T].second = y1T;
            robo1T.setPosition(x1T, y1T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();

            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time amarelo foi movido para baixo"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            y1T -= 0.5;
            posicoes[id1T].second = y1T;
            robo1T.setPosition(x1T, y1T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();

            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time amarelo foi movido para cima"<<endl;
        }

        //Comandos do Keyboard para movimentar o Robô 1 do time azul

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            x1M += 0.5;
            posicoes[id1M].first = x1M;
            robo1M.setPosition(x1M, y1M);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            cout<<"O robô 1 do time azul foi movido para a direita"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            x1M -= 0.5;
            posicoes[id1M].first = x1M;
            robo1M.setPosition(x1M, y1M);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            cout<<"O robô 1 do time azul foi movido para a esquerda"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            y1M += 0.5;
            posicoes[id1M].second = y1M;
            robo1M.setPosition(x1M, y1M);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time azul foi movido para baixo"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            y1M -= 0.5;
            posicoes[id1M].second = y1M;
            robo1M.setPosition(x1M, y1M);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 1 do time azul foi movido para cima"<<endl;
        }
        
        //Comandos do Keyboard para movimentar o Robô 2 do time amarelo

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            x2T += 0.5;
            posicoes[id2T].first = x2T;
            robo2T.setPosition(x2T, y2T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 2 do time amarelo foi movido para a direita"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
            x2T -= 0.5;
            posicoes[id2T].first = x2T;
            robo2T.setPosition(x2T, y2T);

            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 2 do time amarelo foi movido para a esquerda"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
            y2T += 0.5;
            posicoes[id2T].second = y2T;
            robo2T.setPosition(x2T, y2T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 2 do time amarelo foi movido para baixo"<<endl;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            y2T -= 0.5;
            posicoes[id2T].first = y2T;
            robo2T.setPosition(x2T, y2T);
            
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            //cout<<retas[0].first.first<<"|"<<retas[0].first.second<<" || "<<posicoes[id1T].first<<"|"<<posicoes[id1T].second+14<<endl;
            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
            check = false;
            cout<<"O robô 2 do time amarelo foi movido para cima"<<endl;
        }

        if(check){
            sf::Vertex retaRoboRoboCen[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first, posicoes[id1M].second+14))
            };
            sf::Vertex retaRoboRoboTop[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second))
            };
            sf::Vertex retaRoboRoboDown[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first+28, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id1M].first+14, posicoes[id1M].second+28))
            };
            retas[id1M-1].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M-1].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second);
            retas[id1M].first = make_pair(posicoes[id1T].first+28, posicoes[id1T].second+14);
            retas[id1M].second = make_pair(posicoes[id1M].first+14, posicoes[id1M].second+28);

            sf::Vertex retaRoboRoboCen1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+28, posicoes[id2T].second+14))
            };
            sf::Vertex retaRoboRoboTop1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second))
            };
            sf::Vertex retaRoboRoboDown1[] = {
                sf::Vertex(sf::Vector2f(posicoes[id1T].first, posicoes[id1T].second+14)),
                sf::Vertex(sf::Vector2f(posicoes[id2T].first+14, posicoes[id2T].second+28))
            };
            retas[id2T].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second);
            retas[id2T+1].first = make_pair(posicoes[id1T].first, posicoes[id1T].second+14);
            retas[id2T+1].second = make_pair(posicoes[id2T].first+14, posicoes[id2T].second+28);

            criarAngulo(retas, id1M, id2T);
            classificarAngulo();
            
            for(int i = 0; i < qtRobos-1; i++){
                cout<<classificacao[i].second<<classificacao[i].first<<", está presente no ângulo de "<<angulos[i].first<<"º"<<endl;
                if(angClas[i] == 2){
                    cout<<"ÂNGULO APENAS PASSE"<<endl;
                }else if(angClas[i] == 0){
                    cout<<"ÂNGULO TOTALMENTE PROIBIDO"<<endl;
                }else if(angClas[i] == 1){

                }
            }

            janela.draw(retaRoboRoboCen, 2, sf::Lines);
            janela.draw(retaRoboRoboTop, 2, sf::Lines);
            janela.draw(retaRoboRoboDown, 2, sf::Lines);
            janela.draw(retaRoboRoboCen1, 2, sf::Lines);
            janela.draw(retaRoboRoboTop1, 2, sf::Lines);
            janela.draw(retaRoboRoboDown1, 2, sf::Lines);
        }

        check = true;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        janela.display();
    }

    return 0;
}