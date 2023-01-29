#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

struct Game{
  int player,
    enemy,
    win = 0,
    lost = 0,
    draw = 0;
};

Game game;

vector<string> menus{"Mulai", "Lihat riwayat", "Keluar"};
vector<string> histories;

void ReadResultGame(int player, int enemy, string result) {
  cout << "Player : " << player << "\n";
  cout << "Enemy : " << enemy << "\n";
  cout << "Hasil : " << result << "\n\n";
  histories.push_back(result);
}

int main() {
  int menu;
  char repeat;

  menu:
    cout << "================ Lempar Dadu ================\n\n";

    for (int i = 0; i < menus.size(); i++) {
      cout << i + 1 << ". " << menus[i] << "\n";
    }

    cout << "\nPilih menu (1 - " << menus.size() << ") : ";
    cin >> menu;

    system("cls");

    switch (menu) {
      case 1:
        game:
          cout << "======== Hasil Permainan ========\n\n";
          game.player = rand() % 6 + 1;
          game.enemy = rand() % 6 + 1;

          if (game.player > game.enemy) ReadResultGame(game.player, game.enemy, "Menang");
          else if (game.player < game.enemy) ReadResultGame(game.player, game.enemy, "Kalah");
          else ReadResultGame(game.player, game.enemy, "Imbang");

          cout << "Ulangi permainan? (y/t) : ";
          cin >> repeat;

          system("cls");

          if (repeat == 'y') goto game;
          else goto menu;
        break;
      case 2:
        for (int i = 0; i < histories.size(); i++) {
          if (histories[i] == "Menang") {
            game.win = 1 + game.win;
          } else if (histories[i] == "Kalah") {
            game.lost = 1 + game.lost;
          } else {
            game.draw = 1 + game.draw;
          }
        }

        if (histories.size() > 0){
          cout << "======== Riwayat Permainan ========\n\n";
          cout << "Menang : " << game.win << "\n";
          cout << "Kalah : " << game.lost << "\n";
          cout << "Imbang : " << game.draw << "\n";
        } else {
          goto menu;
        }

        cout << "\nMulai permainan? (y/t) : ";
        cin >> repeat;

        system("cls");

        if (repeat == 'y') {
          goto game;
        } else {
          goto menu;
        }

        break;
      case 3:
        abort();
        break;
      default:
        goto menu;
        break;
    }
}
