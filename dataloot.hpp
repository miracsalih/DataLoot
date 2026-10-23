/*
 * DataLoot/dataloot.hpp
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

#pragma once
#include <map>
#include <vector>
#include <string>

std::map<std::string, std::vector<std::string>> encode(std::string& code);
