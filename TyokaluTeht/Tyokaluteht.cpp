#include <iostream>
#include <string>
/**
 * @brief Tehdä auto luokka jossa on auton rekisteritunnus, huippunopeus, nopeus nyt ja matka kuljettu.
 * 
 */
class Auto
{
    public:
        std::string rekisteritunnus;
        int huippunopeus;
        int nopeysnyt = 0;
        int kuljettu = 0;
        /**
         * @brief Muuttaa auton nopeutta hetkellä
         * 
         * @param maara 
         */
        void kiihdyta(int maara)  
        {
            nopeysnyt = nopeysnyt + maara;
            if(nopeysnyt > huippunopeus) {
                nopeysnyt = huippunopeus;
            }
            if(nopeysnyt < 0) {
                nopeysnyt = 0;
            }
        }
        Auto() {
            huippunopeus = 142;
            rekisteritunnus = "ABC-142";
        }
        

};
int main() {
    Auto vroom;
    std::cout<<vroom.huippunopeus << "\n";
    std::cout<<vroom.nopeysnyt << "\n";
    std::cout<<vroom.kuljettu << "\n";
    std::cout<<vroom.rekisteritunnus << "\n";

    vroom.kiihdyta(30);
    vroom.kiihdyta(70);
    vroom.kiihdyta(50);
    std::cout<<vroom.nopeysnyt << "\n";
    vroom.kiihdyta(-200);
    std::cout<<vroom.nopeysnyt << "\n";
    
}