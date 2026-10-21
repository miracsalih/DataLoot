/*
 * DataLoot/dataloot.cpp
 * Copyright (C) 2026  Miraç Salih İşler
 *
 * Bu program özgür yazılımdır: GNU Genel Kamu Lisansı'nın (GNU General
 * Public License) Free Software Foundation tarafından yayımlanan koşulları
 * altında (Lisansın 3. sürümü veya (isteğinize göre) daha sonraki bir
 * sürümü) yeniden dağıtabilir ve/veya değiştirebilirsiniz.
 *
 * Bu program, işe yarayacağı umuduyla dağıtılmaktadır, ancak HİÇBİR GARANTİ
 * VERİLMEZ; hatta TİCARİ ELVERİŞLİLİK veya BELİRLİ BİR AMACA UYGUNLUK
 * garantisi bile verilmez. Daha fazla ayrıntı için GNU Genel Kamu
 * Lisansı'na bakın.
 *
 * Bu programla birlikte GNU Genel Kamu Lisansı'nın bir kopyasını almış
 * olmalısınız. Eğer almamışsanız, <https://www.gnu.org/licenses/> adresine
 * bakın.
 */

/*
 * DataLoot adındaki bir veri taşıyan format.
 *
 * "Lütfen iyi kullanın. =D"
 * — Miraç
 */

#include "dataloot.hpp"
#include "lexer.hpp"
#include <map>
#include <vector>
#include <string>

// Şuan çalışıyor gibi görünüyor ama çalışmıyor. Denemeyin. :/
std::vector<std::string> encode(std::map<int, std::vector<Lexer>> code) {
    std::vector<std::string> out;
    std::string ch;
    bool empty;
    for (const auto& [op, lexer] : code) {
        for (const auto& [type, data] : lexer) {
            if (data == "{") {
                if (ch.empty()) return {"err"};
                else {
                    out.push_back(ch);
                    ch = "";
                }
            }
        }
    }

    /* Mesela:

    new{
        type=int
        name=x
    }

    =

    block new;
    new type;
    set type int;
    new name;
    set name x;
    unblock new;

    TODO: Hata kontrolünü sona ekle. Ama çıktı '='dan sonraki gibi olsun. :3
    */
    return out;
}
