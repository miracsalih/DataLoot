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

std::map<std::string, std::vector<std::string>> encode(std::vector<Lexer> code) {
    std::map<std::string, std::vector<std::string>> out;
    std::vector<std::string> path;
    std::string name[2];
    bool mode = false;
    for (const auto& [op, data] : code) {
        if (data == ":") {
            mode = true;
        } else if (data == ";") {
            mode = false;
            std::string a;
            for (const std::string& i : path) a += i + "/";
            out[a].push_back(name[0] + ":" + name[1]);
            name[0] = "";
            name[1] = "";
        } else if (data == "{") {
            mode = false;
            path.push_back(name[0]);
            name[0] = "";
        } else if (data == "}") {
            if (!name[0].empty() || !name[1].empty()) {
                mode = false;
                std::string a;
                for (const std::string& i : path) a += i + "/";
                out[a].push_back(name[0] + ":" + name[1]);
                name[0] = "";
                name[1] = "";
            }
            path.pop_back();
        } else {
            if (mode) name[1] += data;
            else name[0] += data;
        }
    }
    return out;
}
